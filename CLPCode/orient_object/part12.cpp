//
//  part12.cpp
//  CLPCode
//
//  Created by 陈俊 on 2020/1/4.
//  Copyright © 2020 陈俊. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "string.h"

using namespace std;

// C++ 文件和流

// 本教程介绍如何从文件读取流和向文件写入流。这就需要用到 C++ 中另一个标准库 fstream，它定义了三个新的数据类型：
// ofstream    该数据类型表示输出文件流，用于创建文件并向文件写入信息。
// ifstream    该数据类型表示输入文件流，用于从文件读取信息。
// fstream    该数据类型通常表示文件流，且同时具有 ofstream 和 ifstream 两种功能，这意味着它可以创建文件，向文件写入信息，从文件读取信息。
// 要在 C++ 中进行文件处理，必须在 C++ 源代码文件中包含头文件 <iostream> 和 <fstream>。

// 打开文件
// 在从文件读取信息或者向文件写入信息之前，必须先打开文件。ofstream 和 fstream 对象都可以用来打开文件进行写操作，如果只需要打开文件进行读操作，则使用 ifstream 对象。
// 下面是 open() 函数的标准语法，open() 函数是 fstream、ifstream 和 ofstream 对象的一个成员。
// void open(const char *filename, ios::openmode mode);
// open() 成员函数的第一参数指定要打开的文件的名称和位置，第二个参数定义文件被打开的模式。
// ios::app    追加模式。所有写入都追加到文件末尾。
// ios::ate    文件打开后定位到文件末尾。
// ios::in    打开文件用于读取。
// ios::out    打开文件用于写入。
// ios::trunc    如果该文件已经存在，其内容将在打开文件之前被截断，即把文件长度设为 0。

void p12_func0()
{
    // 以写入模式打开文件，并希望截断文件，以防文件已存在，
    ofstream outfile;
    outfile.open("file.dat", ios::out | ios::trunc);
    
    // 打开一个文件用于读写
    ifstream afile;
    afile.open("file.dat", ios::out | ios::in);
    
    // 关闭文件
    // close() 函数是 fstream、ifstream 和 ofstream 对象的一个成员。 用于关闭文件
    outfile.close();
    afile.close();
    
}

// /Users/chenjun/XcodeProjects/files
// 读写文件示例
void p12_func1()
{
    char data[100];
    
    // 写文件
    // 以写模式打开文件
    ofstream outfile;
    outfile.open("/Users/chenjun/XcodeProjects/files/afile.dat");
    
    cout << "Writing to the file" << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);
    
    // 向文件写入用户输入的数据
    outfile << data << endl;
    
    cout << "Enter you age: ";
    cin >> data;
    cin.ignore();
    
    // 再次向文件写入用户输入的数据
    outfile << data << endl;
    
    // 关闭打开的文件
    outfile.close();
    
    // 读文件
    // 以读模式打开文件
    ifstream infile;
    infile.open("/Users/chenjun/XcodeProjects/files/afile.dat");
    
    cout << "Reading from the file" << endl;
    infile >> data;
    
    // 在屏幕上写入数据
    cout << data << endl;
    
    // 再次从文件读取数据, 并显示它
    infile >> data;
    cout << data << endl;
    
    // 关闭打开的文件
    infile.close();
    
}

void p12_func2()
{
    char data[80];
    
    // 写文件
    fstream outfile;
    outfile.open("/Users/chenjun/XcodeProjects/files/afile.dat");
    
    cout << "请输入你的姓名:";
    cin.getline(data, 80);
    outfile << data << endl;
    
    cout << "请输入年龄:";
    cin >> data;
    cin.ignore();
    
    outfile << data << endl;
    
    outfile.close();
    
    
    // 读文件
    fstream infile;
    infile.open("/Users/chenjun/XcodeProjects/files/afile.dat");
    
    infile >> data;
    
    // 打印到屏幕上
    cout << data << endl;
    
    // 再次读文件打印到屏幕上
    infile >> data;
    cout << data << endl;
    
}


void p12_func3()
{
    int s;
    double pi, a;
    for (s = 1, a = 1, pi = 0.0f; ; a = a+2) {
        pi = pi + s/a;
        s = -s;
        if (1/a < 1e-6) break;
    }
    
    pi = pi * 4;
    
    cout << "pi = " << pi << endl;
}

#define Student 1

void p12_func4()
{
    
#ifdef Student
    
#if (Student)
    printf("  处理小学生信息...\n");
#else
    printf(" 处理大学生信息...\n");
#endif
    
#else
    
    printf(" 处理教师信息...\n");
    
#endif
}

void p12_func5()
{
//    char a[20];
    cout<< "请输入字符串" << endl;
//    scanf("%s",a);
//    printf("%s\n",a); puts(a);
    
//    getchar();
//    gets(a);
//    printf("\n\n%s\n",a); puts(a);
//    getchar();
    
    char a[10], b[10], c[10],d[10];
    scanf("%s%s%s%s",a,b,c,d);
    
    printf("%s\n",a);
    printf("%s\n",b);
    printf("%s\n",c);
    printf("%s\n",d);
    
}

void p12_func6()
{
    char a[10] = {"abcdefghi"}, b[5];
    printf("a: %s\nb: %s\n",a,b);
    strcpy(b,a);
    printf("a: %s\nb: %s  l=%d\n",a,b,strlen(b));
    printf("b[4] = %c b[5]=%c  b[8]=%c\n",b[4],b[5],b[8]);
    getchar();
}


