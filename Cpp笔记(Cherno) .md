#  C++ NoteBook（Cherno）

@Aiken 2020 

this notebook is based on Cherno‘s Video Class in [YouTube](https://www.youtube.com/watch?v=wXBcwHwIt_I&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=62&ab_channel=TheCherno)；if there is sth get confused，I can **recheck** the video which talk about it, or **just google it**. 

- this is not totally for newbie, so some basic information we should search it by outselves.
- And this is a important [websize](https://zh.cppreference.com/w/%E9%A6%96%E9%A1%B5) to tell us basic info about C++.
- [Microsoft Websize for C++](https://docs.microsoft.com/zh-cn/cpp/cpp/?view=msvc-160)

**ToDo:**

- using c++ and Python to finish the leetcode. 
- review data structure when we code.
- **reorganize the notebook by onenote** and leetcode.
- 后续可能会添加Effetive C++中的相关内容
- C++ Switch[语句](https://www.runoob.com/cplusplus/cpp-switch.html)

**Attention：**

- 为了防止一些遗漏，或者搜索上的困难，虽然我们会尽量避免内容的overlap，但是如果和两者都特别相关的话，可能会在两个地方出现完全一致的内容。
- **后续补充**：如果是confused的内容（不确信的话）就加入:question:  或者 still in puzzle: 内容的格式添加把
- [Typora常用快捷键](https://support.typora.io/Shortcut-Keys/#change-shortcut-keys)

  

## Introduction About C++

C++是一种强类型的语言，也就是我们需要实现指定数据的类型，同时我们没法随意的改变类型或者混杂类型把。（其实也是可以的就是需要执行特定的代码，相对而言没有那么方便而已。）

有疑惑就去查cppreference，永远的神；

此外当我们对某个不知道什么时候用的时候就google xxx when why how



## Part 1 编译器基本工作原理

This Chapter 主要介绍Visual Studio中C++的**compiler，linker**的基本工作原理；以及在Visual Studio中一些相关工作环境的设置，比如**输入输出配置**，**debugging**环境之类的；此外建议使用VsCode的**键盘映射**，对于自己来说比较熟悉）；同时也会介绍一些和编译器原理相关的**预处理模块**；以及**Library**

### 基本信息

STD：standard library C++中的标准库，包含了一些最基础的标准操作，包括`cin; cout;` 

`<cmath>`

#: hash tag（预处理符号）+预处理语句（基本的就是include，define之类的） = 预处理器

### Build ：Compiler + linker的基本原理

**编译和连接的规则：**

**原则1：**.Cpp都会被编译，但是.h不会被编译，他是以#后接的指定模式(`include`被嵌入(copy)到指定的.Cpp中的指定位置再进行编译。（下面是一些预处理指令）

>1. `include`：直接**复制粘贴**到**指定的位置，**所以你也可以定义}之类的进入h。
>2. `define`：搜索并**替换**
>
>     可以用做简单的函数定义
>
>     也可以使用成定义pi的值之类的，指定一个名称
>
>3. `#if 0/1` …       `#endif `:中间的内容将根据if后的true or false 来决定是否存在。（是否编译） 

上述的三种操作都是**文本级别**的操作，也就是针对编码文本进行处理后再送入编译器进行编译的。

---

**原则2：**每个cpp都会被编译成.obj文件然后由Linker，将这些obj连接起来成为一个.exe

 - **THIS IS IMPORTANT：**如果我们想要将功能和主题main（entrypoint）分离开来，除了用header的方式，我们也可以写在另外的.cpp中，然后再主要文件中进行declaration（定义函数名和指定的传入参数即可），也就是**声明该函数是存在的**，而不用具体定义（具体定义在另外的cpp中），这样在build的过程中，linker就会在我们的工程项目文件夹中搜索其他cpp中的指定function（we just declaration in the main cpp）。这样也能成功的编译。

 - 所以如果我们一个函数在多个cpp中定义（多重定义），或者由于header中的include h，这样可能会导致compile的时候出现代码（链接？）**混淆**的问题（bug），再不济也是个冗余的编译操作。
   - 如果需要多次使用.h     我们可以将其中的函数定义成**static**的方式，这样在每个cpp中都会有自己版本的.h中的函数，就不会有重复编写导致模棱两可的问题了。
   
   - inline前缀也能解决同样的问题：内联函数
   
     > **inline：内联标识符**适用于结构简单的小型函数。
     >
     > 增加了 inline 关键字的函数称为“内联函数”。内联函数和普通函数的区别在于：当编译器处理调用内联函数的语句时，不会将该语句编译成函数调用的指令，而是直接将整个函数体的代码插人调用语句处，就像整个函数体在调用处被重写了一遍一样。
   
 - 所以在这里我们推荐**在header中只实现Declaration**，而具体**的Definition就只在某一个cpp中**进行编写。

---

**机器码：**Visual Studio中可以将输出的obj之类的，包括代码中转化成汇编代码去看，就能知道我们的机器的实际运行逻辑，在VisualStudio中我们也可以设置针对汇编的自动优化来提升算法的运行速度。（一般是在release中会自动优化，而Debug中便于定位问题就没有优化）

**Debug标识符**： C：Compile Error；LINK：Linker Error

**Static标识符**：在变量的部分细讲，实际上对于编译过程也是一个很重要的关键词

### Build： 头文件（Header Files）

**一般在header 中写入declaration，然后把definition写在Cpp files里面。**

**#Include 命令** "" 或 <>

- "[content]" : content是文件的相对路径，可以使用类似..去索引
- <>:一般用来索引标准库之类的，用""来存储.h之类的文件
- 有.h后缀的导入一般是C，Cpp的就没有后缀

**#Pragma once**

这个hash tag的作用是让预处理仅仅只编译头文件一次，就是多次import也不会重复编译把，这个东西不要删除它。

原理上是取代了原本的ifnder；实际上也是一个宏

```c++
#ifndef Tag1_H
void functionA(int var1);
#endif
```



### Build：预编译头文件（precompailed Header）

**基本概念：**使用通用的header文件，将一些include放入header中，然后对这些header进行预编译，生成二进制文件。这样的话，

>- 我们就不需要每个cpp中的#include .h 都对其中的所有的include在进行copy paste然后进行编译，这样的话，加入了很多不必要的编译过程。
>- 也不用每次修改代码进行编译测试的时候，都有繁重的编译工作要去做了。

**使用情景：**

>- 在大型工程或者文件的时候使用头文件的预编译器是**非常重要**的。用它
>- 对于一些通用的常用的操作或者文件可以放进去，但是频繁更改的那些内容就不要放进去了，每次进行重新的预编译是浪费时间的。
  主要是一些include，declaration就别放在这了把？
>- 预编译的header可以对project中的所有cpp负责吗？还是需要include
>- 但是那些特定的依赖项，对于专门操作或者环境的，我们还是放到特定的cpp中，这样会使得代码更加易读，也不会增加负担。实际上就是两方面的考量，特定的和通用的两种处理方式。实际**上取决于依赖程度**；

**Visual Studio中的使用方法**

1. 创建需要预编译的头文件`pch.h`;创建`pch.cpp` 包含`#include "pch.h"`
2. 右键pch.cpp属性：c/c++ ->预编译头->预编译头（`使用`）
3. 右键项目属性：
   1. c/c++ ->预编译头->预编译头（`使用`/create）
   2. c/c++ ->预编译头->预编译头文件（`pch.h`）
4. 试一下把，不对的话，再回来检查视频。（可以在vscode的设置里，project c++中设置编译时间输出）

### Build：代码存储的文件结构

补充说明：VS侧栏的文件夹实际上只是分组，不是真实文件夹，所以我们在哪创建h和cpp都一样

**Rule1:** 推荐**在header中只实现Declaration**，而具体**的Definition就只在某一个cpp中**进行编写。

**Relu2：**在大型或者规范的Project中建议修改Vscode 的文件保存设置，当然我们也可以根据自己的需求去修改。

> 输出目录：$(SolutionDir)bin\$(Platform)\$(Configuration)\
>
> 中间目录：$(SolutionDir)bin\intermediate\$(Platform)\$(Configuration)\

### Build: 宏（Macros）

`#define`的各种用法；实际上就是通过预处理器对某些操作进行宏处理，“我不喜欢过度使用宏，这样可能比较不方便阅读”这点上其实和template是一样的道理。

> #define: 实际上就是在代码中搜索指定的文本进行替换
>
> 是一种文本级别的操作

**推荐的使用方法：**

约定俗称的名称或者表达，或者一些简单的函数（但是实际上为了便于阅读，并不是太推荐，见仁见智把）

- `#define pi=3.14159265`:类似的一种约定俗称的value

- `#define LOG(x) std::cout<<x<<std::endl;`

  

### Debug：条件与动作断点

**基本操作：**

- 设置breakpoint
- 内存信息读取：从debug-windows中可以调出各种窗口，从变量名或者&para找到内存地址也可以

**条件与动作断点：**

当然我们可以在代码中嵌入循环来使用普通断点来实现这些，简单的就是在断点的地方使用右键。主要的优势在于，我们无需暂停我们正在运行的程序，就可以执行这样的Break.

**Conditional**：条件断点就不说了。

**Action**：就是不需要stop我们的运行，我们添加了以后，就能在执行我们断点的操作的时候，在terminal输出，我们设置的action（简单的来说就是用于监控运行过程中的参数变化）

### Lib： Using Libraries 外部依赖的使用

<u>Static Linking and Dynamic Linking静态与动态链接库</u>

**基本思想**：希望在C++中不需要进行Package Manage 也就是不需要自己再去一个个的下载依赖项，也就是希望能pull下来就能用。

以GLFW为例，我们下载的时候可以下载2进制文件也可以下载源代码；下载的时候是x86还是x64与编写的目标代码有关，和OS无关。

#### 动态静态连接的基本概念：

静态链接在编译的时候实现，而动态链接是在运行的时候才操作；

- **静态链接**，意味着这个库直接放到可执行文件中（比如说exe）

- - 静态链接在一些情况下会更快，而且我们可以进行各种优化，所以这个作者比较喜欢静态优化。
  - 静态链接可以实现更多的优化操作，实际上是你exe中的一部分

- **动态链接**，在运行的时候加载DLL（动态链接库）之类的。

- - 询问dll载入调用到的函数，静态lib就是一次性把所有的都载入了
  - 它实现在运行过程中，linking一个外部文件，而不是可执行文件的一部分。

- - 当然也可以在你启动电脑的时候就启动，也可以设置为require，就是没链接就会完全报错。

#### 静态和动态连接的具体实现：

**静态链接的具体实现：**Head File，Include file的形式

- 创建dependency文件夹然后->libraries子文件夹(归属关系)
- Copy `include` 和相关vs版本的`lib`文件夹进去
  - 如果我们使用静态链接就和lib有关，如果我们使用动态链接就和DLL有关。
- 在VS 设置中c++ general +额外包含文件夹+相对文件夹（${SolutionDir} ->include文件夹）的路径

  - 如果需要我们也能在这看到其他的指代路径的意思
- 然后include<GLFW/…h>     (其实使用双引号也没问题)

  - 这个头文件实际上支持动态链接和静态链接（include中的）
  - 这里提供了declaration，但是没有实际的definition，所以我们还需要
- VS设置Linker/general/ Addition Libraries设置相对路径(Lib-vsxxx)和刚刚类似
- VS设置Linker/Input/Additional Dependencies设置具体lib文件的地址
- Over

**第二种静态链接的方法(不推荐)**

在前面的库设置好了以后，我们也可以不include，但是我们要声明（declaration）这个函数存在，注意类型不能错（这就好麻烦）

需要注意的是，我们链接的有的函数实际上是c而不是c++，这种时候就要添加前缀：

Extern "C"

**动态链接的具体实现**：基于静态的实现来分析

dll和dll.liB需要同时使用，lib提供了一堆指向dll文件中函数的指针，两者直接相关。

- 也就是相对于静态链接改变dependency中lib文件为dll.lib
- 然后要把dll放在我们需要运行的exe的同一个文件夹下。

### Lib：Multiple Project 编写自己的Lib或Dll

在解决方案Title下可以添加项目，一个解决方案下多个project

1. 将主project的属性中配置类型设置为exe

2. 将依赖文件设置为lib 或者dll，所有的配置和平台

3. 同样的在h中下写declaration在cpp中definition，然后在include的时候，由于路径不在一个文件夹下，所以我们可以用相对路径的方式设置，但是这样就比较傻，正确的做法：👇

4. 1. 属性，c++通用，额外的包含目录，把该目录放进去就行了

5. 但是这样其实我们没link，所以我们可以通过再主项目中右键添加引用，把我们要的引用添加进去，就可以了。（当然我们也可以生成lib再用）

6. 1. 但是这种情况好像只适用于同一个项目文件夹的时候。
   2. 这种自动处理同时会自动执行engineer的build

*在这里使用了namespace的写法，也许就是和类中的函数是特别像的把，也就是std那样的双冒号*

### Lib：Timing 计时器

C++中的计时器功能：主要用于统计程序运行时间和控制进程等等的操作。

具体还有timer的cast还有一些单位转化的工作，去cpp中查找或者看benchmark那课的视频

主要使用的库：`#include<chrono>`

```c++
// 还有一个暂时不知道起什么作用的namespace
using namespace std::literals::chrono_literals;
// 获取当前的时间
auto start = std::chrono::high_resolution_clock::now();
// 获取时间间隔的方式，这里的type比较特别
std::chrono::duration<float> duration = end - start;
```

上面这个方式,如果每次都要调用的话，就写得比较麻烦，如果我们希望能够比较简单的得到比如某个function运行的时间，我们可以利用lifetime签署一个类别，在function开始的时候定义一个就可以了。

看下面的实例：

```c++
struct Timer
{
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;
    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end -start;
        // std::endl 实际上比较慢
        std::cout<<"timer took"<< duration <<"s\n"
    }
}
```

### Lib：Sort排序iterator

`std::sort` need to `include<algorithm>` ；这是c++标准库中一个对Iterator进行排序的库。

复杂度 O(N·log(N))，其中N=`std::distance(first,last)`

参考网站：https://zh.cppreference.com/w/cpp/algorithm/sort 

```c++
//简单实例
#include<vector>
#include<algorithm>
#include<functional> //其中有一些分类的标准可以调用
int main(){
    std::verctor<int> values = {1,3,4,5,2,6}
    std::sort(values.bagin(),values.end()); //空载或者<,>是基本的用法
    //如果我们试图自定义函数的话
    std::sort(values.bagin(),values.end(),[](int a, int b){
        if (a==1)
            return False; //1放到其他所有的后面
        if (b==1)
            return true; // 同上
        return a<b //升序
            
    })
}
```



## Part 2 “变量”的使用和定义

In this section we‘ll introduce **variables（data structure） in C++**，主要是变量的声明和使用方式和用途，生存周期，存储空间，各种Keyword，类型转换。

### 变量（Variables） 

**As we know all datatype in machine is different number**

实际上就是给机器指定存储的空间和解析的类型。

- Char 实际上只是内联了“**数字到字符的转换**”，所以我们可以用各种类型来输入字符或数字（主要是内存空间占用），但是最后表达的类型会根据我们预定义的类型相关，有内联的数字和字符的转换存在。

#### 基本的数据类型

实际上就是预先定义了内存的分配了表达的类型，大小实际上取决于编译器。

可以用`sizeof()`查看各种**类型**占用的内存空间大小

**Keyword：**

> **整型：**
>
> ​	char（1 byte）；shot；int（4 byte）；Long；Long long（8 btyte）
>
> ​	unsigned
>
> **非整型：**
>
> ​	Float（4 byte）；double（8 byte）
>
> ​	实际上是精度类型，比如再数据后面+f指定精度类型
>
> **BOOL：**
>
> ​	bool （true， false == 0）；!0 即True
>
> **Void：**
>
> ​	类型未指定

**特殊类型**

- 指针类型（Pointers）：再类型后面+ `*`: `int* variables`
- 引用类型和取值符号（reference）：
  - 引用： 在类型后面+`&`:`int& refer`
  - 取址：`int* a = &variable;`

#### 变量的作用域（{}）和生命周期

**作用域**：在哪个范围内能访问到该变量

**生命周期**：

- 在内存中存在的范围（stack变量一般是活不过`}`）
- 需要跨越作用域的生存的话通常需要指定存储heap

#### sizeof 特殊类型的存储空间

Sizeof(Empty Class) = 1 ; 加入构造和析构函数 =1；将析构函数标记为virtual， = 4（32位的机器） =8（64位的机器） （会生成虚函数表，并为该类型的所有实例中添加一个指向虚函数表的指针。） 

也就是说指针在32位上是4字节 在64位上是8字节。

#### object“对象”的生命周期

（**不使用New关键词的时候**）生命周期只到栈或者说是**大括号**内（可以使用空的大括号组），是存在的

（**使用new关键词的时候**）如果我们不delete它，就只能在程序终止的时候才退出了。

:x: 下面这是一种<u>十分错误</u>的写法

```c++
int* CreateArray()
{
    int array[50];
    return array;
}
int main()
{
    int array[50];
    CreateArray(array);
}
//完全错误，在函数结束的时候这个指针会被完全销毁，所以指向的地址是没有值的，
```

如果我们希望延长声明周期，我们可以将数据分配到heap上，或者通过传入指针，对指针调用的地址的值进行修改。

**编写一个会自己销毁的在heap上的指针**（实际上和智能指针又异曲同工之妙）

```c++
class ScopedPtr
{
// 该ScopedPtr的申明是存在stack上的，所以销毁的时候调用delete就直接。
private:
    Entity* m_ptr;
public:
    ScopedPtr(Entity* ptr)
        :m_ptr(ptr){}
    ~ScopedPtr（）
    {
        delete m_ptr;
    }
}
int main()
{
    {
        ScopedPtr e = new Entity(); //申明周期也只到内部的大括号，出不去。会顺便把实例也销毁了。这个还稍微有点疑问。:question
    }
}
```

#### const 常量修饰符

[C++ const 关键字小结 | 菜鸟教程 (runoob.com)](https://www.runoob.com/w3cnote/cpp-const-keyword.html)

**语义含义**：**不可变，不可修改**；

- 可以令值不可变，也可以令指针不可变；定义一些常量之类的东西
- 可以在函数传入值中定义，使得传入值不可被修改，或者防止传入的指针或者是引用被不正确的修改导致一些奇怪的问题。
- 要注意根据位置的不同是指针不可修改还是值不可修改的含义是不一样的。

**本质含义**：实际上是一种代码的可见性机制，只是个promise，用来简化我们的代码。所以我们应该遵守它：就是我们不去修改这个const。（避免使用强制类型转换去修改它）

几种基本的定义方式：

1. 这种形式指的是我们**没法修改地址的值**，但是我们可以改变指针所指向的地址。

   ```c++
   //这两种都是一样的，在指针*的前面
   const int* a = new int ;
   int const* a = new int ;
   ```

2. 这种形式指的是**无法修改**指针引用的那个**地址**，但是可以随意的修改值。

   ```c++
   int* const a = new int 
   ```

3. 复用就是都不能改

4. 在类中的public函数declaration的括号后面加 const，指的是我们<u>没法在类内函数中修改类内的private的值</u>。这样的操作会被定义为illegal。

5. 类内指针的话就有意思了，要有三个const全用 
   :question:这一点后面慢慢补充，没搞清楚来着，记得太模糊了。

6. `const Entity& e` 指的是我们**没法修改指向的地址**。

**实例说明：**

对于传入函数的Instance（Entity）也是一样的，如果我们不希望进行内存上的copy，我们就加上&，如果我们不希望改变值就加入const。

用一些例子来说明一些其他情况的Const用法。 需要注意！

```c++
class Entity
{
private:
    int m_x, m_y;
public:
    int GetX() const //需要保证函数不能修改类内的private的值
    {
        return m_x;
    }
}
// 但是还是有一些问题
在这种情况下的const最前面的就是指的指针的地址不能变，但是其中的值能变。那么在这个时候，涉及到实体的那些函数，如果我们再类中没有加入const后缀的话，那么我们就不能使用这个get函数，因为编译器不能确保他不修改我们不能动的那些数据。
    
所以有时候会出现一个+const的定义和一个不加const的定义。
    
如果我们对一些private需要指定在一些const后缀的情况下可以改变，那么我们可以再声明的时候加入mutable前缀：允许的可变。
void PrintEntity(const Entity& e)
{
    std::cout<<e.GetX()<<std::endl;
}
```

#### Mutable可变标识符

**用途1：**基本上对于一些private类，在有const后缀的情况下我们又希望修改其中的某个值，才会用到这个关键词。

```c++
class A
{
private:
    std::string m_name;
    mutable int m_DebugCount = 0;
public:
    // 结合上面的范例可以看出这个返回类型为啥回事这个const+&
    const std::string& GetName() const
    {
        m_DebugCount++;
        return m_name;
    }
}
```

**用途2：**使用**lambda**的时候。我们希望能够修改传入值本身，（但是lambda是不允许修改的所以需要）

```c++
int x = 8;
auto f = [=]() mutable
{
    x++;
    std::cout<<x<<std::endl;
}
f();
```



#### Static静态标识符

**静态标识符类型：** class or struct 内部，外部，function 内

**类外的static：**

对于Linker起作用的修饰符，表示为**局部的**，也就是**只对它本身的obj**起作用，不会和别的文件连接起来，只对本身可见。

> - 如果在**function**的前面添加Static 就表示该Function 只被该.cpp调用，也不会考虑外部的Link，所以当我们如果希望被外部调用的时候就不能加static标识符，在要调用的地方进行**declaration.**
>
> - 实际上**全局的参数定义**，对于Linker来说也可以是跨文件的，所以如果我们定义全局参数的话，我们要考虑是否是通用的（需要重复include的常量），就可只在cpp定义一次。同时我们要在引用（另一个文件）的时候添加修饰符。（比如在头文件中用Extern Declaration参数）
>
>   **Extern**（也是用于声明：在外部已经定义过了，定义参数独有的）
>
>   https://www.cnblogs.com/lulululu/p/3693865.html

**类内的static：**

**这部分*memory**对于这个类别的所有实例**是共享**的，换句话说也就是，无论你定义了多少个instances，这个变量或者方法也是唯一的，对于所有的类别是通用的。你**改变了一个，也就改变了所有。**

>- 所以，类内的静态方法可以在没有类实例的情况下被调用，而且在这种静态方法中不能refer to 一个具体的类实例。
>- 也不能通过**实例对静态变量进行调用处理**，这样Linker会找不到我们实例对应的变量，因为那几个变量是类的变量而不是实例的变量。那么怎么去调用或者修改呢。
>- 使用作用域(type  ClassName:: x)的方式去声明,同样也**以这样的方式去调用**（ClassName（同样也能类比成namespace）:: x）才是真正正确的使用方法，类内的静态函数也是这样定义和操作的。但是**不用**像参数一样在类外声明

**Function内的Static：**

>- 其实和类内的Static是一样的，当我们第一次调用这个function的时候就会存储这样一个对于所有的function的静态变量，后续调用的时候这个参数就**不会被重新创建**了。
>- 也就是说这种**参数对于函数来说是恒定**的，在该参数上进行的**变化会被继承**下来，也就是会被迭代运作。
>- 某种程度上来说也算是延长了参数的生命周期，通常来说需要&的return值的一些情况下就需要用static关键词定义的vars。(:question:这一点是啥意思来着）

### 数组、多维变量（Array）

#### 经典数组

数组实际上是一组连续的变量，在内存上存储指定长度的空间，**本质是指针**

- **定义方式**：`type var[n]`,定义n个**连续**的type**内存空间**，这里的var实际上是相应的**指针**

  ```c++
  int example [5];
  int* ptr = example;
  ```

- 用var[idx]去索引指针相应地址的值：（实际上就是在初始地址上加上相应的偏移）

- 默认在stack上：没有new就是在stack上，需要heap就＋new把 记得delete[] 

  > 同时也可以用New关键字去声明数组，同时这个数组就会被存储到Heap中，这样的话该数组的声明周期就能活过大括号了，需要我们手动调用delete命令去删除它，由于定义的形式是数组所以在delete的时候记得使用的是delete[] var 命令
  >
  > ```c++
  > int* another = new int[5];
  > for (int i ; i <5; i++)
  > 	another[i] = 2;
  > ```

和传统的array好像有一定的同质性；找到数组长度的方法：

```c++
int count = sizeof(a) / sizeof(int);
// 用std::array的会自己保存数据的array
```

#### 静态数组（std::array）

**数组的长度或者大小没办法自动（动态）改变的**，我们应该用这种方式来代替传统的定义方式，有很多好处。

https://blog.csdn.net/thinkerleo1997/article/details/80415059

https://blog.csdn.net/fengbingchun/article/details/72809699

```c++
#include<array>
std::array<int,5> data;
```

**什么时候我们应该用这种array来取代传统的int array？**

- 现在这种方式有很多的集成函数：比如说size，sort，began好像还有iterator之类的方法。
- 因为传统的使用New，关键词是slow的，这种方法也会快一点，而且长度是不知道的。
- verctor是heap上的，而array和传统的int，array都是存在在stack上的，（非new关键词）
- 有很多优化，同时这种方法有自动的边界检测？
- 在函数传入array的时候，建议可以使用template的方法。

**BTW：**快不是标准库（STD）的基本目的和最求，所以很多时候需要资源最大化利用的情况下，很多project都会编写自己的数据类型：（可以从Cherno的最后两课去看看）

#### 动态数组（std::vector）

更详细的一些操作指南可以google或者看HR的`vector.svg`(附件)

就是个不指定大小的Array，可以改变数组的大小，其实就是自动执行内存的重新分配（内存动态分配），牺牲性能来得到更好的便捷性。

> 虽然C++命名Vector，但是实际上是个动态的ArrayList，而不是向量。

**vector移动数据**而不是Copy的方式在很大程度上提升了效率（没超过默认大小的情况下），但是在超过了指定大小的时候，还是需要用到copying（内存的动态分配）这就不是一个非常理想的情况。

>Vector：当append超过了现有的容量，找到一个足够大的内存位置，然后把原本的参数copy迁移过去，然后加上我们要添加的参数，然后删除原本占用的内存空间。
>
>这样就会造成运行缓慢，那么我们如何**避免这样的copy操作**，

https://blog.csdn.net/theonegis/article/details/50533770

**基本的声明方式**

```c++
#include<vector>
std::vector<type>name; //type 也可以是自己定义的class；实际上存储的就是数据的内存顶点（起始点）
// using vector = std::vector以后
vector <int> a;
vector<int> b(a); //声明容器b, 用容器a初始化b
vector<int> b(a.begin(),a.begin()+3); //用0-2个元素来初始化
vector <int> a(num); //
vector <int> a (num,value);
// 长度初始化
vector<vector<int>> memo(w1_idx+1,vector<int>(w2_idx+1));
```

**基本的一些method**

`Push_back({v1,v2,v3})` 就相当于append；`size（）`获取长度；`clear（）`将长度设置为0

索引还是[]；

`eraser（）`：需要在括号中设置一个迭代器，比如我们需要移除第二个参数

​           ↑：`vertices.begin() +1` 

使用示例：

```c++
std::vector<Vertex> vertices;
vertices.push_back({1,2,3});
vertices.push_back({4,5,6});

for (int i = 0; i<vertices.size();i++)
    Print(vertices[i]);
// 这里的迭代好像是存在问题的，我们要看一下
for (Vertex& v: vertices)
    Print(v);
```

**存储空间**

默认应该是在heap上的，但是会自动删除的。

**优化vector的使用**

**issue1：**我们会先调用最原始的构造函数，在main function的栈中构造一个vectex，然后copy it to Vertor类所在的空间中，如何**直接**在**指定的地方添加**（或者说只进行一次构造）呢？

解决方法：用`emplace_back `取代`push_back`,**直接传入构造对象需要的参数**即可

```c++
vetrices.emplace_back(1,2,3);
vetrices.push_back(vetrices(4,5,6));
```

**issue2:**空间超过以后进行了复制和迁移操作，也就是我们每一次添加都需要把原本的空间进行resize（copy and move）

解决方法：直接在开始的时候指定可能的最大size，就是给定一个[预留空间](https://www.cnblogs.com/zhuruibi/p/8983192.html)

```c++
std::vector<Vertex> Vertices;
Vertices.reserve(3);
```

### 字符串（String）

**String - stream of text 一组字符串 == array of characters**

**一些额外的信息**：字符串相关的一些其他事项

- 实际上`""`定义的就是固定（const）的type为char的指针，也就是 const char*；换句话说也就是占据固有长度的char array

- 实际上这是c中编写string的风格，为了熟悉基本的原理才这么编写的，现在就直接用string库了

- 原本定义的时候还需要在末尾指定ascii码终止符，但是在新的版本中不需要特地指定，也就是下述的两者是一样的。

  ```c++
  char name2[7] = { 'A','i','k','e','n',0};
  char name2[7] = { 'A','i','k','e','n' };
  ```

**基本信息**: 使用string的基本注意事项

- **基本的定义方式也就是和int之类的没区别**
- **string类别**就可以使用find size append +=之类的操作了，所以拥抱string；
  官方的[参考链接地址](http://www.cplusplus.com/reference/string/string/ )（看看其中的function的作用）： 
- `""`定义的类别实际上就是`const char[]`，本身就是一个不可修改的指针了，各种意义上的不可修改
- `''`定义的才是像普通的123这样的char value
- `string`实际上也是`std`中的一部分: 同时include它包含了重载<<，使得其得以接受stiring类型。
- +=不能再“”中执行，但是可以在string和“”中进行。
- 将string 传入函数的时候，也是不修改原值的，所以我们还是使用`&`的传入参数设置去使得不需要赋值一个新的，同时如果不希望修改的话，就在最前面加入`const`

**String Literals**

- 实际上我们在上面说的“”定义的就是String     Literals，字符常量，这种方式定义的后面会自带一个休止符的位置，再内存中也就是00；我们也可以手动定义休止符\0
- 实际上我们修改string都是再内存中获取一个Copy去进行的。所以我们需要善用&符号

**一些函数：**

Strlen（）:返回string长度，char array，要注意自己手写休止符的特殊情况

基本的“”实际上也是utf-8类型的。

```c++
const char* name = u8"Aiken"; //1 byte
const wchar* name2 = L"Aiken"; // (2/4) byte
const char16_t* name3 = u"Aiken"; // 2 byte
const char32_t* name4 = U"Aiken"; //4 byte
```

可以使用 

- `using namespace std::string_literals`使得我们对 **“” -> string**的类型转换可以从
  `std::string("")`变成只需要`""s`
- R"" 也很有用，:question:但是我忘了这个是用来干嘛的了

**迭代器**

```c++
string A;
A.begin() ！= A.end();
// 反向迭代器
A.rbegin()！= A.rend();
```



### 栈数据类型（STACK）

栈的std实现和基本用法：

```c++
#include<stack>
template<typename T>
stack<T> stack1;
```

 ### 无序图类型（unordered_map）

HASH存储类型的std实现，`unordered_map`

```c++
#include<unordered_map>

```



### 枚举类型（ENUMS）

枚举类型：也就是set of value

根据第一个var = x; 后面每一项的默认值在前一项的基础上+1，自动匹配对应的value

本质上就是一组指定的别名和其对应的value

```c++
class example
{
public:
    enum Level: unsigned char
    {
        L_error = 0,L_Warning,L_info
    };
    //取代了下面这种表达其实
    /*
    const int L_error = 0;
    const int L_warning = 1;
    const int L_info = 2;
    */
private:
    Level m_logLevel =L_info;
}
```



### 自动类别指定（Auto Keyword）

**可以结合模板来使用**

实际上就是根据我们键入的等式右边的内容，自动指定int float or any other type。

> 但是作者不是很推荐这种用途，很简单的情况，就很没必要，而且不利于阅读和维护`auto a = 4;`

比较推荐的用法：

1. **调用函数时的返回值前缀**：

- 在这种情况下我们修改function（API）的return type的时候就不需要重新在**修复赋值**的定义了，这种时候auto还是很有用的，或者**返回类型不明确**的时候。

  ```c++
  // 比如function的type 我们可能经常会动，或者有几个相似的函数的情况
  char* GetName()
  {
      return "aiken"
  }
  int main()
  {
      auto name = Getname();
  }
  ```

- 缺点：但是这种方式的话实际上也会让我们是否修改了代码的指示比较不明确，比如有时候会发生隐式转换。

2. **替代特别长的数据类型：**
   比如使用像vector这种的时候，参数名实在是太长了，就你懂的了，推荐使用（当然这种可以用using 来取代也是一样的。）

   ```c++
   // 使用 using的话就是。
   using DeviceMap = std::unordered_map<std::string, std::verctor<Device*>>;
   DeviceManager dm;
   // 话说下面这个应该是 值不可被修改的别名（因为&本来就无法修改地址，所以只有一种可能把）
   coust DeviceMap& devices = dm.GetDevices();
   ```

   

### 模板（Templates）

模板可以理解为一种指代，简单的例子就是通过这种模板的定义我们可以定义一个类别通用的函数；

模板实际上是在编译的时候就实现的一种机制，而不是到了具体的运行的时候才实现的。

**简单使用场景：**

1. 当我们需要多种类型的输入，来进行相似的function操作，比如说Print的时候，这种时候我们定义一种TypeName的模板；然后我们就可以使用如下方式调用定义的函数了。

```c++
template<typename T>
void Print(T value)
{
    std::cout<< value << std::endl;
}
print(5);
print<int>(5); //其他类型的也可以，只要函数内部支持就行。
```

2. 除了不确定的类别，我们也可以针对不确定的size去做（其实这里的int类型可以改成size_t）

```c++
template<typename T, int N>
class Array
{
private:
    T m_array[N];
public:
    int Getsize() const {return N;}
};
//main 
Array<int, 5> array;
```

但是不要过度使用，因为可读性会比较差；但是更关键的是，模板在编译和执行的时候是两回事，这样会让我们很难定位问题。所以不要乱用。但是在编写loging的system之类的地方，就比较合适。

### 操作符与操作符重载（Operators and operator overloading）

更多的表现是符号而不是函数，`new` ， `+` `-` ,之类的都是 括号

与或非： `||` `&&` `！` 

**一些优先级设定：**

++之类的运算符号的**优先级**> *取值，所以我们要**加入括号**，使其首先解引用，防止改变的是地址的值而不是value。

**重载的用途：**

比如我们实现向量类别的时候，我们就可以重载+，来实现这个加号，就是不用写一个Add函数（麻烦），主要是比较大规模的情况下为了使用方便来写的吧。

**Example：**

```c++
Vector2 Add(const Vector2& other) const
{
    return Vector2(x + other.x,);
}
Vector2 operator+(const Vector2& other) const
{
    return Add(other);
}
```

为了更方便的cout重载`<<`

```c++
std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
    stream<< other.x <<other.y;
    return stream;
}
```

对bool的判断进行重载：

```c++
bool operator==(const Vector2& other) const
{
    return x==other.x && y== other.y
}
bool operator!=(const Vector2& other) const
{
    return !(*this == other);
}
```

重载迭代器的索引

```c++
char& operator[](unsigned int index)
{
    return m_buffer[index];
}
```



### 命名空间（Namespace）

Using namespace apple (导入apple中所有的定义)

Using apple：：func1（只导入func1）

Namespace a = 定义

类似的查看cppreference网页即可

### 左值与右值（lvalue and rvalue）

其实就是赋值等式左边的变量和右边的常量的关系把？在这部分还会讲到相应的reference。

<u>rvalue就是 i=10中的10，这种值不能被更改，是一种临时的变量值，没有location和space，我们会将它分配到i，也就是左值。才是可分配和可改变的</u>。实际上就是这样的。

rvalue可以用来创建lvalue，**lvalue才有reference**，但是有特殊规则；

```c++
int& a =10 // error,这样写是错的，rvalue没有直接的引用
const int& a =10; //right
```

了解这点的意义在于（为啥我们要使用const）

```c++
std:string fName = "H";
std:string Lname = "Aiken";
std:string Fullname = "Aiken" + "H";
// 这个等式左边的全lvalue, 等式右边的（整体）都是rvalue，于是我们调用下面函数的时候，无法写输入值为"Aiken" + "H"，因为rvalue没有&
void PrintFuc(std:string& name){}
// 我们稍微修改一下，就能得到一个通用的Print,能够对临时变量rvalue进行传入。
void PrintFuc(const std:string& name){}
```

假如我们需要一个**只能传入rvalue**的函数，那么我们可以将表达修改为，这是一种特殊的方式

```c++
void PrintFuc(std:string&& name){}
```

这种方式有什么用呢？对于下面的**移动语义**很有用，因为**临时的变量**不需要考虑livetime或者memory之类的东西，同时我们可以简单的获取其中的值，<u>不用担心他和很多其他的地方产生关联。</u>

### 移动语义（move semantics）

> **Question：**为什么&引用符号不能解决这个问题，好像是对传入object的情况进行处理的一种方法：就像string，我们在某个地方需要她的时候，我们可能需要重新构造它。

> **Ans：**移动语义针对的对象实际上是Rvalue，也就是临时变量，临时变量的生命周期短，特别是像“”到string的情况，也是需要申请空间的，这样在我们将rvalue传入function或者class的时候，就会发生一次不必要的copy（因为rvalue没有&所以你懂的）

**Move Semantic： move objects around**

为了避免类似的不必要copy的操作，我们就使用**移动语义**的编程思想来做。👇

<u>move就是获取原本存储地址的指针，然后再将原本的指针赋值为nullptr（这样会使得其自动调用析构函数，也就不会有泄露等错误了）同时将size设置为0。</u>

*相比较于深拷贝实际上就是一种浅拷贝的操作。*

具体的实现思路其实就是针对rvalue重构copy constructor

```c++
//copy constructor 如下,以class string为例
//基础类别的部分
string(const String& other)
{
    printf("Copird!");
    m_size = other.size;
    m_data = new_char[m_size];
    memcpy(m_data, other.m_data,other.m_size);
}
//重构rvalue情况下的..
string(const String&& other) noexpect
{
    printf("Move!");
    m_size = other.size;
    m_data = other.m_data;
    // 清除原本的指针
    other.size = 0;
    other.m_data = nullptr;
}
// Entity部分，要添加一个针对rvalue的构造函数
Class Entity
{
public：
    Entity(const String& name)
    	:m_name(name) {}
    // 这里注意要手动把转换写出来，不然还是会进行copy的情况(执行上面那个),move 或者(string&&)
    Entity(const String&& name)
    	:m_name(std::move(name)) {}
private：
    string m_name;
}
// main 部分
Entity entity("aiken");
entity.print()// ....
```

`std::move()`左右值转换 

**参考资料：** [详细解析](https://drewcampbell92.medium.com/understanding-move-semantics-and-perfect-forwarding-part-2-6b8266b6cfa4)；[Anthor one](https://www.cnblogs.com/sunchaothu/p/11392116.html)

### 可选数据（Optional Data）（new in C++17）

**基本设置：**项目，设置，C++，语言，c++语言标准>17

针对那些我们**可能会使用也可能不使用的可选数据**。这也是一个c++ 17的内容：https://zh.cppreference.com/w/cpp/utility/optional

传统的就是通过引用传入一个bool flag，然后通过flag去判断是否存在之类的。但是有了optional我们就可以如下的方式去做

```c++
#include <fstream>
#include <optional>
std::optional<std::string> readfile(cosnt std::string& filepath)
{
    std::ifstream stream(filepath);
    if(stream){return string1}
    
    return {}; //这种写法其实是空tuple？还是要学一下的。
}
auto data = readfile(); //或者写那一长串optional string
//然后就可以使用
if(data) 或者 if(data.have_value())
```

还有另一种使用方式就是，用于设定不存在数据的默认值。

```c++
std::string value = data.value_or("sdsds"); //如果data是空的救会取到这个，相当于默认值把。
//比如
std::optional<int> count;
int c = count.value_or(100);
```

### 多类型变量（MultiType Variable）（new in C++ 17）

换句话说就是数据的类型是在指定的范围内可选的，依托于`#include<variant>`通过指定数据可能的Type，然后用特殊的方式取出来。

它实际上存储的是所有类型的长度相加的空间；虽然能实现和unions类似的功能，但是实际上是更安全的。就是存储空间的占用更大？两者相比推荐这个把。

`std::get_if`：对于这类型的数据很经常被拿来使用，我们可以参考[这里的](https://zh.cppreference.com/w/cpp/utility/variant/get_if)用法

```c++
std::variant<std::string,int> data;
data = "Aiken";
// 这种数值取出的方式只有在类型正确的时候才会起作用，不然会造成exception
std::cout<<std::get<std::string>(data)<<"\n";
data = 5;
std::cout<<std::get<int>(data)<<"\n";
----------------------------查看当前的数据类型-------------------------------
data.index(); //这个index对应我们前面的定义的顺序
//另一种更优美的数据获取方式
auto* value = std::get_if<std::string>(&data);
// and we could use it like that 
if(auto value = std::get_if<std::string>(&data)) {}
    
```

针对**Get_if**的具体实例可以写成这样：

```c++
#include <variant>
#include <iostream>
int main()
{
    std::variant<int, float> v{12};
 
    if(auto pval = std::get_if<int>(&v))
      std::cout << "variant value: " << *pval << '\n'; 
    else 
      std::cout << "failed to get value!" << '\n'; 
}
```

此外我们也可以通过这种类型来定义函数：这种的使用方式可以像这样看（对于可选的话，只是返回一个空值，这样可以更加具体的定义我们为什么访问不到文件），但是这种方式的话，不能用auto来代替吗

```c++
//因为我们要当成类型传入，所以需要class但是这里不用return值吗
enum class ErrorCode
{
    None = 0, NotFound = 1, NoAccess =2
};
std:: variant<std::string,ErrorCode> ReadFileAsString ()
{
    return {}; //这里应该也是需要修改的把，改成ErrorCode类型
}
```

### 任意类型数据的存储（store any type）（new in C++17）

我们也可以使用空指针来存储任意类型的数据；但是这不是这一块讨论的内容，这里讨论的是`std::any`

就是一个能存储任意类型的variable，实际上和variant很像，但是那个更安全，因为我们知道所有的可能类型；同时这样的方式也会避免any可能会带来的动态内存分配，这个我们知道是相当影响性能的。

```c
#include<any>
std::any data;
data = 2;
data = "aiken";
// variant 指定string的时候实际上会发生const char * 到string的隐式转换，但是any是不会的。
//any 取出变量的方式如下,在这种情况下数据类型不匹配的话，是不会成功取出的，我们还是需要知道我们当前的any type 以及按照指定的方式取出，所以实际上variant是一种更为安全的方式
std::string string = std::any_cast<std::string>(data); //但是这样的话我们还是会有一个copy的操作，我们是否能够直接返回一种引用👇（别名）
std::string& string = std::any_cast<std::string&>(data); 
```

**使用的情境：**

实际上是存储空间是有默认的小规模存储空间和大规模存储空间(限制);超过了小规模（32byte？）的情况下会使用动态的内存分配的机制。

当我们需要用any存储类似struct之类的大数据的时候，any可能就会调用new来动态的内存分配了。

能用variant就用，不行，导致非要用void*（空指针）的情况下就用any；但是最好的话，我们是不需要这种东西的。

**如何使用：**

### 多维矩阵（2D+Array）

**n维数组实际上就是n-1维数组的堆叠**：array的array

也就是其实是**指针**机制：指针指向的地址存放一组指针，然后这组指针再指向各个Array，这就是2d array了。关键就是 **指针的指针\*\***

多维矩阵第一次取出的时候实际上是指针类型，多重取出的最层才是数据。

```c++
int main()
{
    // 实际上就是用指针的指针的方式分配多维度的数组，更多维度也是一样的（星星更多了）。
    int* array = new int[50];
    // 分配50个存放int指针（int是返回的类型不是指针的类型）的空间
    int** a2d = new int*[50]; //绑定了50个内存位置
-------------------------------------------------------------------------------------
    //实际的定义多维数组的方式,更高维度的就要嵌入更深的循环。
    int** a2d = new int*[50];
    for(int i=0;i<50;i++)
        a2d[i] = new int[50];
}
```

问题来到了下一步**如何删除**多维度的数组？

如果我们只delete最外层的指针，那么内部的所有指针地址，将会发生内存泄漏。

所以：我们需要像定义那样，反向的**对每个指针都进行delete**

```c++
for(int i=0;i<50;i++)
        delete[] a2d[i];
delete[] a2d;
```

这些50*k的存储空间实际上不一定是连续的，但可能是接近的，实际上是，再内存中随机的分配50个buffer来存放50个array，这种方式会越来越慢，（因为缓存的命中问题？），连续的存放可以使得缓存有更高的命中率来提升速度。

再某些情况使用1d array来代替2d array比如下（**这不用看了，谁不会啊**，手动换算行号呗），但是这样的代码在**执行的时候，快很多**

```c++
int* array = new int[5*5];
//我还以为，是类似的写法也可以，这样的话，谁不会啊。
for (int y=0;y<5;y++)
{
    for (int x=0;x<5;x++)
    {
        array[x + y*5] =2;
    }
}
```

### 隐式转换和显式转换（Implicit Conversion and the Explicit Keyword）

隐式转换和显式关键词

**隐式：不用告诉他他究竟要做什么**

很多时候由于类的构造函数实现，基于类的输入类型，我们可以将函数表示的初始化，转化为等号的。同时也能在一些特定的场景下执行内置的类型转换。

但是如果是我的话，我尽量不会这么去做🔜，因为这样会增加阅读的负担。

**显式关键词：不让执行隐式转换**

`Explicit` 加在构造函数的最前方，这就是让构造函数只能被显式调用，不能执行隐式调用。

```c++
#include<iostream>
using String = std::string;

class Entity
{
private:
    String m_name;
    int m_age;
public:
    Entity(const String& name)
        :m_name(name){}
    Entity(int age)
        :m_age(age){}
};
void PrintEntity(const String& name)
{
    // print
}
int main()
{
    // 在这一步中C++将根据构造函数进行隐式转换，前提是对应的类别要是正确的
    Entity a = 22;
    Entity b = String("aiken");
    // 第二种自动进行隐式转换的场景，实际上和上面是完全一致的
    printEntity(String('asdad'));
    std::cin.get();
}
```

cast：类型转换从typeA-> type B

- int（22）之类的
- 所有的类名也能这么做（借助隐式调用这样的）

### 类型转换（Type Casting）

cast实际上会为我们检查类型是否正确等等

**显式转换：**显式的**指定**我们希望将当前类型**强制转换**成什么**目标类型**

```c++
double s = static_cast<int>(value)+ 5.3
```

**隐式转换：**不需要我们显式的指定转换的数据类型，根据输入输出会自动转换

```c++
// 反过来也是可以的
double value = 5.25;
int a = value; 
// 我们同样也可以显式的指定,但是这种转换不是强制的，只是显式的表达
double b = (int)value;//safe style csat的样式
double b = (int)value +5.2 //我们可以看看没有这个int的结果
```

实际上存在四种不同的Casting：`static_cast`，`const_cast`，`dynamic_cast`，`reinterpret_cast` ，这几种cast的使用请 [GoogleIt](https://zh.cppreference.com/mwiki/index.php?title=Special%3A%E6%90%9C%E7%B4%A2&search=cast&button=)来补充基本的含义，以及一些使用情况，（CPP reference是真的牛逼）

在一些情况下转换失败的话会return null，所以也可以用做派生类的检查。

**const**：用来从const到非const

**dynamic**：用于从基类到子类的指针转换，（反过来可以，但是实际上不需要显式转换）

> 其实是一种function，实际上会有一些额外的操作。
>
> 如果这个转换是错误的，那么这个指针会返回null，所以实际上，这个指针可以用作类型之间继承关系的验证作用。
>
> ```c++
> // 基本定义
> class Entity {};
> class Player : public Entity {};
> class Enemy : public Entity{};
> ```
>
> 实际上由于存储了运行的中间状态（runtime type infomation默认是启用的，关闭会报错），所以是可以知道该类到底是啥的，也就是支持从基类推导到该子类到底是啥。
>
> ```c++
> Player* player = new Player();
> Entity* e = player; //毫无问题
> Entity* e1 = new Enemy();
> 
> Player* p0 = dynamic_cast<Player>(e1); //这种转换不可行，会return null
> Player* p1 = dynamic_cast<Player>(e); //从基类转换到子类 ok，但是这种情况下我们需要指定多态，也就是virtual 为了避免冲突，这其实是一个多态的用法
> if(dynamic_cast<Player>(e1)){} //验证类型的用法
> ```

**reinterpret**:用于无关类型的转换，还是需要再搜索一下，不太常用，推荐的可以使用的情况，类型转换转换回原本类型的时候

这种类型转换实际上是更可靠的。

### 类型双关（Type Punning）

**实际上就是获取某种类型变量的指针，然后转化成另一种类型的指针的操作。**

[Google it](http://tisyang.is-programmer.com/posts/38184)

当然接下来我们也可以解引用,其他之类的。

首先看一串示例代码（double）实际上是为了让到double的隐式转换更加清晰，并没有真正的操作指令。

```c++
// 这样的操作实际上就是a-b的隐式转换，但是这样的话，内存空间实际上是没有公用的，b是用的另外赋值的双精度的5
int a = 5;
double b = (double)a; 
// 反过来也是一样的道理
```

如果我们想要直接使用指针转换，将double指针转换到int指向的内存地址，这样的话，由于**两种类型的长度不同**，所以会导致输出**错**，严重的话还会导致**崩溃**。

但是实际上，这样的操作，我们可以通过同样长度的内存操作，来直接的对内存进行操作，但是正常人没有人这么干。

```c++
struct Entity
{
    int x,y;
    int* GetPositions(){return &x;}
};
int main()
{
    Entity e = {5,8};
    int* position = (int*)&e; //将struct的指针转化为int指针
    std::cout<<postition[0]<<postirion[1]<<std::endl;
    
    int y = *(int*)((char*)&e+4); // 通过char的单字节操作获取到第二个指针的地址。
    int* z = e.Getpositions()
}
```



## Part 3 Poniter & References指针与引用

从指针的含义出发，对各种不同指针的用法，引用场景，内在含义，进行分析，记录世界记录你。永远的神，指针。

**指针**实际上就是一个1byte的**整型值**，**它就是一个地址**，指示你在内存中存储该值的位置，和类型没有半毛钱关系，类型只是指示你可能放了个啥类型的数据在那个地址`Void* ptr = &var;`

**引用**和指针本质上是一回事，用法上会有所区别它实际上是基于指针的一种高级修饰，是对某个已经存在的var的引用。他并不是一个真正的变量。`Int& ref = var。`

> 引用能做的指针都能做，实际上是一种代码的优化和简化过程（moew clean），主要的用处就在将var而不是value传入function（达到能够直接修改var的作用）

### 指针基础（pointer）

**->的访问方式**：实际上等同于(*e1).method，`Arrow->`只能在左边是指针的时候使用，而`.`调用的方式左边只能是实体。

```c++
Entity_virtual e1 = new Entity_virtual();
std::cout<<e1->GetName()<<std::endl;
Entity_virtual e2("Aiken2");
std::cout<<e2.GetName()<<std::endl;
```

**基本的定义和使用方式：**

- <u>用`*`定义一个指针类型（用来存放地址）= &var（用该符号取出后接变量存储所在的内存地址）var</u>
  - 然后我们可以在Debug Stage从windows的memory找到该变量在内存中的值。
  - **实际上也可以用**`type* name = Value`，这样的话name还是指的是value所在的地址。但是这种时候type就需要写好了。
- 在指针类型变量前加*表示我们**访问**该地址所存储的Var，我们可以对该var进行读取写入或者修改，但是在这个时候，我们写入的值就和之前所提到的类型有关了（指针本身是无关的）
  - 因为**类型会告诉内存，我们写入的数据要在内存中占用多少个字节**，多少位之类的信息，而如果我们使用void，那当我们给该指针取到的数据赋值的时候，compiler就不知道怎么存储该数据，也就会导致error。
- 也可以用`**`定义<u>指针的指针</u>，也就是指针所在的内存空间的地址
  - BTW:从内存窗口看到的地址是逆序的
- 可以将指针定义为nullptr，后续再赋值，而引用必须马上引用一个已经存在的变量，他不是一个新的变量。
- 在<u>同一行里定义多个指针变量</u>的时候要在**每一个前面+**`*`千万别忘了

**注意事项：**

1. ++之类的运算符号的**优先级**> *取值，所以我们要**加入括号**，使其首先解引用，防止改变的是地址的值而不是value。
2. “0”不是一个有效的内存地址
3. **指针偏移值**实际上取决于指针前面的type：如下图就是加入了两个int长度的地址。

```c++
int example[5];
int* ptr = example;
for (int i=0; i<5;i++)
    example[i] =2;
example[2] = 5;
*(ptr+2)=6;
//上述也等同于
*((char*)ptr + 8) = 6;
```

### 引用基础（references）

- 用`type& ref = var`定义一个对var的引用，不需要其他的操作符

- - 实际上ref就是一个别称，他**不是实际存在**的，只是var的另一种表达形式。
  - 需要立即赋值。

- 具体的用途除了**创建别名**方便读写以外：主要用于需要修改原值的参数引用定义上。

- - function中通常情况下，是传值，而不是传递变量的地址。所以会有额外的内存拷贝的操作发生；所以通过function中的value产生的变化实际上是不会影响传入的变量的，这时候我们需要使用引用将**变量传入**，**而不是值传入**。（if we need this operation，也就是我们需要影响原值的时候）那么实现的方法有下面的三种。

  - 1. 要这么做的话实际上就是，我们将内存地址传入，然后通过地址取值进行操作，而不是只将这个值copy一下传进去也就是`def fun(int* var)`; `func(&var)`;当然这种方式也适用于**直接传入指针**，

       ```c++
       def fun(int* var);
       func(&var);
       ```

    2. 对1进行修正，更优雅的写法，简洁，就是使用reference，接受传入的是别名，也就是具体的变量，而不是值。

       ```c++
       def func(type& value);
       func(var);
       ```

    3. 当然我们也可以通过return来改变原值，但是这样会需要temp value来影响内存效率之类的东西，也比较傻逼。

- 无法改变引用的对象。

- 再func前面类型定义为`Type&`,那么我们正常的`return`就是返回一个<u>原值的引用</u>。

### 指针的->操作符(Arrow Operator )

**→用来取代解引用后取值，就是用于指针直接调用参数或者函数，免去用`*`解引用的过程**。

- 但是所有的操作符都可以重载，我们可以在自己的类别中定义他：比如当我们用一个Class     装载别的Class的指针的时候（比如我们为了让他能自己delete），如果我们希望能够直接指向最底层的那个Class 的function的时候。

  ```c++
  // ScopedPtr存放另一个class（Entity）的指针，和构造析构函数。
  // 重载使得直接调用底层类别中的函数。
  Entity* operator->()
  {
      return m_obj;
  }
  
  ScopedPtr entity = new Entity();
  entity->Print();
  ```

  

- 获取类中参数的内存偏移量（可能是特殊的用法把，和第一点最基础的代码完全不一样）：

  ```c++
  struct Vector3
  {
      float x,y,z;
  }
  int main()
  {
      int offset = (int)&((Vector3*)nullptr)->x;
      std::count << offset << std::endl;
  }
  // x,y,z会分别Get到0，4，8（字节）
  ```

### 函数指针（Function Pointer）

主要目的就是：获取函数所在的内存空间的地址；

https://zh.cppreference.com/w/cpp/language/pointer

函数指针的补充资料：[link1](https://blog.csdn.net/zj1131190425/article/details/92065897)，[Link2](https://zhuanlan.zhihu.com/p/37306637)，还需要通过编程来加深理解

实际上应该还有其他类型的表达；

**定义和使用**

记住这里1不加括号（有参数输入的时候才加入括号），这就等同于在HW卡面+&

```c++
auto function = HelloWorld;
//记住这里不加括号（有参数输入的时候才加入括号），这就等同于在HW卡面+&
```

下面这种定义方式便于我们理解：

```c++
//等于下面这种方式
void(*cherno)() = HelloWorld;
cherno(); // 调用函数。
// 通过4-5的参数对比，我们可以知道cherno就是一个函数的别名。

// 这种方式其实更规范的可以写成 :这里添加了参数的输入所以比较不一样
typedef void(*HelloWorldFunction)(int);
HelloWorldFunction function = HelloWorld;
function(8)
```

**函数指针的使用场景：**

主要用于把function传入function，和lambda匿名函数好像有比较好的结合

```c++
void PrintValue(int value)
{
    //Print cout
}

void ForEach(const std::vector<int>& values, void(*func)(int))
{
    for (int value : values)
        func(value);
}

int main()
{
    std::vector<int> values = {1,2,3,4,5};
    ForEach(values, PrintValue);
}
```

### 智能指针（Smart Pointer）

**非常重要，能用智能指针的情况下我们就不用传统的指针**

作用域:{}  [参考资料1](https://blog.csdn.net/xuyouqiang1987/article/details/104127669)；[参考资料2](https://blog.csdn.net/shaosunrise/article/details/85158249)

**唯一指针**，能够自动的在作用域外就进行销毁（最基本的智能指针）

```c++
#include<memory>
// 下面这个是错误的，给个范例
std::unique_ptr<Entity> entity = new Entity();  // 这个是错误的！！！！！！！
//只能显式调用构造函数：正确↓
std::unique_ptr<Entity> entity(new Entity());
//另一种 写法：推荐写法：最好就这么写
std::unique_ptr<Entity> entity = std::make_unique<Entity>();
```

**共享指针**，<u>另一种智能指针</u>，

使用reference_count来进行引用指针的计数，对象的所有引用消除了以后（count=0），才进行销毁（delete）

主要功能：

管理动态创建的对象的销毁。它的基本原理就是记录对象被引用的次数，当引用次数为 0 的时候，也就是最后一个指向某对象的**共享指针析构**的时候，共享指针的析构函数就把**指向的内存区域**释放掉。就是一个对象可以有多个引用。

```c++
std::share_ptr<Entity> sharedEntity = std::make_shared<Entity>();
```

**弱指针**weak_ptr: 是一种弱化的共享指针，不会进行reference count

https://blog.csdn.net/albertsh/article/details/82286999

它不会等到全部的指针都被销毁了才销毁，它会在指针销毁的时候就对对象进行析构，所以可能会有部分指针指向没有分配值的地址。

---

**总结一下：**重要！！！

- 所以只是当我们需要在一个**heap**上声明的对象，但是希望能在作用域外自动销毁的时候我们才应该使用智能指针。
- 也就是智能指针分配的数据空间是在heap上的，但是存储指针自身的空间是在stack上的
- 先思考使用unique point 在需要不同的地方共享的时候在考虑share pointer 
  - 避免使用`new` `delete`
- 实际上智智能指针就是对原生指针的一个高层封装，就是类似struct ，在struct 的destructor 调用指针指向地址的delete？ 看看视频中的代码。

## Part 4 Class & Struct 面向对象

This Chapter 主要就是<u>面向对象的编程逻辑</u>，以及类和结构体中的一些知识点

**面向对象编程**：这是一种非常流行的编程思想，这是一种编码的风格。

jave所有的一切都应该是一个class.

### 类（Class）

**Class**：和python是一样的，是一种将**数据**和**function**（**method**）组织在一起的一种方式。

和namespace的区别是啥：namespace没有访问控制。

#### 一些基础用法和信息

1. 比如玩家的属性，和玩家的一些function，就可以使用class的instance来定义多个角色，而不必重复的定义类似的方法和属性值。

2. 类中的function就被称为method

3. 可以使用大括号的方式来初始化赋值

   ```c++
   struct Vector2
   {
       float x,y;
   };
   int main()
   {
       Vector2 a = {2,3};
   }
   ```

4. 实际上可以在类内declaration函数，然后再类外用::namespace的方式进行定义

5. 当我们想要将Class or Struct传入Function中的时候，我们最好是使用reference `&`和`Const`，这样可以防止传入的类之类的被修改，同时也节省了memory，不需要额外的生成一个copy。

6. 建立一个Logging类：将warning Or Error 打印在控制台上，因为控制台永远不会出问题，对于debug很有帮助。

7. 继承所有在Entity中不是private的都会被player继承。

#### 访问控制（Visibility）

- public：可以在类外访问，也就是可以在类的外部随便定义，取出，或者修改。
- private：只能通过类内的操作或者类内的函数，以及friends进行修改调用。
- protect：类内或者继承类

friend的定义方式：在类内的public使用前置`friend` 去重载这个函数或者类别即可。就能访问私有变量了。

#### 类的构造函数和析构函数

[C++ 类构造函数 & 析构函数 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-constructor-destructor.html)

**constructors****：构造函数（可重载）**

- 用于每个instance生成时候的初始化，我们可以通过不同的传入值来**重载**这个函数。

- 名称和类名一致，不需要type。

- 默认是存在constructor的（但是不初始化变量），如果我们不希望用户构建实例，我们可以将constructor写在private中，那么就无法使用该类别去生成一个实例。

- 函数构造的**初始化列表**：

  构造函数初始化列表以一个**冒号开始**，接着是以**逗号分隔**的数据成员列表，每个数据成员后面跟一个放在括号中的初始化式。

  但是这种方式，需要我们按照成员函数的**顺序去编写**，他是默认这样执行的。

  [类构造函数初始化列表](https://www.runoob.com/w3cnote/cpp-construct-function-initial-list.html)。

  - 这样假如我们成员中有类别实体，我们可以避免该类别实体进行重复的构造，浪费了性能。（可以用cout测试）
  - 此外这样也可以分离初始化参数和一些其他的初始化指令操作（写在大括号里）。

**Destructor****：析构函数**

用于destory我们生成的object或者说instance；清除变量。

- 在构造函数前面加~就是定义的方式。一般不需要显式编程
- 活到生命周期末尾（大括号之类的）会自动调用
- 如果New 就需要Delete才会调用

#### 类的继承

继承的主要作用，是让我们拒绝duplicated，拒绝代码重复。所以我们就能在父类中放置通用功能，然后在子类中重载或者编写新功能。

- 在子类的定义的时候`：[public] 父类，父类2`
- 如果函数的输入是（`父类* a`），那么所有的子类都可以输入来着 ：实际上是多态的因素，就是所有的子类都属于父类把，所以父类的指针可以代表所有的子类。

**抽象类abstract class**

1. 不能被实例化的类别，但是可以作为类继承的基类；
2. 所有的method都是virtual的情况下就称为抽象类（纯虚）；

**虚函数Virtual Function**

1. 在父类中编写的**virtual function**就能在子类中选择覆盖重载

2. **Virtual   function**可以避免在特殊情况下，我们在子类覆盖定义了父类函数的情况下，还是调用了夫类中的同名函数的情况：它加入了动态分配的机制，通过存档虚函数 所代表的各种虚函数映射情况，便于我们**找到正确的函数**。
3. 实际上也就是在**需要重载（override）函数**前面加入一个**virtual**的关键字（在最前面）；同时可以在覆盖（override）的地方加上**override**关键字（在声明的最后面，大括号的前面），但是这不是必须的，但是更具备可读性。

4. 但是需要额外的内存空间：需要表需要基类指向虚函数表的指针；

5. 需要额外的运行速度：因为每次调用虚函数，需要额外遍历虚函数；

6. 一般情况损耗不会太大，除非对于嵌入式设备来说。

**Virtual Destructors**

和virtual一样，为了我们在使用子类进行多态操作的时候，不会发生没有调用destructor导致内存泄漏的情况。所以就要再析构函数的时候virtual一下。

**Interface（PureVirtualFunction）纯虚函数**

纯虚函数也可以理解为接口，就是需要后续被实现的一些

- 实际纯虚函数就是一种在基类中没有实现的函数：在Jave和C#这类语言中就被称作接口，也就是我们需要在子类中一定要重写的函数。（有时候我们需要每个子类都定义特殊的函数，基类的定义顶多就当作模板，不包含实现方法）
- 在基类中对虚函数的实现（`{}`）改成（`=0；`），就是纯虚函数了，如果我们想要使得子类能够实例化对象，我们就必须在子类中override这个纯虚函数。这种时候基类也不能被实例化了。
- 如果父类对祖父类的override了，那么我们可以直接继承父类就不用再覆写了。BTW：纯虚函数（和成员变量）组成的也叫做抽象类

#### 类的多态

多态 https://www.runoob.com/cplusplus/cpp-polymorphism.html 

其实就是用base的指针来指向子类的一种调用方式

### Override覆盖，Overload重载，Overwrite重写或隐藏，Virtual；

**override** 是一种动态多态，就是在子类中实现基类的override的方法（传参需一致）。

**overload** 是一种静态多态，在同个域中实现不同传参的同名函数定义的方法。

**Virtual** 定义的是虚函数，后面加=0的话是纯虚函数，也就是后续一定要实现的函数。

**Overwrite**叫做隐藏，就是不定义virtual的情况下执行的同名同参数重定义，这种方式在使用基类指针调用的时候会执行基类中的函数，不会执行子类中的函数。只有使用子类指针去调用的时候会执行子类中的函数调用。

### “This” 指针

this是指指向当前对象的指针，索引到当前的instance；

用来调用当前类中的函数或者变量

```c++
class Entity
{
public:
	int x,y;
	Entity(int x, int y)
	{
		this.x = x;
	}
};
```

### 复制构造函数以及浅拷贝深拷贝

复制构造函数的概念和实现：

就是传入值为本类别实例的`const ClassName& A`构造函数，通常需要指定const和&防止循环的复制调用导致栈溢出。

#### 基本概念

通常对Class进行复制或者等号赋值操作的时候，很多情况下会发生内存拷贝，这样会使用新的内存地址去存储新的相同数据，也就是建立一个副本，但是很多情况下是不需要的。（**用等号的时候都是进行的copy**）

这种方式就是建立副本：

```c++
Vector2 a = {2,3};
Vector2 b = a;
b.x = 5; //不改变a
```

可以使用指针建立指针的副本，数据空间不进行拷贝；

```c++
Vector2* a = new Vector2();
Vector2* b = a;
b->x
```

如果不加入&会产生无线递归调用

```c++
Class A
{
private:
    int var;
public:
    A(int temp)
        :var(temp){}
    A(const A temp)
    {
        this->var = temp.var;
    }
}
int main()
{
    A B(2);
    A C = B; //这样会在temp的位置发生无线的递归调用
}
```



#### 浅拷贝：以自定义的String为例

c++已经实现了，这就是个范例；

**memcpy**是内存赋值（赋值内存块）：在这里就是取代for loop 去copy value

```c++
class String
{
private:
	char* m_buffer;
	unsigned int m_size;
public:
	String(const char* string)
	{
		m_size = strlen(string);
		m_buffer = new char[m_size + 1]; //假设包含终止符的情况，但是这样就会对于非普通string的类别不太安全（它们可能不包括终止符）
		memcpy(m_buffer, string, m_size);
	}
	friend std::ostream& operator<<(std::ostream& stream, const String& string);
}
std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream<< string.m_buffer;
	return stream;
}
```

基于终止符的不同情况，我们可以修改成：

```c++
memcpy(m_buffer, string, m_size);
m_buffer[m_size] = 0;
```

但是实际上这样可能会发生内存泄漏，所以实际上我们不应该忘记析构函数：

```c++
~String()
{
	delete[] m_buffer;
}
```

但是如果我们在这种情况下定义的string进行复制的时候，我们会发现，我们实际上是对类中所有的value进行copy，所以我们实际上拷贝了一个指针，然后再最终程序结束的时候，我们对同一个地址调用了两次析构函数，于是程序崩溃了。这就是**浅拷贝**。

#### 深拷贝：以自定义的String为例

我们想要的就是有一个指向新地址的新指针，然后指向的地址有一样的value。

于是**复制构造函数**就被需要了，就是实际上我们是重新调用了一次前面的构造函数，去构造了一个完全相同的变量，而不是只是浅拷贝。

<u>*C++实际上已经存在了一个默认了：我们可以直接声明，但是这实际上是浅拷贝，也就是默认的方式*</u>

```c++
String(const String& other); //这个实际上是浅拷贝 == 下面的

String(const String& other)
    :m_buffer(other.m_buffer), m_size(other.m_size) {}

or if you want to be more exciting...
// 也等同于下面这个，都是浅拷贝
String(const String& other)
{
    memcpy(this, &other, sizeof(String));
}
```

那么如果我们想要完全禁用浅拷贝：我们可以在声明后面加上=delete

实际上就是通过构造函数的类型隐式转换（就是那个等号的重载来实现的），所以我们要弄一个**深拷贝**的话：

```c++
String(const String& other)
    :m_size(other.m_size)
{
	m_buffer = new char[m_size+1]
        memcpy(m_buffer, other.m_buffer, m_size+1);
}
```



### 单例（singleton）

[单例模式(Singleton)及其C++实现_FBeetle的博客-CSDN博客](https://blog.csdn.net/hit0803107/article/details/54411180)

单例是面向对象里面的一种编程模式，也就是某些类别只有一个例子：比如班主任，一个班只需要一个班主任。

或者我们只是要提供一个通用的方法库这种情况下，可以使用这种编程模式。

这就是一种编程方法，我们把东西都放到类中。然后使用类变量来调用global set of function 或者data.我们不需要进行实例化或者其他的操作、

换句话说，我们就是把class 像namespace这样来用。

Singleton 就是组织大量全局变量和static function的方法，将这些组合成一个blob。

**阻止实例化**

1. 可以通过把构造函数设置为私有来阻止实例化操作，但是还是会存在缺陷，还是可以通过下面的操作来类似的实例化；

```c++
Singleton instance = Singleton::Get();
```

2. 但是这样的话会把我们singleton的数据都复制一次（每执行一次复制一次），所以我们需要去除复制构造函数来防止这种操作的实现。这样的话，我们最多就是使用&来使用一个别名进行这个singleton的调用（在上面那个定义加入`&` ->`Singleton&`）

```c++
public:
	Singleton(const Singleton&) = delete;
```

3. 标准的单例调用模式存在一定的麻烦（代码块1），如果我们希望去掉Get来优化调用的过程：可以在定义的时候修改成（代码块2）

```c++
Random::Get().Float();
// 先获得单例，然后调用函数
// 或者使用下面的方式
auto& random = Random::Get();
float number = random.Float();
```

```c++
public:
    static float Float() {return Get().IFloat();}
private:
	float IFloat() {return m_RandomGenerator;}
```

**单例通常使用::在外面定义**，就像下面大图的nullptr

但是如果我们不希望这样（不希望自己在外面进行一个初始化）我们可以写成（写在get里，那么初次调用的时候会生成类static的singleton）（这也是结合了后面修正的**最终版**）（分析一下这些static）第一次生成，后面全是singleton引用。

```c++
class Singleton_origin
{
private:
	// 构建一个通用的单例指针
	static Singleton_origin* s_Instance;
public:
	// 通过Get返回指针所指向的singleton对象
	static Singleton_origin& Get()
	{
		return *s_Instance;
	}
	// 每个Singleton_origin class 的实例中的通用Function
	void hello()
	{
	}
};
Singleton_origin* Singleton_origin::s_Instance = nullptr;

// TYPE2: 实际构建一个singleton怎么去做
// 这一步还没有对复制的情况以及调用的麻烦的情况进行优化，结合下面的最终版。
class Singleton
{
public:
	static Singleton& Get()
	{
		// 这个静态的instance只会在初次调用这个GET的时候生成，后续的话就是直接return他了。所以这样写就行
		// 需要注意的是，由于我们返回的类型设定为reference（&），所以如果我们去掉的了↓的static关键词，就会出错
		// 因为reference返回的是别名，也就是需要这个值一直存在，不然在后续的使用中会出现问题，而不是返回一个copy，当然也可以去掉函数中的&。
		// 所以我们需要借助static 关键词，来延长这个instance的声明周期，才会被正确的使用。
		// 这种只有第一次起到作用的方法，就适用于很多需要初始化的场景。
		static Singleton instance;
		return instance;
	}
	void hello() {}
};
int main()
{
	//Singleton_origin::Get().hello();
	Singleton::Get().hello();

	std::cin.get();
}
```

**最终版** 集成了上面的全部优点，简化了调用，不会进行复制，不需要在类外进行单例的初始化。

```c++
public:
	Random(const Random&) =delete;
	
	static Random& Get()
	{
		static Random instance;
		return instance;
	}
	
	static float Float() {return Get().IFloat();}
private:
	float IFloat() {return m_RandomGenerator;}
	Random(){}
	float m_RandomGenerator = o.5f
```



### 结构体（Structure）

实际上就是一个默认是Public的Class，Class是反过来的。

1. 什么时候该用结构体什么时候该用类？

   **默认情况**下：class是私有的，类或属性（需要共有的时候要public）；而Struct是默认公有的（需要私有的时候要用private）；

2. 这是唯一的区别，但是在代码实际使用的时候还是有所不同的：**存在的原因**

   1. 保持和c之间的兼容性
   2. 或者我们想要全都用public的时候。

3. 自定义使用场景（规定编程风格）

4. 1. Plain old data（pod）的时候喜欢更多的用struct，就是仅仅只代表一堆变量的时候。比如说**定义向量**，这中类似的数据体的时候
   2. “我将永远不会对struct使用继承”

### 公用体（Unions） 

是一种类似Struct的结构，但是同时只能存在一个member（变量），无论你声明了多少个，实际上都是共享内存空间（地址）的，所以如果我们declaration的Type不同，就可能会出现Type Punning的现象，实际上也可以理解为一个变量的多个别名？

[菜鸟教程](https://www.runoob.com/cprogramming/c-unions.html)，[CPP reference](https://zh.cppreference.com/w/cpp/language/union)

- 但是通常**匿名使用**，也就是只使用其**只能有一个member的特性**，很多时候会放置再Struct 之类的里面。和Struct一起匿名使用是不影响我们的调用层级结构的
- 存储空间的大小以最大的成员作为标准好像

```c++
struct Vet2
{
    float x,y;
};
struct Vet4
{
    union
    {
        struct
        {
            float x,y,z,w;
        };
        struct
        {
            Vet2 a,b;
        };
    };
};
// 这样的话
Vet4 v = {1.0f,2.0f,3.0f,4.0f}; 
//v.x 实际上和 v.a.x 是一样的,他们共享了一样的内存地址，这个和type punning有点像。

```

### 结构体绑定（Structured binding）

这一部分实际上解决的是，我们使用struct的方式来实现多类回归的情况：[linkto](#Func: 多值输出 (Multiple Return)),所以参考那一部分就好了

## Part 5 WorkFlow&逻辑控制

This Part 介绍一些算法的逻辑控制以及workflow控制，包括循环，条件，**函数**，线程之类的，控制工作流的内容。

### Func： 基本的函数定义（Functions）

其实没啥特别好说的就是：

- **一般在header 中写入declaration，然后把definition写在Cpp files里面。**
- 其实定义的**全局变量**在function中也是可以**直接调用**的，不需要重新导入之类的。这个应该都是懂的吧
- :star: Always pass you object by const reference!总是使用const和reference传入我们的参数。
- 需要副本就复制.

### Func： 匿名函数（Lambdas）

参考资料：[lambda详细教程](https://zhuanlan.zhihu.com/p/143884880)，[捕获值理解](https://blog.csdn.net/guotianqing/article/details/103460612)

匿名函数实际上是用于基本上一次性的函数：我们不需要真正的（实际的）对函数进行定义。

基本定义方式：`[capture](传入参数){实现内容}`

```c++
auto lambda = [](int value){std::cout<<"Value:"<<value<<std::endl;};
// 调用的时候
lambda(5);
```

- 需要传入外部数据的时候就需要使用Capture，比如main中的值，用&or =；如果我们要使用Capture的时候，我们可能要`#include<functional>`

- **Question:** lambda的传入的参数默认是不能修改的，要修改的话我们需要加入mutable关键词（在传入参数和实现内容之间）

其他的lambda实例：

```c++
std::vector<int>values = {1,5,4,2,3};
std::find_if(values.begin(), values.end(), [](int value){return value>3;});
// it actually is👇 返回第一个>3的值
auto it = std::find_if(values.begin(), values.end(), [](int value){return value>3;});
std::cout<< *it <<std::endl;
```

### Func：三元运算符（Ternary Operator）

**条件表达式？表达式1：表达式2**

这种形式实际上和python中的如下的表达式一致

```python
Flag = True
a = 5 if Flag else 10
```

c++中表示为如下

```c++
s_Speed = s_Level > 5? 10: 5;
s_Speed = s_Level > 5? s_Level >10? 15: 10: 5;
```



### Func: 多值输出 (Multiple Return)

include新报本的结构体绑定方式。

由于C++本身的Type机制，我们没办法在func中同时**直接**return不同类型。

- 而如果我们试图return同一type的多个value的话，我们实际上可以用return**vector或者array**的方式实现，当然这就是一种比较蠢的操作了。

  > stdarray或者传统的array
  >
  > 好像也可以使用tuple的方式{v1,v2}同个类型的多个值

- **推荐：**当然聪明一点的方法就是，我们定义一个struct，包含我们需要的这些所有type，然后**return这个struct**就好了

- 还有一种方法就是使用**&来传递参数**，就不需要return了，设置为void就可以了

  > 也可以用指针的方式，指针方式的好处就是可以是空值

**C++的默认指定方式：tuple和pair**

用tuple类型的方式操作起来有点麻烦啊如下，但是也可以混杂多种类型输出。

```c++
#import <tuple>
static std::tuple<type1,typw2> func()
{
    //return std::make_pair<type1,type2>(var1,var2);
    //上面的type指定有时候也能省略
    //或者使用下面这种方式,上面那种实际上是pair类型的返回把
    return {var1,var2}
}
auto [name, age] = func();
// c++ 标准更新以后tuple的使用方法变得更加的好用了。
    
------------------👆NEW Version & Called Structure Binding----------------
--------------------------------👇OLD VERSION <c++17----------------------
//std::tuple<type1,type2> a = func();
////或者
//auto a = func();
////oldversion要取出元素的时候我们还需要
//std::string& name=std::get<0>(a); //这里可以用&防止动态的内存copy的情况
//std::get<1>(a);
////所以这边建议使用struct

//// 取出元素的第二种方法.
//std::string name;
//int age;
//std::tie(name,age) = func();
```

### Threads：线程操作

函数编写过程中的多线程操作和线程管理，下面是一个典型的例子，我们**好像**也可以使用进程去建立一个线程对象。

使用线程主要的目的是为了1. 完成单线程没法完成的事情以及2. 优化一些算法的运行速度。

```c++
#include <iostream>
#include <thread> //支撑线程的基准库

static bool Flag = true;
// 编写一个函数用于子进程的执行，通常使用函数指针的方式调用
void DoWork()
{
    
    while (true)
    {
        std::cout<<"Working... \n";
        std::this_thread::sleep_for(1s); //休眠这个进程1s，防止疯狂打印
    }
}

int main(){
    std::thread worker(DoWork); //使用一个进程去执行Dowork
    
    std::cin.get();
    Flag = false; //使得子进程得以结束。
    
    worker.join();//等待到子进程结束，再继续主进程
    std::cin.get();
}
```

如果我们再调用某个进程的时候想看当前的ID，也可以再运行的函数中加入`STD::this_thread::get_id()`得到当前进程的ID。当然我们每次运行可能都是不一样的。

### Threads：多线程管理

**这一部分没有英文字幕，缺失了很多信息，后续使用到的时候进行补充和修正把。**

线程并行；异步；等等的多线程管理。`std::async`

对于**independent**的Application和Function Part，实际上很多操作我们可以在cpu和memory上并行进行，对不相关的任务进行分布（异步），对相关的任务有所约束（同步），合理的对进程进行调度，能够使得我们对资源有更充分的利用，同时也能提升程序的运行速度。

对于不依赖于运行次序的一些操作：比如载入很多模型或者数据（num_worker）

[cppref参考页面](https://zh.cppreference.com/w/cpp/thread/async)；[异步合同的概念](https://www.cnblogs.com/IT-CPC/p/10898871.html)；

```c++
#include<future>
static std::mutex s_meshesMutex; //解决1. 针对变量定义一个互斥锁
static void LoadMesh(std::vector<Ref<Mesh>>& meshes, std::string filepath)
{
    auto mesh = Mesh::Load(filepath);
    //解决1. 使用lock，锁住我们可能需要修改的这个变量，使得一个thread在进行修改的时候，🔒（其余不能对该变量进行操作），修改完成解锁🔑；
    std::Lock_guard(std::mutex) lock(s_meshexMutex)
    meshes.push_back(mesh);
}
for (const auto& file : filelist)
{
    //1. 异步使用文件载入，但是这样会出现问题，就是当我们两个进程同时进行修改操作的时候怎么办？
  m_Futures.push_back(std::async(std::lauch::async,LoadMesh,m_Meshes,filelist));
}
```

为了防止同时的写入操作，我们还需要Lock操作去锁住可能会修改的变量。同时好像异步程序的返回值比较特殊，所以我们需要在头文件中进行如下定义：

```c++
std::vector<std::future<void>> m_Future;
```

此外我们可以控制是否执行异步程序（老办法了）

```c++
#define ASYNC 1
#if ASYNC
	ASYNCfunc()
#else
	func()
#endif
```

最后我们可以在debug的时候 windows ，parallel stacks找到进程表（很吊）。好像也可以在执行代码的地方跳到正在执行的某个进程

### Benchmark：基准测试

在运行程序的时候如何监控我们该**代码的性能**（**运行时间**等等），或者测试新方法的方式。这里给出了他的方式。实际上有很多不同的方式。

`_debugbreak()`: 类似python中的raise exception

```c++
// 简单的范例，
int main()
{
    int v = 0;
    {
        Timer timer1;
        func()
    }
    ...;
    _debugbreak();
}
```

我们要确信的一点是，计时器是否真正的测量了运行的时间，因为有时候编译器会直接进行中间态计算，所以实际运行的时候，就会没有计算到开销。

**测量share pointer和unique pointer**

unique>make share >new share

#### Visual Benchmarking （可视化）

使用`chrome:://tracing` 在浏览器中进行可视化,这一课作为补充资料把。暂时不需要用这种方式

### Switch：case 分支

一个 **switch** 语句允许测试一个变量等于多个值时的情况。每个值称为一个 case，且被测试的变量会对每个 **switch case** 进行检查。

```c++
switch(expression){
    case constant-expression  :
       statement(s);
       break; // 可选的
    case constant-expression  :
       statement(s);
       break; // 可选的
  
    // 您可以有任意数量的 case 语句
    default : // 可选的
       statement(s);
}
```

### Workflow：Conditions and Branches 条件和分支

if 指令实际上是检查**值是否为0**，0 == False， !0 ==True;

Keyword：`if`; `else if`; `else`;

### Loops: For and While 循环定义

1. **For 循环其实就是 （声明变量；condition；迭代规则）**

   我们可以直接在括号里写，也可以全部写在外面

   condition要声明，但是可以在外面定义

2. **While （condition）**

3. **Do {**

   **}While（condition）**

   即使条件为false也至少能执行一次

### Workflow: Control Flow (contiune, break , return) 循环控制

这几个关键词的使用和含义基本是和Python一致的，但是这里的Break还用于switch

### Workflow： Iterators迭代器

迭代器的一些基本的参数：first（key），（当然这个是以这种形式存在的是时候才有的）second（value）；it本身是以指针形式存在的？

是一种对dataset中的数据进行迭代的方式，这就是一种迭代器，有点像是运算符重载，通常用于对数据结构进行迭代（遍历）。

```c++
 //最常见的方式就不再说了，。vector.size()来循环就行了
#include <vector>
// type1 内置的迭代器，也是常用的使用方式。
std::vector<int> values = {1,2,3,4,5};
for (int value : values)
    std::cout<<value<<std::endl;
// type2 使用内置的iterator，还有反向的iterator，但是正常人谁用这个啊
// 这里注意到it是一堆指针，我们如果要取值的话需要解除指针。*
for(std::vector<int>::iterator it = values.begin(); it != values.end(); it++){
    std::cout<<*it<<std::endl;
}
```

那么我们如何对于**无序的数集**(实际上unorder_map是Hash的C++实现)来进行迭代或者遍历呢？，看下面这个例子：

```c++
#include <unordered_map>
using ScoreMap = std::unordered_map<std::string, int>;
//std::unordered_map<std::string, int> map;
ScoreMap map;
map["aiken"] = 5;
map["c++"] = 2;
// 由于无序图没有index，经典的就是使用这样的方式
for (ScoreMap::const_iterator it = map.begin(); it != map.end(); it++)
{
    auto& key = it->first;
    auto& value = it->second; //second 应该指的是value把，但是对于多元素的hash怎么处理？
    PRINT_FUC HERE.
}
// 仿照上面那种更方便的方式来编写迭代的话(这里的auto 实际上是pair的形式)
for (auto kv : map)
{
    auto& key = kv->first;
    auto& value = kv->second;
    PRINT_FUC HERE.
}
// 当然还有一种梦寐以求的方式，后续可能我们会最常用的方式
for (auto [key, value] : map)
{
    std::cout << key << "=" << value << std::endl;
}
```

**编写我们自己Structure中的Iterator**：

假设：这是不是应该使用类似linklist之类的方式，将数据通过类似指针的方式迭代的串起来？

这一部分太长了，还是参考[视频94](https://www.youtube.com/watch?v=F9eDv-YIOQ0&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=94&ab_channel=TheCherno)把，我就直接重载[]和size通过for去做迭代器了，建议加入相关的.cpp，不要集成在文档中。

这一部分其实可以帮助对一些重载，还有一些vector机制有一个更好的理解，以及一些动态的内存管理，可以自己在后续编写一下试试。

### Workflow: Continuous Integration CI （持续集成）

每次commit后都build 以及run &test就是CI吗？

“持续集成是一种软件开发实践，即团队开发成员经常集成他们的工作，通常每个成员每天至少集成一次，也就意味着每天可能会发生多次集成。每次集成都通过自动化的构建（包括[编译](https://baike.baidu.com/item/编译/1258343)，发布，自动化测试）来验证，从而尽早地发现集成错误。”

使用：jenkins（第86课）

### Workflow: Static Analysis(静态代码分析)

也就是一些分析工具，比如pylint之类的东西；

Cherno推荐：PVS-Studio

## Part 6  Memory 资源管理

This Section 我们从memory出发来谈及关于Stack，Heap之类的内存管理和优化方法,以及编写的safe。

[粗略：Heap和Stack的区别](https://www.cnblogs.com/2sheep2simple/p/10680347.html)；[进阶1：C++中内存分配，堆（Heap）与栈（Stack）区别](https://www.cnblogs.com/iostream7/archive/2010/12/08/1900279.html)

[为什么c++中要分为heap（堆）和stack（栈）](https://www.zhihu.com/question/281940376)

### Stack vs Heap: C++中的内存栈与堆

`char* buffer = new char[8]` 定义一个8个字节的内存空间，并返回指向内存开始的地址的指针

**基本概念**：stack和heap都是内存（RAM）中实际存在的单元

- stack存在预定义的长度: 2M左右。
- heap虽然已有预设的默认值，但会随着我们的Application去更改大小
- 目的都是为我们的程序和全局或者局部变量提供存储空间。
- 不同的内存分配方式。
- memset可以用来填充内存块
- memcpy 内存拷贝，拷贝内存块

**基本定义方式：**前面一般是定义在stack上的，后半部分是定义在heap上的

```c++
int main()
{
    int value = 5;
    int array[5];
    ClassA vector;
    
    int* hvalue = new int;
    *havalue = 5;
    int* harray = new int[5];
    ClassA* hvector = new ClassA();
}
```

**分配方式上的区别**（主要是**new**）

1. **stack**上分配的内存空间是**连续的**，实际上就是栈顶的指针移动需要的距离，然后重新赋予数值。每一个在另一个上面。
   1. 所以这样分配会比较快，我们只需要在寄存器上移动指针的地址就可以了
   2. {}实际上就是一个stack，超出这个作用域后，栈内的数据会自动销毁，也就是实际上就是将指针还原到了作用域开始的地方。Free操作实际上只是指针的移动。
2. heap上分配的内存空间是随机的。
   1. 实际上会call `malloc`，给你一个指定大小的内存块，同时也会管理一个**需要**free-list的内存列表（也就是已经申请了的列表），
   2. 所以在heap上**分配**空间实际上是一整套任务，而在stack上实际上就是指针移动，他们两个的效率是完全不一样的。但是有各自面对的状况吧。
   3. 需要大量数据，或者说是，需要延长生存周期的话都需要用heap。
3. 在debug model中的汇编之类的机器代码是没有经过精简的，但是release后vs会自己优化。

### New：Keyword For Mem内存关键词

使用new实际上是一系列命令（运算符重载），包括在空闲的内存块中占用一块指定大小的内存，所以会**需要时间**；

基本准则：**有new有Delete；无new 无delete**

- new经常和数组一起使用来获得指定大小的heap空间
- new在使用的时候也会调用constructor（构造函数），相应的delete；
- new ->delete; new [] -> delete [];

```c++
int* b = new int [50];
Entity* e = new Entity[50]; //这种情况下同时会调用构造函数
//虽然我们可以用malloc指令定义，但是这种方式不会调用析构函数，所以千万不要用这种方法。
```

具体的底层原因：

> new底层其实是call了malloc，malloc是memory allocation的简写，从名字也可以知道它负责分配内存，delete则调用了free()。区别是new和delete不仅管理内存，还会调用constructor和destructor，另外它们都是operator，所以你可以重载它们，做一些有趣的事情。
>
> 对了，new【】和delete【】其实另两个operator，它们做的事情稍微有点不一样，你调用new【】的时候，必须要指定一个size，但调用delete【】的时候，并没有指定size，它怎么知道delete多少呢？这是因为new【】不仅分配了所需要的内存，还会多分配一个额外的空间，来存储这个size，所以以视频中的举例，它所做的是分配这样一块内存【8, 0, 0, 0, 0, 0, 0, 0, 0】，连续的，但是多一块在最前面，但是return给你的是跳过那块内存的地址，比如malloc返回的是0x1，但new【】给你返回的是0x1+2（我记得它分配的是一个word（一般是short）的大小，具体大小需要看系统），然后在delete【】的时候，它会往前推一个word，因为它知道前面一个word肯定是size，从而拿到size，进而delete所有）

**什么时候通过New来定义实体（instance）**

- 就是如果我们希望在一个Function中定义类的实体的时候，为了延长生命周期，我们需要将实体定义在heap上

- 或者是class 规模太大，但是stack太小了，所以我们要借助heap的存储空间

- ```c++
  Entity* entity = new Entity("Cherno");
  ```

  

### Safety：使用智能指针的情景

什么样的程序是safe的？减少崩溃和内存泄漏的情况，也就是让Code尽量不要越过需要的边界。This Part is about Smart Pointer。

实际上安全性和内存分配是分不开的。

- 对自己所有allocated的memory负责，所以智能指针特别屌，应该**100%使用智能指针，不要仅仅使用原生指针（Raw Poniter），能不用就尽量不用。**智能指针我们就不需要担心delete或者内存泄漏等等的问题了。
- Raw Poniter在我们使用的小规模程序的时候偷懒，因为只要使用※，他不安全，就只是好读和简单。
- 所以就是，使用smart pointer，当然在确保安全的情况下，我们也可以用raw pointer自由选择反正。优点和缺点就是这样了。

### Track Memory Allocation：内存申请跟踪

优化跟踪内存管理对于计算机的性能来说相当重要，特别是我们要知道我们在哪里分配了数据。

虽然heap的space比较大，但是在性能至上的环境中，可能heap不会是一个最佳的选择。

智能指针会在heap上分配内存，（**std::string都是分配在内存中的**）

**Easy Way：**

这一部分能够简单的嵌入我们的任何project；(void* 存储的就是一个内存地址)

基本思路：重载我们的new 操作符;

```c++
import <memory>
void* operator new(size_t size)
{
    std::cout<<"Allocating"<<size<<'Bytes\n';
    return malloc(size);
}
```

那么当然我们也可以重载delete去检测内存的释放情况

```c++
void operator delete(void* memory, size_t size)
{
    std::cout<<"deleteing"<<size<<'Bytes\n';
    free(memory);
}
```

那么最方便的实现方法就是我们使用一个struct来统一管理我们的内存分配情况。

```c++
struct AllocationMetrics
{
    uint32_t TotalAllocated = 0;
    uint32_t TotalFreed = 0;
    
    uint32_t CurrentUsage(){return TotalAllocated-TotalFreed;}
}
//实例化全局架构
static AllocationMetrics s_AllocationMetrics;
// 然后将上面的new和delete中的print改成+= 和-=
static void PrintUsage()
{
    std::cout<<"usage::"<<s_AllocationMetrics.CurrentUsage()<<"...\n"
}
```



## Part 7 How to make C++ run Faster

算法或者进程优化的部分，这一部分在做题的时候慢慢的进行填充把，在学习的时候先选择性的看看，实际上应该是Part6的延申，逃不脱资源管理的部分、

TODO：（已知可以但是应该暂时没用）

- `std::async` （应该是用于进程优化） 79课
- 80 83：string优化

### run string faster 优化string的运行速度

string会在heap上allocated，所以对于性能优先的情况下不是特别推荐的,可以通过下面的方式查看heap申请。

```c++
void PrintName(const std::string& name){}
// 想要看空间的声明，重载new就对了，看Part6
static uint32_t s_AllocCount = 0;
void* operator new(size_t size)
{
    s_AllocCount ++;
    PrintHere;
    return malloc(size)
}
PrintName(const std::string& name){}
int main()
{
    name = "aiken";
    Print(name); //copy一次
    std::string name = "aiken aiken"; //copy
    std::string firstname = name.substr(0,3); //copy
    std::string lastname = name.substr(4,9); //copy 
}
```

但是加入我们只是想要一个很简单的输出“”，不希望发生再次的construct，来增加一个string的heap空间。甚至我们使用`substr()`来输出其中的一部分，也会copy（allocation）一次原本的string。

**避免这样无意义的Copy**，只是要一个指向原数据内存地址的指针，以及size把，我们可以很容易写一个这样的类，但是在C++17中官方集成了把👇

```c++
PrintName(std::string_view name){} //这样以后print（“”）也不会分配了，原本的情况，执行print甚至都会复制一份。究极不合适
std::string name = "aiken aiken"; //allocation only
//3可以修改成5 就没有allocation了,但是5的话 6，7的c_str()要去掉
const char* name = "aiken aiken"; //not allocation 
std::string_view firstName(name.c_str(),3);
std::string_view lastName(name.c_str()+4,9);
print(firstName); //这种类型也不会再发生复制了
print(LastName);
print("aiken aiken");
----------------------------------整理如下--------------------------------------
//只在定义的时候发生一次赋值。
printname(std::string_view name){}
std::string name = "aikenaiken"; //allow 1(copy happen)
std::string_view firstName(name.c_str(),3);
std::string_view lastName(name.c_str()+4,9);
print(firstName); //这种类型也不会再发生复制了
print(LastName);
print("aiken aiken");
```

## Somthing Else 无题

畅所欲言，或者等待归类。

- `sizeof`通常用来获取数据的存储空间；
- `strlen()`:获取const char*的长度
- `alloca(size)`：再当前地址内存分配；所以我们可以类型转换指针（int*）
- `size_t`:可以存储各种类型大小的值,size type
- `constexpr`https://www.jianshu.com/p/34a2a79ea947 
- `\`:编写代码的时候的换行续接符号

wandbox.org ：在线编译网站

Visual Studio 表达式的编译顺序是从右到左运算

### Argument Evaluation Order 参数输入顺序（面试？）

传入参数实际上可以是传入一个函数或者是一个表达式，我们应该规划一下这样的输入。（和++相关）

i ++ : 先传递在增长 ，++i：先增长在传递把

(**undefine behavior**: 意味着这种方式实际上没有被定义，也就是说是一种不可控的行为，下面是一种实例)（切换这种++的位置也是）

``` c++
void Psum(int a, int b)
{
   std::cout<<a <<"+"<<b <<"="<<a+b<<std::endl;
}
value = 0；
Psum(value++,value++);
//这是一种不可靠的编写方式,这个输出是不确定的，也就是一个不可靠的结果。
//哪个在线编译网站会告诉我们这个的编写是不确定的。有warning
```

正确答案是这种实际上是C++没有规范的，我们没法得到真实的值，但是再C++17中要求：

The Postfix-Expression is Sequenced before each expression in the expression-list and any default argument。

也就是他们需要被一个接着一个的运行。这个其实没有太听清。

https://blog.csdn.net/samantha_wang/article/details/46942343 

https://blog.51cto.com/8681495/1416759

也不要写像这种的

`v[i] = ++i;`