//
//  part7.cpp
//  CLPCode
//
//  Created by 陈俊 on 2019/12/31.
//  Copyright © 2019 陈俊. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

// C++指针
// 指针是一个变量，其值为另一个变量的地址，即，内存位置的直接地址
// type *var-name;

void p7_fun1()
{
    int var1;
    char var2[10];
    
    cout << "var1 变量的地址: " << &var1 << endl;
    cout << "var2 变量的地址: " << &var2 << endl;
}

// 指针的定义
void p7_fun2()
{
//    int    *ip;    /* 一个整型的指针 */
//    double *dp;    /* 一个 double 型的指针 */
//    float  *fp;    /* 一个浮点型的指针 */
//    char   *ch;    /* 一个字符型的指针 */
}

// 指针的使用
void p7_fun3()
{
    int  var = 20;   // 实际变量的声明
    int  *ip;        // 指针变量的声明
    
    ip = &var;       // 在指针变量中存储 var 的地址
    
    cout << "Value of var variable: ";
    cout << var << endl;
    
    // 输出在指针变量中存储的地址
    cout << "Address stored in ip variable: ";
    cout << ip << endl;
    
    // 访问指针中地址的值
    cout << "Value of *ip variable: ";
    cout << *ip << endl;
}

// C++ NULL 指针
// 在变量声明的时候，如果没有确切的地址可以赋值，为指针变量赋一个 NULL 值是一个良好的编程习惯。
// 赋为 NULL 值的指针被称为空指针。NULL 指针是一个定义在标准库中的值为零的常量。
void p7_fun4()
{
    int *ptr = NULL;
    cout << "ptr 的值是 " << ptr << endl;
}

// NULL指针
void p7_fun5()
{
//    int a = 10;
    int *ptr = NULL;
    
    if (ptr) {
        cout << "ptr value is: " << ptr << endl;
    } else {
        cout << "ptr is null" << endl;
    }
}

// 指针的算术运算
// 指针是一个用数值表示的地址。因此，您可以对指针执行算术运算。可以对指针进行四种算术运算：++、--、+、-。
const int MAX = 3;

// 递增指针
void p7_fun6()
{
    int var[MAX] = {10,100,200};
    int *ptr;
    
    ptr = var;
    
    cout << "sizeof(int)=" << sizeof(int) << endl;
    for (int i = 0; i < MAX; i++) {
        cout << "Address of var [" << i << "] = ";
        cout << ptr << endl;
        
        cout << "Value of var[" << i << "] = ";
        cout << *ptr << endl;
        
        // 移动到下一个位置
        ptr++;
    }
}

// 递减指针
void p7_fun7()
{
    int var[MAX] = {10,100,200};
    int *ptr;
    
    ptr = &var[MAX - 1];
    for (int i = MAX - 1; i >= 0; i--) {
        cout << "Address of var [" << i << "] = ";
        cout << ptr << endl;
        
        cout << "Value of var[" << i << "] = ";
        cout << *ptr << endl;
        
        // 移动到下一个位置
        ptr--;
    }
}

// 指针比较
void p7_fun8()
{
    int  var[MAX] = {10, 100, 200};
    int  *ptr;
    
    ptr = var; // ptr指针指向数组的起始地址.
    int i = 0;
    while ( ptr <= &var[MAX - 1] )
    {
        // 打印元素i的地址
        cout << "Address of var[" << i << "] = ";
        cout << ptr << endl;
        
        // 打印元素i的值
        cout << "Value of var[" << i << "] = ";
        cout << *ptr << endl;
        
        // 指针指向下一个位置.
        ptr++;
        i++;
    }
}

// 指针 vs 数组
// 指针和数组在很多情况下是可以互换的。例如，一个指向数组开头的指针，可以通过使用指针的算术运算或数组索引来访问数组。
void p7_fun9()
{
      int  var[MAX] = {10, 100, 200};
      int  *ptr;
    
      // 指针中的数组地址
      ptr = var;
      for (int i = 0; i < MAX; i++)
      {
         cout << "var[" << i << "]的内存地址为 ";
         cout << ptr << endl;
    
         cout << "var[" << i << "] 的值为 ";
         cout << *ptr << endl;
    
         // 移动到下一个位置
         ptr++;
      }
    
    // 然而，指针和数组并不是完全互换的
    // 把指针运算符 * 应用到 var 上是完全可以的，但修改 var 的值是非法的。这是因为 var 是一个指向数组开头的常量，不能作为左值。
    for (int i = 0; i < MAX; i++)
    {
       *var = i;    // 这是正确的语法
//       var++;       // 这是不正确的
    }
    
    // 由于一个数组名对应一个指针常量，只要不改变数组的值，仍然可以用指针形式的表达式。例如，下面是一个有效的语句，把 var[2] 赋值为 500
    *(var + 2) = 500;
}

