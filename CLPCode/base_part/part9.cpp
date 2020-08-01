//
//  part9.cpp
//  CLPCode
//
//  Created by 陈俊 on 2020/1/2.
//  Copyright © 2020 陈俊. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

// 1. C++ 基本的输入输出
// 如果字节流是从设备（如键盘、磁盘驱动器、网络连接等）流向内存，这叫做输入操作。
// 如果字节流是从内存流向设备（如显示屏、打印机、磁盘驱动器、网络连接等），这叫做输出操作。

// I/O库头文件
// <iostream>    该文件定义了 cin、cout、cerr 和 clog 对象，分别对应于标准输入流、标准输出流、非缓冲标准错误流和缓冲标准错误流。
// <iomanip>    该文件通过所谓的参数化的流操纵器（比如 setw 和 setprecision），来声明对执行标准化 I/O 有用的服务。
// <fstream>    该文件为用户控制的文件处理声明服务。我们将在文件和流的相关章节讨论它的细节。

// 标准输出流 cout
void p9_func0()
{
    char str[] = "Hello C++";
    cout << "Value of str is : " << str << endl;
}

// 标准输出流 cin
void p9_func1()
{
    char name[50];
    
    cout << "请输入您的名称： ";
    cin >> name;
    cout << "您的名称是： " << name << endl;
}

// 标准错误输出流 cerr
void p9_func2()
{
    char str[] = "Unable to read....";
    
    cerr << "Error message : " << str << endl;
}

// 标准日志流 clog
void p9_func3()
{
    char str[] = "Unable to read....";
    
    clog << "Error message : " << str << endl;
}

// 2. C++ 数据结构
// 结构是 C++ 中另一种用户自定义的可用的数据类型，它允许您存储不同类型的数据项。 结构用于表示一条记录.

// 定义结构
/*
 struct type_name {
 member_type1 member_name1;
 member_type2 member_name2;
 member_type3 member_name3;
 .
 .
 } object_names;
 */
struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book;

void p9_func4()
{
    Books Book1;        // 定义结构体类型 Books 的变量 Book1
    Books Book2;        // 定义结构体类型 Books 的变量 Book2
    
    // Book1 详述
    strcpy( Book1.title, "C++ 教程");
    strcpy( Book1.author, "Runoob");
    strcpy( Book1.subject, "编程语言");
    Book1.book_id = 12345;
    
    // Book2 详述
    strcpy( Book2.title, "CSS 教程");
    strcpy( Book2.author, "Runoob");
    strcpy( Book2.subject, "前端技术");
    Book2.book_id = 12346;
    
    // 输出 Book1 信息
    cout << "第一本书标题 : " << Book1.title <<endl;
    cout << "第一本书作者 : " << Book1.author <<endl;
    cout << "第一本书类目 : " << Book1.subject <<endl;
    cout << "第一本书 ID : " << Book1.book_id <<endl;
    
    // 输出 Book2 信息
    cout << "第二本书标题 : " << Book2.title <<endl;
    cout << "第二本书作者 : " << Book2.author <<endl;
    cout << "第二本书类目 : " << Book2.subject <<endl;
    cout << "第二本书 ID : " << Book2.book_id <<endl;
}

// 结构作为函数参数
// 该函数以结构指针作为参数
void printBook( struct Books *book )
{
   cout << "书标题  : " << book->title <<endl;
   cout << "书作者 : " << book->author <<endl;
   cout << "书类目 : " << book->subject <<endl;
   cout << "书 ID : " << book->book_id <<endl;
}
void p9_func5()
{
    Books Book1;
    
    // Book1 详述
    strcpy( Book1.title, "C++ 教程");
    strcpy( Book1.author, "Runoob");
    strcpy( Book1.subject, "编程语言");
    Book1.book_id = 12345;
    
    // 通过传 Book1 的地址来输出 Book1 信息
    printBook( &Book1 );
}

// 使用typedef关键字给结构体取别名
typedef struct Book
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
}Book;

Book book1,book2;
// 也可以使用 typedef 关键字来定义非结构类型
typedef long int *pint32;
pint32 x, y, z; // x, y 和 z 都是指向长整型 long int 的指针。



int main9()
{
    p9_func5();
    return 0;
}
