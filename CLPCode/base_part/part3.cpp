//
//  ConstDefine.cpp
//  CLPCode
//
//  Created by 陈俊 on 2019/12/31.
//  Copyright © 2019 陈俊. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

// 1. 常量
// 常量是固定值，在程序执行期间不会改变。这些固定的值，又叫做字面量。
// 常量可以是任何的基本数据类型，可分为整型数字、浮点数字、字符、字符串和布尔值。

// 整数常量
// 整数常量可以是十进制、八进制或十六进制的常量。
// 前缀指定基数：0x 或 0X 表示十六进制，0 表示八进制，不带前缀则默认表示十进制。
// 后缀是 U 和 L 的组合，U 表示无符号整数（unsigned），L 表示长整数（long）。后缀可以是大写，也可以是小写，U 和 L 的顺序任意。


// 浮点常量
// 浮点常量由整数部分、小数点、小数部分和指数部分组成。您可以使用小数形式或者指数形式来表示浮点常量。
// 使用小数形式表示时，必须包含整数部分、小数部分，或同时包含两者。
// 使用指数形式表示时， 必须包含小数点、指数，或同时包含两者。带符号的指数是用 e 或 E 引入的

// 布尔常量
// 布尔常量共有两个，它们都是标准的 C++ 关键字：true 值代表真。 false 值代表假。
// 我们不应把 true 的值看成 1，把 false 的值看成 0。

// 字符常量
// 字符常量是括在单引号中。
// 如果常量以 L（仅当大写时）开头，则表示它是一个宽字符常量（例如 L'x'），此时它必须存储在 wchar_t 类型的变量中。
// 否则，它就是一个窄字符常量（例如 'x'），此时它可以存储在 char 类型的简单变量中。
// 字符常量可以是一个普通的字符（例如 'x'）、一个转义序列（例如 '\t'），或一个通用的字符（例如 '\u02C0'）。

// 字符串常量
// 字符串字面值或常量是括在双引号 "" 中的。

// 定义常量
// 使用 #define 预处理器。
// 使用 const 关键字。

// #define定义常量
#define LENGTH 10
#define WIDTH  5
#define NEWLINE '\n'

void p3_test1()
{
    // const定义常量
    const int  C_LENGTH = 10;
    const int  C_WIDTH  = 5;
    const char C_NEWLINE = '\n';
    
    int area;
    
    area = C_LENGTH * C_WIDTH;
    cout << area;
    cout << C_NEWLINE;
}

// 2. C++修饰符类型
// C++ 允许在 char、int 和 double 数据类型前放置修饰符。修饰符用于改变基本类型的含义，所以它更能满足各种情境的需求。
// 修饰符 signed、unsigned、long 和 short 可应用于整型，signed 和 unsigned 可应用于字符型，long 可应用于双精度型。
// 修饰符 signed 和 unsigned 也可以作为 long 或 short 修饰符的前缀。例如：unsigned long int。
// C++ 允许使用速记符号来声明无符号短整数或无符号长整数。您可以不写 int，只写单词 unsigned、short 或 unsigned、long，int 是隐含的

// 3. C++ 中的类型限定符
// const    const 类型的对象在程序执行期间不能被修改改变。
// volatile    修饰符 volatile 告诉编译器不需要优化volatile声明的变量，让程序可以直接从内存中读取变量。对于一般的变量编译器会对变量进行优化，将内存中的变量值放在寄存器中以加快读写效率。
// restrict    由 restrict 修饰的指针是唯一一种访问它所指向的对象的方式。只有 C99 增加了新的类型限定符 restrict。

// 4. 存储类
// 存储类定义 C++ 程序中变量/函数的范围（可见性）和生命周期。这些说明符放置在它们所修饰的类型之前。
// 下面列出 C++ 程序中可用的存储类：auto register static extern mutable thread_local (C++11)

// auto存储类
// 声明变量时根据初始化表达式自动推断该变量的类型、声明函数时函数返回值的占位符。
// C++98标准中auto关键字用于自动变量的声明，但由于使用极少且多余，在C++11中已删除这一用法。
void p3_test2() {
    auto f=3.14;      //double
    auto s("hello");  //const char*
    auto z = new auto(9); // int*
//    auto x1 = 5, x2 = 5.0, x3='r';//错误，必须是初始化为同一类型
    cout << f << s << z << endl;
}

// register存储类
// register 存储类用于定义存储在寄存器中而不是 RAM 中的局部变量。
// 这意味着变量的最大尺寸等于寄存器的大小（通常是一个词），且不能对它应用一元的 '&' 运算符（因为它没有内存位置）。
// 定义 'register' 并不意味着变量将被存储在寄存器中，它意味着变量可能存储在寄存器中，这取决于硬件和实现的限制。
void p3_test3()
{
//    register int  miles = 25;
//    cout << miles;
};

// static存储类
// static 存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开作用域时进行创建和销毁。
// 因此，使用 static 修饰局部变量可以在函数调用之间保持局部变量的值。
// static 修饰符也可以应用于全局变量。当 static 修饰全局变量时，会使变量的作用域限制在声明它的文件内。
// 在 C++ 中，当 static 用在类数据成员上时，会导致仅有一个该成员的副本被类的所有对象共享。
// 函数声明
void func1(void);
 
static int num = 10; /* 全局变量 */

// extern存储类
// extern 存储类用于提供一个全局变量的引用，全局变量对所有的程序文件都是可见的。
// 当您使用 'extern' 时，对于无法初始化的变量，会把变量名指向一个之前定义过的存储位置。
// 通过extern来引用全局变量或全局函数
int part3_num;
extern void part2_func(void);


// mutable存储类
// mutable 说明符仅适用于类的对象, 它允许对象的成员替代常量。也就是说，mutable 成员可以通过 const 成员函数修改。

// thread_local存储类
// 仅可以在当前线程内部访问, 变量在创建线程时创建，并在销毁线程时销毁。
thread_local int x; // 命名空间下的全局变量
class X
{
    static thread_local std::string s; // 类的static成员变量
};
//static thread_local std::string X::s;  // X::s 是需要定义的
//
//void foo()
//{
//    thread_local std::vector<int> v;  // 本地变量
//}


int main3()
{
    // const定义常量
    const int  C_LENGTH = 10;
    const int  C_WIDTH  = 5;
    const char C_NEWLINE = '\n';
    int area;
    
    area = C_LENGTH * C_WIDTH;
    cout << area;
    cout << C_NEWLINE;
    
    cout << "Hello \t World \n\n";
    
    short int i;
    short unsigned int j;
    
    j = 50000;
    
    i = j;
    
    cout << i << " " << j << '\n';
    
    while(num--)
    {
        func1();
    }
    
    part3_num = 5;
    part2_func();
    
    return 0;
}


// 函数定义
void func1( void )
{
    static int i = 5; // 局部静态变量
    i++;
    
    cout << "变量 i 为 " << i;
    
    cout << " , 变量 num 为 " << num << endl;
}
