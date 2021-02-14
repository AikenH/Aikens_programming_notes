# 要点解析与补充

@Aiken 2021 

IN THIS DOCUMENT，主要介绍一些常用数据类型的一些method，区别还有一些特殊的定义；

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

## Unordered_map & Unordered_set

### CPP中hash table的实现数据类型：

实际上就是无序表，针对不同情况下的基本的定义方式，理念相同，针对不同的应用场景

- ``` unordered_map<typedef,typedef> Hashtable``` : 实际上是Key-Value的架构  

- ```unordered_set<typedef> Hashset``` ：只包含key的类型

插入的话，可以使用数组的形式，也可以用insert 或者emplace把。

### 取值方式

除了通过Key取Value这种老生常谈的方式，我们这里探讨的是iterator的情况下如何取到当前的值：

1. **set**: `*it`即可；
2. **map：**`*it`取的应该是value，**key**的话通过 `it->first`来取值，**value**通过`it->second`

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

## queue队列

实际上就是队列数据结构的CPP实现，基本的特征和队列的要求是一致的，常在BFS中使用到。

### 常用的成员函数和操作

1. `front/back`：访问首/尾元素;
2. `push/emplace/pop`: 在末尾插入/构造数据；弹出队首数据；
3. `swap`：交换内容（还没尝试过使用的方式）;

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

✅应该和我理解的是一眼的，less最终就会是升序排列的，greater就会是降序排列的集合，然后只要我们在下面的pop或者push中指定一样的compare function就行。

#### push_heap & pop_heap堆元素的添加和删除

帮助通过最大值堆和最小值堆的数据的添加和删除；此外我们在这里可能需要额外的介绍一下`make_heap`，应该也是heap的系列套件，不知道是从什么数据类型开始来帮助建立堆，我们后续需要补充一下。

1. 通过`push_heap`能够实现堆元素的添加同时并不破坏数据结构，实际上应该也就是实现了shiftup之类的操作。
2. 而通过`pop_heap`的话，实际上实现的是将要弹出的元素换到了末尾，这样我们从0，n-2的元素就是重构好的最大/小堆。必要的时候我们需要手动调用`pop_back()`，来对要弹出的元素进行实质上的弹出。
3. `make_heap`将一个可迭代容器按照指定的compere建立成堆，默认是最大堆，输入的是begin，end，compa，

## SWAP FUNCTION

swap在实际操作的时候经常被用到，很多时候会被拿来代替删除等等的命令。

他适用的数据结构和数据类型以及传入的方式可以简单总结如下：

1. 初始定义就是交换两个变量之间的赋值，但是在各个数据类型中都存在swap的特化方程，所以**根据该特化执行**的情况下，等价于`varA.swap(varB)`，会交换其中的所有值；
2. 通过基本的定义也能实现vector中两个不同index下的值的交换；

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





