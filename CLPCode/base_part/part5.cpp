//
//  part5.cpp
//  CLPCode
//
//  Created by 陈俊 on 2019/12/31.
//  Copyright © 2019 陈俊. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

// 函数的定义
// 函数是一组一起执行一个任务的语句。每个 C++ 程序都至少有一个函数，即主函数 main() ，所有简单的程序都可以定义其他额外的函数。

// 函数的声明
// 函数声明会告诉编译器函数名称及如何调用函数。函数的实际主体可以单独定义。
// return_type function_name( parameter list );
// int max(int num1, int num2);
// int max(int, int);

// 函数参数
// 传值调用    该方法把参数的实际值复制给函数的形式参数。在这种情况下，修改函数内的形式参数对实际参数没有影响。
// 指针调用    该方法把参数的地址复制给形式参数。在函数内，该地址用于访问调用中要用到的实际参数。这意味着，修改形式参数会影响实际参数。
// 引用调用    该方法把参数的引用复制给形式参数。在函数内，该引用用于访问调用中要用到的实际参数。这意味着，修改形式参数会影响实际参数。


// 参数的默认值
// 当您定义一个函数，您可以为参数列表中后边的每一个参数指定默认值。
// 当调用函数时，如果实际参数的值留空，则使用这个默认值。
int sum(int a, int b=20)
{
  int result;
 
  result = a + b;
  
  return (result);
}

 

// 函数声明
int max(int num1, int num2);

 
int main5 ()
{
    // 局部变量声明
    int a = 100;
    int b = 200;
    int ret;
    
    // 调用函数来获取最大值
    ret = max(a, b);
    
    cout << "Max value is : " << ret << endl;
    
    // 局部变量声明
    int result;
    
    // 调用函数来添加值
    result = sum(a, b);
    cout << "Total value is :" << result << endl;
    
    // 再次调用函数
    result = sum(a);
    cout << "Total value is :" << result << endl;
    
    return 0;
}


// 函数返回两个数中较大的那个数
int max(int num1, int num2)
{
   // 局部变量声明
   int result;
 
   if (num1 > num2)
      result = num1;
   else
      result = num2;
 
   return result;
}


