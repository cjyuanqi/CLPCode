//
//  variableDefine.cpp
//  CLPCode
//
//  Created by 陈俊 on 2019/12/31.
//  Copyright © 2019 陈俊. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

// 1. 变量定义: 变量定义就是告诉编译器在何处创建变量的存储，以及如何创建变量的存储。变量定义指定一个数据类型，并包含了该类型的一个或多个变量的列表
int i, j, k;
char ch;
float salary;
double d;

// 2. 变量声明
// 变量声明向编译器保证变量以给定的类型和名称存在, 这样编译器在不需要知道变量完整细节的情况下也能继续进一步的编译.  只在一个文件中定义, 在多个文件中调用时, 变量声明就显得非常重要.

// 3. 变量声明
extern int a, b;
extern int c;
extern float f;

extern int part3_num;

// 4. 函数声明
// 在函数声明时，提供一个函数名，而函数的实际定义则可以在任何地方进行
int func();

// 5. c++中的左值(Lvalues) 和右值(Rvalues)
// 左值（lvalue）：指向内存位置的表达式被称为左值（lvalue）表达式。左值可以出现在赋值号的左边或右边。
// 右值（rvalue）：术语右值（rvalue）指的是存储在内存中某些地址的数值。右值是不能对其进行赋值的表达式，
// 也就是说，右值可以出现在赋值号的右边，但不能出现在赋值号的左边。
// 变量是左值，因此可以出现在赋值号的左边。数值型的字面值是右值，因此不能被赋值，不能出现在赋值号的左边

// 6. 局部变量
// 在函数或一个代码块内部声明的变量，称为局部变量


// 7.全局变量
// 在所有函数外部定义的变量（通常是在程序的头部），称为全局变量. 全局变量的值在程序的整个生命周期内都是有效的.
// 全局变量可以被任何函数访问。也就是说，全局变量一旦声明，在整个程序中都是可用的。
// 在程序中，局部变量和全局变量的名称可以相同，但是在函数内，局部变量的值会覆盖全局变量的值。
int g;

int main2()
{
    // 局部变量
    int a, b, c;
    // 实际初始化
    a = 10;
    b = 20;
    c = a + b;
    cout << c << endl;

   
    
    // 函数调用
    int i = func();
    
    cout << i << endl;
    
    g = 28;
    int g = 10; // 函数内部局部变量的值覆盖全局变量的值.
    cout << g << endl;
    
    return 0;
}

// 函数定义
int func() {
    return 0;
}

void part2_func(void) {
    cout << "part3_num is:" << part3_num << endl;
}