// C++指针数组
void p7_fun10()
{
    int var[MAX] = {10,100,200};
    // 下面是一个指向整数的指针数组的声明：
    int *ptr[MAX];
    
    for (int i = 0; i < MAX; i++) {
        ptr[i] = &var[i]; // 赋值为整数的地址
    }
    
    for (int i = 0; i < MAX; i++) {
        cout << "Value of ptr[" << i << "] = ";
        cout << ptr[i] << endl;
    }
    
    cout << "\n";
    
    // 用一个指向字符的指针数组来存储一个字符串列表
    const char *names[MAX] = {"Zara Ali", "Hina Ali", "Nuha Ali",};
    for (int i = 0; i < MAX; i++) {
        cout << "Value of names[" << i << "] = ";
        cout << names[i] << endl;
    }
    
    cout << "\n";
    cout << "names = " << names << endl;                // 凡是数组的名称都是一个指针常量
    cout << "names + 1 =" << names + 1 << endl;         // 数组名算术运算后的结果仍是地址
    cout << "*(names + 1) = " << *(names + 1) << endl;  // *(地址) 运算后的结果是地址所指向的内容
    cout << "&names[1] = " << &names[1] << endl;        //  & 是取址操作.
    cout << "names[1] = " << names[1] << endl;          // 如果是字符串的地址, 直接会打印字符串, 字符串 即 字符数组.
    
}

// C++ 指向指针的指针 (多级间接寻址)
// 通常，一个指针包含一个变量的地址。当我们定义一个指向指针的指针时，第一个指针包含了第二个指针的地址，第二个指针指向包含实际值的位置。
void p7_fun11()
{
    // 一个指向指针的指针变量必须如下声明，即在变量名前放置两个星号。
    int **p = NULL;
    
    int var;
    int *ptr;
    int **pptr;
    
    var = 3000;
    
    // 获取var的地址
    ptr = &var;
    
    // 获取ptr的地址
    pptr = &ptr;
    
    // 使用pptr 获取值
    cout << "var 值为 :" << var << endl;
    cout << "*ptr 值为 :" << *ptr << endl;
    cout << "**pptr 值为 :" << **pptr << endl;
    
    cout << "ptr的值为 :" << ptr << endl;
    cout << "*pptr的值为 :" << *pptr << endl;
    cout << "pptr的值为 :" << pptr << endl;
    
}

// C++传递指针给函数
void getSeconds(unsigned long *par);
// 能接受指针作为参数的函数，也能接受数组作为参数，
double getAverage(int *arr, int size);

// C++从函数返回指针
// 需要声明一个返回指针的函数 int * myFunction(){};
int * getRandom()
{
    // C++ 不支持在函数外返回局部变量的地址，除非定义局部变量为 static 变量。
    static int r[10];
    
    srand((unsigned)time(NULL));    // 设置种子
    for (int i = 0; i < 10; ++i) {
        r[i] = rand();
        cout << r[i] << endl;
    }
    
    return r;
}



int main7()
{
    p7_fun11();
    
    // 传递指针参数, 输出秒数.
    unsigned long sec;
    getSeconds(&sec);
    cout << "Number of seconds :" << sec << endl;
    
    // 带有5个元素的整型数组
    int balance[5] = {1000, 2, 3, 17, 50};
    double avg;
    
    // 传递一个指向数组的指针作为参数
    avg = getAverage(balance, 5);;
    
    // 输出返回值
    cout << "Average value is: " << avg << endl;
    cout << endl;
    
    int *p;
    p = getRandom();
    for (int i = 0; i < 10; i++) {
        cout << "*(p + " << i << ") : ";
        cout << *(p + i) << endl;
    }
    
    return 0;
}

void getSeconds(unsigned long *par)
{
    *par = time(NULL);
}

double getAverage(int *arr, int size)
{
    int sum = 0;
    double avg;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    avg = (double)sum / size;
    
    return avg;
}
