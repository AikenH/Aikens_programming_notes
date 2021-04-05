# 要点解析与补充

@Aiken 2021 

IN THIS DOCUMENT，主要介绍一些常用数据类型的一些method，区别还有一些特殊的定义；

priority_queue 默认是大顶堆，great的话是小顶堆，less的话是大顶堆，自定义的话不知道是不是一致的

set默认top是小顶，这个大小我就不知道了，自定义的话，好像和我想得是一致的

**所有的动态容器都是存放在heap上的，像是什么Vector，String，unordered_map之类的**

## 指定精度的输出和计算

在腾讯的笔试中出现的需要指定精度和指定的计算精度的分析，在使用常数的时候一定要使用.0去修正一个方法。

## Vector 动态数组

Vector中的一些常用的函数，方法，以及一些属性介绍和辨析

### emplace_back & push_back（在末尾添加元素）

`empalce_back `直接在数组的末尾进行构造，而`push_back`借助于构造的临时变量再将其加入数组末尾，所以在一些操作中`empalce_back`对于空间时间的效率是会更高的，但是如果我们有重复构筑的数据的话，可能就需要使用`push_back`。

要注意实际上vector中并**没有**append的方法。

### 初始化方法
主要有几种常用的构造函数，在这里主要介绍的是关于多维度的初始化构造方式。

```cpp
vector<int> v = {7, 5, 16, 8}; // 最基本的定义
// 通过大括号来设定多级的vector的初始值
vector<vector<char>> value = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'}}; 
```

常用的长度和常量

```cpp
vector<vector<int>> vec(size1,vector<int>(size2,defaultvalue));
```

## Unordered_map&set哈希结构

### CPP中hash table的实现数据类型：

实际上就是无序表，针对不同情况下的基本的定义方式，理念相同，针对不同的应用场景

- ``` unordered_map<typedef,typedef> Hashtable``` : 实际上是Key-Value的架构  

- ```unordered_set<typedef> Hashset``` ：只包含key的类型

插入的话，可以使用数组的形式，也可以用insert 或者emplace把。

### 取值方式

除了通过Key取Value这种老生常谈的方式，我们这里探讨的是iterator的情况下如何取到当前的值：

1. **set**: `*it`即可；
2. **map：**`*it`取的应该是value，**key**的话通过 `it->first`来取值，**value**通过`it->second`

### 按照迭代器来初始化

```cpp
unordered_set<string> deaded(deadends.begin(),deadends.end());
```



### 是否存在键值

使用`.count`不要再用find和end了，那个估计时间成本特别高了。。。。怎么更慢了。

使用map[key] 可以访问键对应的值，但是如果Key不存在，cpp会自动创建这个key同时赋值为0；

### erase

可以直接根据键值进行erase()

## List 双向链表like

