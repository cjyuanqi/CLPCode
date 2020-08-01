//
//  part6.cpp
//  CLPCode
//
//  Created by 陈俊 on 2019/12/31.
//  Copyright © 2019 陈俊. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

// 在 C++ 中，除了可以创建各种函数，还包含了各种有用的函数供您使用。这些函数写在标准 C 和 C++ 库中，叫做内置函数。您可以在程序中引用这些函数。
// 为了利用这些函数，您需要引用数学头文件 <cmath>。

// 数组
// C++ 支持数组数据结构，它可以存储一个固定大小的相同类型元素的顺序集合。数组是用来存储一系列数据，但它往往被认为是一系列相同类型的变量。

// 声明数组
// type arrayName [ arraySize ];
// double balance[10];


// 初始化数组
// double balance[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};   // 逐个初始化数组
// double balance[] = {1000.0, 2.0, 3.4, 7.0, 50.0};    // 如果您省略掉了数组的大小，数组的大小则为初始化时元素的个数
// balance[4] = 50.0;   // 为数组中的某个元素赋值.


// 访问数组元素
// double salary = balance[9];      // 数组元素可以通过数组名称加索引进行访问

// C++ 字符串
// C++以下两种类型的字符串表达格式
// C风格的字符串
// C++ 引入的 string 类类型


// C风格的字符串
// 字符串实际上是使用 null 字符 '\0' 终止的一维字符数组
// 下面的声明和初始化创建了一个 "Hello" 字符串。由于在数组的末尾存储了空字符，所以字符数组的大小比单词 "Hello" 的字符数多一个。
// char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};  等价于 char greeting[] = "Hello";
void p6_test1()
{
    char str1[11] = "Hello";
    char str2[11] = "World";
    char str3[11];
    unsigned long len ;
    
    // 复制 str1 到 str3
    strcpy( str3, str1);
    cout << "strcpy( str3, str1) : " << str3 << endl;
    
    // 连接 str1 和 str2
    strcat( str1, str2);
    cout << "strcat( str1, str2): " << str1 << endl;
    
    // 连接后，str1 的总长度
    len = strlen(str1);
    cout << "strlen(str1) : " << len << endl;
    
}


// C++中的String类
// C++ 标准库提供了 string 类类型，支持上述所有的操作，另外还增加了其他更多的功能。
void p6_test2()
{
    string str1 = "Hello";
    string str2 = "World";
    string str3;
    unsigned long len ;
    
    // 复制 str1 到 str3
    str3 = str1;
    cout << "str3 : " << str3 << endl;
    
    // 连接 str1 和 str2
    str3 = str1 + str2;
    cout << "str1 + str2 : " << str3 << endl;
    
    // 连接后，str3 的总长度
    len = str3.size();
    cout << "str3.size() :  " << len << endl;
}





void get_random_num(void);

int main6()
{
    // 数字定义
    int    i = -1000;
    float  f = 230.47;
    double d = 200.374;
    
    // 数学运算
    cout << "sin(d) :" << sin(d) << endl;
    cout << "abs(i)  :" << abs(i) << endl;
    cout << "floor(d) :" << floor(d) << endl;
    cout << "sqrt(f) :" << sqrt(f) << endl;
    cout << "pow( d, 2) :" << pow(d, 2) << endl;
    
    get_random_num();
    
    char str1[11] = "Hello";
    char str2[11] = "World";
    char str3[11];
    unsigned long len ;
    
    // 复制 str1 到 str3
    strcpy( str3, str1);
    cout << "strcpy( str3, str1) : " << str3 << endl;
    
    // 连接 str1 和 str2
    strcat( str1, str2);
    cout << "strcat( str1, str2): " << str1 << endl;
    
    // 连接后，str1 的总长度
    len = strlen(str1);
    cout << "strlen(str1) : " << len << endl;
    
    
    
    return 0;
}

// 关于随机数生成器，有两个相关的函数。一个是 rand()，该函数只返回一个伪随机数。生成随机数之前必须先调用 srand() 函数。
// 下面是一个关于生成随机数的简单实例。实例中使用了 time() 函数来获取系统时间的秒数，通过调用 rand() 函数来生成随机数：
void get_random_num() {
    int i,j;
    
    // 设置种子
    srand( (unsigned)time( NULL ) );
    
    /* 生成 10 个随机数 */
    for( i = 0; i < 10; i++ )
    {
        // 生成实际的随机数
        j= rand();
        cout <<"随机数： " << j << endl;
    }
}


