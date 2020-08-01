//
//  chapter4.cpp
//  CLPCode
//
//  Created by 陈俊 on 2020/2/16.
//  Copyright © 2020 陈俊. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

class Clock {
public:
    Clock(int newH,int newM, int newS);
    Clock();
    void setTime(int newH=0,int newM=0,int newS=0);
    void showTime();
private:
    int hour,minute,second;
};

Clock::Clock(int newH,int newM, int newS):hour(newH),minute(newM),second(newS) {
    
}

Clock::Clock():Clock(0,0,0){}


void Clock::setTime(int newH,int newM,int newS){
    hour = newH;
    minute = newM;
    second = newS;
}

void Clock::showTime() {
    cout << hour << ":" << minute << ":" << second << endl;
}

void test1(){
    Clock myClock;
    myClock.showTime();
}

class Point {
public:
    Point(int xx=0,int yy=0){ x = xx; y = yy;}
    Point(const Point &p);
    ~Point();
    int getX(){ return x;};
    int getY() { return y;}
private:
    int x,y;
};

Point::Point(const Point &p) {
    x = p.x;
    y = p.y;
    cout << "Calling the copy constructor of Point" << endl;
}

Point::~Point() {
}

class Line {
public:
    Line(Point xp1,Point xp2);
    Line(Line &l);
    double getLen() {
        return len;
    }
    
private:
    Point p1,p2;
    double len;
};

Line::Line(Point xp1,Point xp2):p1(xp1),p2(xp2) {
    cout << "Calling constructor of Line" << endl;
    double x = static_cast<int>(p1.getX() - p2.getX());
    double y = static_cast<int>(p1.getY() - p2.getY());
    
    len = sqrt(x*x + y*y);
};

Line::Line(Line &l):p1(l.p1),p2(l.p2) {
    cout << "Calling the copy constructor of Line" << endl;
    len = l.len;
}

void test2(){
    Point myp1(1,1),myp2(4,5);
    Line line(myp1,myp2);
    
    Line line2(line);
    
    cout << "The length of line is :";
    cout << line.getLen() << endl;

    cout << "The length of the line2 is: ";
    cout << line2.getLen() << endl;
}

struct Student{
    int num;
    string name;
    char sex;
    int age;
};

void test3()
{
    Student stu = {12032,"Lin Lin",'F',19};
    cout << "Num: " << stu.num << endl;
    cout << "Name: " << stu.name << endl;
    cout << "Sex: " << stu.sex << endl;
    cout << "Age: " << stu.age << endl;
}

class ExamInfo{
private:
    string name;
    enum {GRADE, PASS, PERCENTAGE} mode;
    union {
        char grade;
        bool pass;
        int percent;
    };
public:
    ExamInfo(string name,char grade):name(name),mode(GRADE),grade(grade){}
    ExamInfo(string name,bool pass):name(name),mode(PASS),pass(pass){}
    ExamInfo(string name,int percent):name(name),mode(PERCENTAGE),percent(percent) {}
    void show();
};

void ExamInfo::show(){
    cout << name << ": ";
    switch (mode) {
        case GRADE:
            cout << grade;
            break;
        case PASS:
            cout << (pass?"PASS":"FAIL") << ":";
            break;
        case PERCENTAGE:
            cout << percent;
            break;
        default:
            break;
    }
    cout << endl;
}

void test4()
{
    ExamInfo course1("English", 'B');
    ExamInfo course2("Calculus", true);
    ExamInfo course3("C++ Programming", 85);
    course1.show();
    course2.show();
    course3.show();
}


enum class Type: char { General, Light, Medium, Heavy};
enum class Category { General=1, Pistol, MachineGun, Cannon};
enum class Side {Right,Left};
enum class Thing{Wrong,Right};

void test5()
{
    Side s = Side::Right;
    Thing w = Thing::Wrong;
//    cout << (s == w) << endl; // //编译错误，无法直接比较不同枚举类
    
}

void test6()
{
    int year;
    bool isLeapYear;
    
    cout << "please input a year" << endl;
    cin >> year;
    
    isLeapYear = (year%4 == 0 && year%100 != 0) || (year%400 == 0);
    
    
    if (isLeapYear)
        cout << year << "is leap year" << endl;
    else
        cout << year << "is not leap year" << endl;
}

void test7()
{
    int x,y;
    cout << "Enter x & y"<< endl;
    cin >> x >> y;
    
    if (x != y)
        if (x > y)
            cout << "x > y" << endl;
        else
            cout << "x < y" << endl;
    else
        cout << "x = y" << endl;
}


void test8()
{
    int day;
    cout << "enter a day" << endl;
    cin >> day;
    switch (day) {
        case 0:
            cout << "Sunday" << endl;
            break;
        case 1:
            cout << "Monday" << endl;
            break;
        case 2:
            cout << "Tuesday" << endl;
            break;
        case 3:
            cout << "Wednesday" << endl;
            break;
        case 4:
            cout << "Thursday" << endl;
            break;
        case 5:
            cout << "Friday" << endl;
            break;
        case 6:
            cout << "Saturday" << endl;
            break;
            
        default:
            cout << "day out of range" << endl;
            break;
    }
}

void test9()
{
    int i = 1, sum = 0;
    
    while (i <= 10) {
        sum += i;
        i++;
    }
    
    cout << "sum = " << sum << endl;
}

void test10()
{
    int n, right_digit;
    cout << "Enter the number:";
    cin >> n;
    cout << "The number in reverse order is ";
    
    do{
        right_digit = n % 10;
        cout << right_digit;
        n /= 10;
        
    } while (n != 0);
    
    cout << endl;
}

