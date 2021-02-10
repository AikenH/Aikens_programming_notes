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

```cpp
try {
    std::cout << "Throwing an integer exception...\n";
    throw 42;
} catch (int i) {
    std::cout << " the integer exception was caught, with value: " << i << '\n';
}
```