通常用[list](https://zh.cppreference.com/w/cpp/container/list)来实现类似双向链表的类型，基本的使用上好像和其他的容器没什么区别，没有index索引，可能需要用iteration来进行遍历操作，

- 和双向队列相同，可以在两端添加和删除，pop push emplace也就是有\_back和\_front的后缀。
- 自带reverse，可以将元素的顺序反转；
- unique可以删除连续的重复元素；
- sort自带排序算法；

## Pair 二元元组对

### 二元tuple类型

实际上应该就是python中的二元tuple，也就是包含两个元素的数据结构，都是公开，可以是同样类别或者不同类别的，再STL中。

### USAGE：

初始化：基本的初始化方式如下

```cpp
pair<type1, type2> Data1;
// 基本的调用方式如下
Data1.first = {};
Data2.second = {};
```

用作新的类型定义的方式

```cpp
typedef pair<type1, type2> newtypeName;
newtypeName Data2;
```

实际上再DP中也是比较常见的，因为有一些情况下需要额外的信息存储就会使用这个类型。

## String & char 字符串

### 一些常用的函数

strcpy：将stringA 的值复制到stringB

strcat：直接用+就行了

## queue队列

实际上就是队列数据结构的CPP实现，基本的特征和队列的要求是一致的，常在BFS中使用到。



### 常用的成员函数和操作

1. `front/back`：访问首/尾元素;
2. `push/emplace/pop`: 在末尾插入/构造数据；弹出队首数据；
3. `swap`：交换内容（还没尝试过使用的方式）;

### Deque双端队列

有下标顺序的容器，允许在首尾两端快速插入和删除，相比于原本的普通队列，元素访问上没什么区；主要的区别在于

1. pop、emplace、push都变成了两种形式：`pop_back\ pop_front` ...etc.

### Priority_queue优先队列

[参考资料](https://blog.csdn.net/weixin_36888577/article/details/79937886) “例如，用 std::greater<T> 将导致最小元素作为 [top()](https://zh.cppreference.com/w/cpp/container/priority_queue/top) 出现。”

#### Usage 基本使用方式

```cpp
priority_queue<type, container, compare>
存放的数据类型，底层的容器类型，比较方程
```

基本的使用 

```cpp
top
push、pop、emplace
swap
```

### Priority_queue与Multiset辨析：

实际上set和map这些数据结构是基于红黑树进行建立的，而优先队列是基于**最大堆最小堆**来建立的，虽然他们都有序，但是实际上他们的结构还是大不相同的。

堆本身是一个完全二叉树（除了最后一层以外都是满的，而且空的值都在右侧），同时满足夫节点大于所有子节点

Set本身是一个自平衡的BST（红黑树）：

> 红黑树是一种近似平衡的二叉查找树，它能够确保任何一个节点的左右子树的高度差不会超过二者中较低那个的一倍



## set/multiset 堆相关的数据类型

比起说是堆，实际上就是集合的意思，但是这两个数据类型，本质上是基于红黑树等数据结构的基础设计（实现）的，很容易能转化为最大值堆和最小值堆。

### 两者之间的基础区别：

两者都包含在`<set>`中，进入这两个数据结构的数据都是会直接被排序好的（迭代器输出的话是从小到大的顺序排列），支持插入，删除，查找。

1. set不允许重复元素的录入，会自动屏蔽重复元素；
2. multiset可以容忍元素的重复，也就是不会做统筹处理；

### Usage使用方式：

可以通过在初始化的时候自定义compare，来规定排序的方向（来构建**最大堆**和**最小堆**），这里就涉及到了一下的两部分内容：

#### less、greater的使用和介绍

两者包含在`<functional>`中

是系统定义好的基本bool比较器，前者就是当A<B的时候会return true；后者应该是反过来的；

在一些函数或者类型定义的时候会使用到这两者的参数，避免我们的重复定义。

:question:但是这里目前有一个问题就是他这里介绍的使用方式来建立最大值和最下值堆，和我个人理解的不太一样，我们需要去后面辨析一下到底是怎么样才是对的。

应该和我理解的是一眼的，less最终就会是升序排列的，greater就会是降序排列的集合，然后只要我们在下面的pop或者push中指定一样的compare function就行。不，和我理解的是相反的

#### push_heap & pop_heap堆元素的添加和删除

帮助通过最大值堆和最小值堆的数据的添加和删除；此外我们在这里可能需要额外的介绍一下`make_heap`，应该也是heap的系列套件，不知道是从什么数据类型开始来帮助建立堆，我们后续需要补充一下。

1. 通过`push_heap`能够实现堆元素的添加同时并不破坏数据结构，实际上应该也就是实现了shiftup之类的操作。
2. 而通过`pop_heap`的话，实际上实现的是将要弹出的元素换到了末尾，这样我们从0，n-2的元素就是重构好的最大/小堆。必要的时候我们需要手动调用`pop_back()`，来对要弹出的元素进行实质上的弹出。
3. `make_heap`将一个可迭代容器按照指定的compere建立成堆，默认是最大堆，输入的是begin，end，compa，

## AVL平衡二叉搜索树

实际上就是在插入元素的时候实现两个操作：

1. 单旋转：插入的大小关系符合但是失衡的情况
2. 双旋转：插入的大小关系不符合同时发生了失衡的情况

[平衡二叉树](https://www.cnblogs.com/vamei/archive/2013/03/21/2964092.html)

## B+、B树、红黑树

根节点最少有两个子女，每个中间节点都包含k-1个元素和k个孩子，每个叶子节点都包含k-1个元素，所有的叶子节点都位于同一层。

重点就在于节省io时间还有中间的节点数量等等

B树与B+树：https://blog.csdn.net/windflybird/article/details/79875972

红黑树：https://zhuanlan.zhihu.com/p/31805309

红黑树和AVL的区分：https://www.jianshu.com/p/37436ed14cc6 ；https://www.it610.com/article/1297797681401372672.htm

## SWAP FUNCTION

swap在实际操作的时候经常被用到，很多时候会被拿来代替删除等等的命令。

他适用的数据结构和数据类型以及传入的方式可以简单总结如下：

1. 初始定义就是交换两个变量之间的赋值，但是在各个数据类型中都存在swap的特化方程，所以**根据该特化执行**的情况下，等价于`varA.swap(varB)`，会交换其中的所有值；
2. 通过基本的定义也能实现vector中两个不同index下的值的交换；

## Switch操作要常用

代替if else

```cpp
class Solution {
public:
    int calculate(string s) {
        vector<int> stk;
        char preSign = '+';
        int num = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                num = num * 10 + int(s[i] - '0');
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
                switch (preSign) {
                case '+':
                    stk.push_back(num);
                    break;
                case '-':
                    stk.push_back(-num);
                    break;
                case '*':
                    stk.back() *= num;
                    break;
                default:
                    stk.back() /= num;
                }
                preSign = s[i];
                num = 0;
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};
```



## 位操作运算

[参考资料](https://blog.csdn.net/cyuyan112233/article/details/40758031) `^`异或；`~`取反；`|`或；`&` 与。

位运算符的优先级从高到低，依次为~、&、^、|。

### 基本的一些操作Tips

根据剑指offer后面的两道题，我们可以分析一下怎么做到按位来进行操作



## Exception 异常处理

介绍cpp中的断言等异常处理的语句：`assert` `try catch`

### Assert 断言

设置条件断点，当Expression == false 的时候终止程序运行， Just take one arguments （Expression）；

可以使用 `#define NOEDEBUG` 预处理符来终止程序中assert的作用。

```cpp
// #define NODEBUG 
// 注释掉的时候assert是有效的
assert(2+2==5);
```

### Try_Catch & Throw 异常捕捉和抛出

Throw就是Try中遇到异常执行的抛出语句，有默认的抛出类类型，我们也可以自定义抛出的值就是了，基本语法框架如下

```cpp
try { /* */ } catch (const std::exception& e) { /* */ } // 具名形参
try { /* */ } catch (const std::exception&) { /* */ }  // 不具名形参
try { /* */ } catch (...) { /* */ }  // 可被任何异常激活的catch
```

还有一个比较具体的例子可以表示如下

```cpp
try {
    f();
} catch (const std::overflow_error& e) {
    // 若 f() 抛出 std::overflow_error 则执行之（“相同类型”规则）
} catch (const std::runtime_error& e) {
    // 若 f() 抛出 std::underflow_error 则执行之（“基类”规则）
} catch (const std::exception& e) {
    // 若 f() 抛出 std::logic_error 则执行之（“基类”规则）
} catch (...) {
    // 若 f() 抛出 std::string 或 int 或任何其他无关类型则执行之
}
```

然后介绍一下我们自己调用`throw`的方式：我们可以抛出任意类型的值，然后通过catch捕获该类型即可，示范如下：

不知道可不可以直接抛出“...”这种，下次试试。

```cpp
try {
    std::cout << "Throwing an integer exception...\n";
    throw 42;
} catch (int i) {
    std::cout << " the integer exception was caught, with value: " << i << '\n';
}
```

## Printf 按照format输出

#inlcude<cstdio>

参考cpp reference进行基本的学习吧，实际上



## Accumulate，isdigit

通过迭代器叠加其中的所有数字

isdigit：返回的是是否是0~9的字符把

## Define定义函数

```cpp
#define nRand(n){rand() % n}
```



## 指针相关内容

### 函数指针

用typedef减少输入量的写法，实际应用在之前的cpp笔记中已经有了

### 智能指针

unique_prt<>:会自己销毁的指针，管理的是堆对象，但是指针本身是随着栈，来进行管理的

shared_ptr<>：对于同一个对象会维护一个指向该对象的count，通过这个count，在count清零的时候自动析构该类

weak_ptr<>: 防止shared_ptr产生两个shard交互引用的情况，这样就永远不会被释放，通过weak指针，他不进行计数，当weak指针被销毁的时候就直接将空间释放，也不会使得技术++