//
//  part8.cpp
//  CLPCode
//
//  Created by 陈俊 on 2020/1/1.
//  Copyright © 2020 陈俊. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace std;

// C++引用
// 引用变量是一个别名，也就是说，它是某个已存在变量的另一个名字。
// 一旦把引用初始化为某个变量，就可以使用该引用名称或变量名称来指向变量。

// C++引用 VS 指针
// 不存在空引用。引用必须连接到一块合法的内存。
// 一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
// 引用必须在创建时被初始化。指针可以在任何时间被初始化。

// 试想变量名称是变量附属在内存位置中的标签，您可以把引用当成是变量附属在内存位置中的第二个标签
void p8_func1()
{
    // 声明简单的变量
    int i;
    double d;
    
    // 声明引用变量
    int &r = i;
    double &s = d;
    
    i = 5;
    cout << "Value of i : " << i << endl;
    cout << "Value of i reference : " << r << endl;
    
    d = 11.7;
    cout << "Value of d : " << d << endl;
    cout << "Value of d reference : " << s << endl;
}

// 把引用作为参数
void swap(int& x, int& y);

// 把引用作为返回值
// C++ 函数可以返回一个引用，方式与返回一个指针类似
// 当函数返回一个引用时，则返回一个指向返回值的隐式指针。这样，函数就可以放在赋值语句的左边。
double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};
double& setValues(int i)
{
    return vals[i]; // 返回第 i 个元素的引用
}

// 当返回一个引用时，要注意被引用的对象不能超出作用域。所以返回一个对局部变量的引用是不合法的，但是，可以返回一个对静态变量的引用。
int& p8_func2()
{
//    int q;
//    return q;     // 在编译时发生错误
    static int x;
    return x;       // 安全, x在函数作用域处依然有效的
}

// C++ 日期 & 时间
// C++ 标准库没有提供所谓的日期类型。C++ 继承了 C 语言用于日期和时间操作的结构和函数。为了使用日期和时间相关的函数和结构，需要在 C++ 程序中引用 <ctime> 头文件。
// 有四个与时间相关的类型：clock_t、time_t、size_t 和 tm。类型 clock_t、size_t 和 time_t 能够把系统时间和日期表示为某种整数。
// 结构类型 tm 把日期和时间以 C 结构的形式保存，tm 结构的定义如下：
/*
struct tm {
  int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
  int tm_min;   // 分，范围从 0 到 59
  int tm_hour;  // 小时，范围从 0 到 23
  int tm_mday;  // 一月中的第几天，范围从 1 到 31
  int tm_mon;   // 月，范围从 0 到 11
  int tm_year;  // 自 1900 年起的年数
  int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
  int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
  int tm_isdst; // 夏令时
}
 */
void p8_func3()
{
    time_t now = time(0); // 基于当前系统的当前日期/时间
    
    char *dt = ctime(&now); // 把now转化为字符串形式
    
    cout << "本地日期和时间: " << dt << endl;
    
    // 把now转换为 tm 结构
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "UTC 日期和时间: " << dt << endl;
    
}



int main8()
{
    p8_func1();
    
    int a = 100;
    int b = 200;
    
    cout << "交换前, a的值:" << a << endl;
    cout << "交换前, b的值:" << b << endl;
    
    swap(a, b);
    
    cout << "交换后，a 的值：" << a << endl;
    cout << "交换后，b 的值：" << b << endl;
    
    cout << "改变前的值" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "vals[" << i << "] = ";
        cout << vals[i] << endl;
    }
    
    setValues(1) = 20.23;   // 改变第二个元素的值
    setValues(3) = 70.8;    // 改变第四个元素的值
    
    cout << "改变后的值" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "vals[" << i << "] = ";
        cout << vals[i] << endl;
    }
    
    p8_func3();
    return 0;
}


void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