void test11()
{
    int n;
    cout << "Enter a positive integer:";
    cin >> n;
    cout << "Number " << n << " Factors ";
    
    for (int k = 1; k <= n; k++) {
        if (n % k == 0)
            cout << k << " ";
    }
    cout << endl;
}

void test12()
{
    int i = 0, j = 0, n;
    cout << "Enter some integers please(enter 0 to quit);" << endl;
    cin >> n;
    
    while (n != 0) {
        if (n > 0) i++;
        if (n < 0) j++;
        cin >> n;
    }
    
    cout << "Counts of positive integers:" << i << endl;
    cout << "Count of negative integers:" << j << endl;
}

enum GameResult {WIN, LOSE,TIE, CANCEL};

void test13()
{
    GameResult result;
    enum GameResult omit = CANCEL;
    
    for (int count = WIN; count <= CANCEL; count++) {
        result = GameResult(count);
        if (result == omit)
            cout << "The game was canceled" << endl;
        else {
            cout << "The game was played ";
            if (result == WIN) cout << "and we won!";
            if (result == LOSE) cout << "and we lost.";
            cout << endl;
        }
    }
}


double power(double x, int n) {
    double val = 1.0;
    
    while(n--) val *= x;
    
    return val;
}

void test14()
{
    cout << "5 to the power 2 is " << power(5, 2) << endl;
}

void test15()
{
    int value = 0;
    cout << "Enter an 8 bit binary number ";
    for (int i =7; i >= 0; i--) {
        char ch;
        cin >> ch;
        if (ch == '1')
            value += static_cast<int>(power(2, i));
    }
    cout << "Decimal value is " << value << endl;
}

double arctan(double x) {
    double sqr = x*x;
    double e = x;
    double result = 0;
    
    int i = 1;
    
    while(e/i > 1e-15) {
        double f = e/i;
        result = (i % 4 == 1) ? result+f : result-f;
        e *= sqr;
        i+=2;
    }
    
    return result;
}


void test16()
{
    double a = 16 * arctan(1/5.0f);
    double b = 4 * arctan(1/239.0f);
    
    cout << "PI = " << a - b << endl;
}


// 判断一个数是否是回文
bool symm(unsigned n){
    unsigned i=n, m = 0;
    
    while (i > 0) {
        m = m*10 + i%10;
        i /= 10;
    }
    
    return n == m;
}

void test17()
{
    for (unsigned i=11; i<1000; i++) {
        if (symm(i) && symm(i*i) && symm(i*i*i)) {
            cout << "m=" << i << " m*m=" << i*i << " m*m*m=" << i*i*i << endl;
        }
    }
}


const double TINY_VALUE = 1e-10;

double tsin(double x)
{
    double g = 0;
    double t = x;
    int n = 1;
    do {
        g += t;
        n++;
        t = -t*x*x / (2*n - 1) / (2*n - 2);
    } while (fabs(t) >= TINY_VALUE);
    
    return g;
}

double tsin1(double x)
{
    double sqr = x*x;
    
    double t = x, r = 0.0f;
    int n = 1;
    
    while (t/n >= TINY_VALUE) {
        
        (n%4 == 1) ? r += t/n : r -= t/n;
        t *= sqr;
        n += 2;
        
    }
    
    return r;
}

const double PI = 3.14159;

inline double  calArea(double radius)
{
    return PI * radius * radius;
}

void test18()
{
    double r = 3.0;
    double area = calArea(r);
    cout << area << endl;
}



int CountDigit( int number, int digit )
{
    int num = 0;
    
    if(number < 0) number = -number;
    
    if(number == 0) {
        if(digit == 0) num++;
    }else {
        int n;
        while (number != 0){
            n = number % 10;
            if(digit == n) num++;
            number /= 10;
        }
    }
    
    return num;
    
}

int narcissistic( int number )
{
    int result = 0;
    int temp = number;
    int sum=0, n;

    // 求出数字位数
    int exponent = 0;
    while(temp != 0){
        temp /= 10;
        exponent++;
    }

    // 计算各位数字的N次方之和
    temp = number;
    while (temp != 0) {
        n = temp%10;
        sum += (int)pow(n,exponent);
        temp /= 10;
    }
    
    if (sum == number) result = 1;
    
    return result;
}
void PrintN( int m, int n )
{
    if (m < 100 || n > 10000 || m == n || m > n) return;
    for(int i=m+1; i<n; i++)
    {
        if (narcissistic(i)) printf("%d\n",i);
    }
}

double funcos( double e, double x )
{
    double t1=1,t2=1,t3=1,sum=1;
    int k = -1,n;
    for (n = 2; t1 > e; n+=2) {
        t2 = t2*x*x;
        t3 = t3*(n-1)*n;
        t1 = t2/t3;
        sum += k*t2/t3;
        k = -k;
    }
    
    return sum;
}



void test19()
{
    int fahr;
    float celsius;

    int lower,upper;
    scanf("%d %d",&lower,&upper);

    if(lower < 0 || lower > upper || upper > 100 ){
        printf("Invalid.");
        return;
    }

    printf("fahr celsius\n");

    for(int i=lower; i <= upper; i+=2){
        fahr = i;
        celsius = 5.0*(fahr - 32)/9;
        printf("%d %6.1f\n",fahr,celsius);
    }
}




int mainc4()
{
    int n;
    scanf("%d",&n);
    
    return 0;
}