int fib(int n);

void p12_func7()
{
    int n, answer;
    cout << "Enter number:";
    cin >> n;
    cout <<"\n\n";
    answer = fib(n);
    cout << answer << " is the :" << n << " fibnocci number \n";
}

int fib(int n)
{
    
//    cout << "processing fib (" << n << ")...\n";
    if (n < 3) {
//        cout << "Return 1!\n";
        return 1;
    }else {
         return fib(n-1) + fib(n-2);
    }
    
}

//class Clock{
//
//public:
//    Clock();
//    Clock(int newH,int newM, int newS);
//
//    void setTime(int newH = 0, int newM = 0, int newS = 0);
//    void showTime();
//
//private:
//    int hour, minute, second;
//};
//
//Clock::Clock(int newH,int newM, int newS): hour(newH), minute(newM), second(newS) {}
//
//Clock::Clock():Clock(0,0,0){};
//
//void Clock::setTime(int newH, int newM, int newS)
//{
//    hour = newH;
//    minute = newM;
//    second = newS;
//}
//
//void Clock::showTime(){
//    cout << hour <<":" << minute << ":" << second << endl;
//}
//
//
//void p12_func8()
//{
//    Clock c1(8,10,0);
//    Clock c2;
////    myClock.setTime(8,30,29);
//    c1.showTime();
//    c2.showTime();
//}

enum CPU_Rank {P1=1,P2,P3,P4,P5,P6,P7};

class CPU {
private:
    enum CPU_Rank rank;
    int frequency;
    float voltage;
public:
    CPU(enum CPU_Rank r, int f, float v){
        rank = r;
        frequency = f;
        voltage = v;
        cout << "构造了一个CPU!" << endl;
    }
    
    ~CPU() { cout << "析构了一个CPU" << endl;}
    
    enum CPU_Rank GetRank() const { return rank;}
    int GetFrequency() const { return frequency;}
    float GetVoltage() const { return voltage;}
    
    void SetRank(enum CPU_Rank r) { rank = r;}
    void SetFrequency(int f) { frequency = f;}
    void SetVoltage(float v) { voltage = v;}
    
    void Run() { cout << "CPU开始运行!" << endl;}
    void Stop() { cout << "CPU停止运行!" << endl;}
};

enum RAM_Type {DDR2=2, DDR3, DDR4};


class RAM {
private:
    enum RAM_Type type;
    unsigned int size;
    unsigned int frequency;
public:
    RAM(int s, enum RAM_Type t, int f):size(s),type(t),frequency(f) {}
    
};

enum CDROM_INTERFACE {SATA=1,USB};
enum CDROM_INSTALL {EXTERNAL=1, BUILT_IN};
class CDROM {
private:
    enum CDROM_INTERFACE interface;
    int capacity;
    enum CDROM_INSTALL install;
public:
    CDROM(enum CDROM_INTERFACE ife, int c, enum CDROM_INSTALL isl) {
        interface = ife;
        capacity = c;
        install = isl;
    }
};

void p12_func9()
{
    CPU c(P6,1000,220.0f);
    c.Run();
    c.Stop();
}

void p12_func10()
{
    int a,b,c,d,e,f,g,h;
    
    a = 2;
    b = 0;
    
    for (c=2; c<=9; c++) {
        for (d = 0; d <= 9; d++) {
            for (int i = 1; i <= 12; i++)
            {
                for (int j = 1; j <= 31; j++)
                {
                    e = i / 10;
                    f = i % 10;
                    g = j / 10;
                    h = j % 10;
                    if (d==e && c==f && b==g && a==h) printf("%d%d%d%d%d%d%d%d\n",a,b,c,d,e,f,g,h);
                }
            }
        }
    }

    
}

void F() {

char str[7] = { 'p', 'r', 'o', 'g', 'r', 'a', 'm'};

std::cout << str << std::endl;

}

void p12_func11()
{
    const char key[] = {'a','c','b','a','d'};
    const int NUM_QUES = 5;
    char c;
    
    int ques = 0,  numCorrect = 0;
    cout << "Enter the " << NUM_QUES << " question tests:" << endl;
    while (cin.get(c)) {
        if( c != '\n') {
            if(c == key[ques]){
                numCorrect++; cout << "~";
            }else{
                cout << "*";
            }
            ques++;
        }else{
            cout << " Score " << static_cast<float>(numCorrect)/NUM_QUES * 100 << "%";
            ques = 0; numCorrect = 0; cout << endl;
        }
    }
}

void p12_func12()
{
    FILE *fp;
    char string[100];
    int i=0;
    
    // 打开文件
    if((fp = fopen("/Users/chenjun/Work/prac/test12.txt", "w")) == NULL){
        printf("cannot open file!\n");
        exit(1);
    }
    
    
    // 输入字符串
    printf("input a string:\n");
    gets(string);
    
    // 把字符串输入到文件
    while (string[i] != '!') {
        if(string[i] >= 'a' && string[i] <= 'z')
            string[i] = string[i] - 32;
        putc(string[i], fp);
        i++;
    }
    
    // 关闭文件
    fclose(fp); 
}


int main_part12()
{
    p12_func12();
//    F();
    return 0;
}
