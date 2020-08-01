//
//  part10.cpp
//  CLPCode
//
//  Created by 陈俊 on 2020/1/2.
//  Copyright © 2020 陈俊. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

// 类的定义
class Box
{
public:
    double length;  // 盒子的长度
    double breadth; // 盒子的宽度
    double height;  // 盒子的高度
    
    // 成员函数声明
    double getVolume(void);
    void setLength( double len );
    void setBreadth( double bre );
    void setHeight( double hei );
};

double Box::getVolume()
{
    return length * breadth * height;
}

void Box::setLength(double len)
{
    length = len;
}

void Box::setBreadth( double bre )
{
    breadth = bre;
}
 
void Box::setHeight( double hei )
{
    height = hei;
}

void p10_func1()
{
    Box Box1;        // 声明 Box1，类型为 Box
    Box Box2;        // 声明 Box2，类型为 Box
    double volume = 0.0;     // 用于存储体积
    
    Box1.length = 5.0;
    Box1.breadth = 6.0;
    Box1.height = 7.0;
    
    Box2.length = 10.0;
    Box2.breadth = 12.0;
    Box2.height = 13.0;
    
    // box 1 的体积
    volume = Box1.height * Box1.breadth * Box1.height;
    cout << "Box1 的体积:" << volume << endl;
    
    // box 2 的体积
    volume = Box2.length * Box2.breadth * Box2.height;
    cout << "Box2 的体积:" << volume << endl;
}

void p10_func2()
{
    Box Box1;                // 声明 Box1，类型为 Box
    Box Box2;                // 声明 Box2，类型为 Box
    double volume = 0.0;     // 用于存储体积
    
    // box 1 详述
    Box1.setLength(6.0);
    Box1.setBreadth(7.0);
    Box1.setHeight(5.0);
    
    // box 2 详述
    Box2.setLength(12.0);
    Box2.setBreadth(13.0);
    Box2.setHeight(10.0);
    
    // box 1 的体积
    volume = Box1.getVolume();
    cout << "Box1 的体积：" << volume <<endl;
    
    // box 2 的体积
    volume = Box2.getVolume();
    cout << "Box2 的体积：" << volume <<endl;
}

// C++类访问修饰符
// 数据封装是面向对象编程的一个重要特点，它防止函数直接访问类类型的内部成员。
// 类成员的访问限制是通过在类主体内部对各个区域标记 public、private、protected 来指定的。关键字 public、private、protected 称为访问修饰符。
// 一个类可以有多个 public、protected 或 private 标记区域。每个标记区域在下一个标记区域开始之前或者在遇到类主体结束右括号之前都是有效的。


// 公有成员 public
// 公有成员在程序中类的外部是可访问的。您可以不使用任何成员函数来设置和获取公有变量的值，
class Line
{
   public:
      double length;
      void setLength( double len );
      double getLength( void );
};

// 成员函数定义
double Line::getLength()
{
    return length;
}

void Line::setLength(double len)
{
    length = len;
}

void p10_func3()
{
    Line line;
    
    // 设置长度
    line.setLength(6.0);
    cout << "length of line : " << line.getLength() << endl;
    
    line.length = 10.0; // 因为length是公有的
    cout << "length of lien : " << line.length << endl;
}

// 私有成员 private
// 私有成员变量或函数在类的外部是不可访问的，甚至是不可查看的。只有类和友元函数可以访问私有成员。 默认情况下，类的所有成员都是私有的。
class Box2
{
public:
    double length;
    void setWidth(double wid);
    double getWidth(void);
    
private:
    double width;   // 私有成员
};

void Box2::setWidth(double wid)
{
    width = wid;
}

double Box2::getWidth()
{
    return width;
}

void p10_func4()
{
    Box2 box;
    
    // 不使用成员函数设置长度
    box.length = 10.0; // OK: 因为 length 是公有的
    cout << "Length of box : " << box.length <<endl;
    
    // 不使用成员函数设置宽度
    // box.width = 10.0; // Error: 因为 width 是私有的
    box.setWidth(10.0);  // 使用成员函数设置宽度
    cout << "Width of box : " << box.getWidth() <<endl;
}

// 保护成员 protected
// 保护成员变量或函数与私有成员十分相似，但有一点不同，保护成员在派生类（即子类）中是可访问的。
class Box3
{
   protected:
      double width;
};
 
class SmallBox:Box3 // SmallBox 是派生类
{
   public:
      void setSmallWidth( double wid );
      double getSmallWidth( void );
};

// 子类的成员函数
double SmallBox::getSmallWidth(void)
{
    return width ;
}
 
void SmallBox::setSmallWidth( double wid )
{
    width = wid;
}

void p10_func5()
{
    SmallBox box;
    
    // 使用成员函数设置宽度
    box.setSmallWidth(5.0);
    cout << "Width of box : "<< box.getSmallWidth() << endl;
}

// 继承中的特点:
// 有public, protected, private三种继承方式，它们相应地改变了基类成员的访问属性。
// 1.public 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：public, protected, private
// 2.protected 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：protected, protected, private
// 3.private 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：private, private, private
// 但无论哪种继承方式，上面两点都没有改变：
// 1.private 成员只能被本类成员（类内）和友元访问，不能被派生类访问；
// 2.protected 成员可以被派生类访问。
class A{
public:
  int a;
  A(){
    a1 = 1;
    a2 = 2;
    a3 = 3;
    a = 4;
  }
  void fun(){
    cout << a << endl;    //正确
    cout << a1 << endl;   //正确
    cout << a2 << endl;   //正确
    cout << a3 << endl;   //正确
  }
public:
  int a1;
protected:
  int a2;
private:
  int a3;
};

// public继承
class B : public A{
public:
  int a;
  B(int i){
    A();
    a = i;
  }
  void fun(){
    cout << a << endl;       //正确，public成员
    cout << a1 << endl;       //正确，基类的public成员，在派生类中仍是public成员。
    cout << a2 << endl;       //正确，基类的protected成员，在派生类中仍是protected可以被派生类访问。
//    cout << a3 << endl;       //错误，基类的private成员不能被派生类访问。
  }
};

void p10_func6()
{
    B b(10);
    cout << b.a << endl;
    cout << b.a1 << endl;   //正确
//    cout << b.a2 << endl;   //错误，类外不能访问protected成员
//    cout << b.a3 << endl;   //错误，类外不能访问private成员
    system("pause");
}

class C : protected A{
public:
  int a;
  C(int i){
    A();
    a = i;
  }
  void fun(){
    cout << a << endl;       //正确，public成员。
    cout << a1 << endl;       //正确，基类的public成员，在派生类中变成了protected，可以被派生类访问。
    cout << a2 << endl;       //正确，基类的protected成员，在派生类中还是protected，可以被派生类访问。
//    cout << a3 << endl;       //错误，基类的private成员不能被派生类访问。
  }
};

void p10_func7()
{
    C c(10);
    cout << c.a << endl;       //正确。public成员
//    cout << c.a1 << endl;      //错误，protected成员不能在类外访问。
//    cout << c.a2 << endl;      //错误，protected成员不能在类外访问。
//    cout << c.a3 << endl;      //错误，private成员不能在类外访问。
    system("pause");
}

// private继承
class D : private A{
public:
  int a;
  D (int i){
    A();
    a = i;
  }
  void fun(){
    cout << a << endl;       //正确，public成员。
    cout << a1 << endl;       //正确，基类public成员,在派生类中变成了private,可以被派生类访问。
    cout << a2 << endl;       //正确，基类的protected成员，在派生类中变成了private,可以被派生类访问。
//    cout << a3 << endl;       //错误，基类的private成员不能被派生类访问。
  }
};

void p10_func8()
{
    D d(10);
    cout << d.a << endl;       //正确。public成员
//    cout << d.a1 << endl;      //错误，private成员不能在类外访问。
//    cout << d.a2 << endl;      //错误, private成员不能在类外访问。
//    cout << d.a3 << endl;      //错误，private成员不能在类外访问。
    system("pause");
}

// 构造函数 & 析构函数
// 类的构造函数是一种特殊的函数，在创建一个新的对象时调用。类的析构函数也是一种特殊的函数，在删除所创建的对象时调用。

// 类的构造函数
// 类的构造函数是类的一种特殊的成员函数，它会在每次创建类的新对象时执行。
// 构造函数的名称与类的名称是完全相同的，并且不会返回任何类型，也不会返回 void。构造函数可用于为某些成员变量设置初始值。
class Line2
{
public:
    void setLength( double len );
    double getLength( void );
    Line2();  // 这是不带参的构造函数
    Line2(double len);
    
private:
    double length;
};

// 成员函数定义，包括构造函数
Line2::Line2(void)
{
    cout << "Object is being created" << endl;
}

Line2::Line2(double len)
{
    length = len;
    cout << "Object is being created length is : " << len << endl;
}

// 使用初始化列表来初始化字段, 语法等同于上个.
//Line2::Line2(double len):length(len)
//{
//    cout << "Object is being created, length is : " << len << endl;
//}
 
void Line2::setLength( double len )
{
    length = len;
}
 
double Line2::getLength( void )
{
    return length;
}

void p10_func9()
{
    Line2 line2;
    line2.setLength(10.0);
    cout << "Length of line2 : " << line2.getLength() << endl;
    
    Line2 line22(12.0);
}


// 类的析构函数
// 类的析构函数是类的一种特殊的成员函数，它会在每次删除所创建的对象时执行。
// 析构函数的名称与类的名称是完全相同的，只是在前面加了个波浪号（~）作为前缀，它不会返回任何值，也不能带有任何参数。
// 析构函数有助于在跳出程序（比如关闭文件、释放内存等）前释放资源。
class Line22
{
   public:
      void setLength( double len );
      double getLength( void );
      Line22();   // 这是构造函数声明
      ~Line22();  // 这是析构函数声明
 
   private:
      double length;
};

// 成员函数定义，包括构造函数
Line22::Line22(void)
{
    cout << "Object is being created" << endl;
}
Line22::~Line22(void)
{
    cout << "Object is being deleted" << endl;
}
 
void Line22::setLength( double len )
{
    length = len;
}
 
double Line22::getLength( void )
{
    return length;
}

void p10_func10()
{
    Line22 line22;
    line22.setLength(5.0);
    cout << "Length of line22 : " << line22.getLength() <<endl;
}

// C++ 拷贝构造函数
// 拷贝构造函数是一种特殊的构造函数，它在创建对象时，是使用同一类中之前创建的对象来初始化新创建的对象。
// 拷贝构造函数通常用于：
// 通过使用另一个同类型的对象来初始化新创建的对象。
// 复制对象把它作为参数传递给函数。
// 复制对象，并从函数返回这个对象。

// 如果在类中没有定义拷贝构造函数，编译器会自行定义一个。如果类带有指针变量，并有动态内存分配，则它必须有一个拷贝构造函数。 拷贝构造函数的最常见形式如下：
// classname (const classname &obj) {// 构造函数的主体 obj 是一个对象引用，该对象是用于初始化另一个对象的。 }

class Line3
{
   public:
      int getLength( void );
      Line3( int len );             // 简单的构造函数
      Line3( const Line3 &obj);      // 拷贝构造函数
      ~Line3();                     // 析构函数
 
   private:
      int *ptr;
};

 
// 成员函数定义，包括构造函数
Line3::Line3(int len)
{
    cout << "调用构造函数" << endl;
    // 为指针分配内存
    ptr = new int;
    *ptr = len;
}
 
Line3::Line3(const Line3 &obj)
{
    cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
    ptr = new int;
    *ptr = *obj.ptr; // 拷贝值
}
 
Line3::~Line3(void)
{
    cout << "释放内存" << endl;
    delete ptr;
}
int Line3::getLength( void )
{
    return *ptr;
}

// 复制对象, 把它作为参数传递给函数.
void display(Line3 obj)
{
   cout << "line 大小 : " << obj.getLength() <<endl;
}

void p10_func11()
{
    Line3 line1(10);
    
    Line3 line2 = line1;    // 调用拷贝函数
    
    cout << "开始display" << endl;
    
    display(line1);
    display(line2);
}

// C++ 友元函数
// 友元函数可以访问类的 private 和 protected 成员。
// 类的友元函数是定义在类外部，但有权访问类的所有私有（private）成员和保护（protected）成员。尽管友元函数的原型有在类的定义中出现过，但是友元函数并不是成员函数。
// 友元可以是一个函数，该函数被称为友元函数；友元也可以是一个类，该类被称为友元类，在这种情况下，整个类及其所有成员都是友元。
// 如果要声明函数为一个类的友元，需要在类定义中该函数原型前使用关键字 friend.
class Box4
{
   double width;
public:
   friend void printWidth( Box3 box );
   void setWidth( double wid );
};
 
// 成员函数定义
void Box4::setWidth( double wid )
{
    width = wid;
}
 
// 请注意：printWidth() 不是任何类的成员函数
void printWidth( Box4 box )
{
   /* 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员 */
//   cout << "Width of box : " << box.width <<endl;
}

// C++ 内联函数
// C++ 内联函数是通常与类一起使用
// 如果一个函数是内联的，那么在编译时，编译器会把该函数的代码副本放置在每个调用该函数的地方。
// 对内联函数进行任何修改，都需要重新编译函数的所有客户端，因为编译器需要重新更换一次所有的代码，否则将会继续使用旧的函数。
// 如果想把一个函数定义为内联函数，则需要在函数名前面放置关键字 inline，在调用函数之前需要对函数进行定义。

inline int Max(int x, int y)
{
   return (x > y)? x : y;
}

// C++ this指针
// 每个对象都有一个特殊的指针 this，它指向对象本身。
// 在 C++ 中，每一个对象都能通过 this 指针来访问自己的地址。this 指针是所有成员函数的隐含参数。
// 因此，在成员函数内部，它可以用来指向调用对象。
class Box5
{
   public:
      // 构造函数定义
      Box5(double l=2.0, double b=2.0, double h=2.0)
      {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;
      }
      double Volume()
      {
         return length * breadth * height;
      }
      int compare(Box5 box)
      {
         return this->Volume() > box.Volume();
      }
   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};

void p10_func12()
{
    Box5 Box1(3.3, 1.2, 1.5);    // Declare box1
    Box5 Box2(8.5, 6.0, 2.0);    // Declare box2
    
    if(Box1.compare(Box2))
    {
        cout << "Box2 is smaller than Box1" <<endl;
    }
    else
    {
        cout << "Box2 is equal to or larger than Box1" <<endl;
    }
}

// C++ 中指向类的指针
// 指向类的指针方式如同指向结构的指针。实际上，类可以看成是一个带有函数的结构。
// 一个指向 C++ 类的指针与指向结构的指针类似，访问指向类的指针的成员，需要使用成员访问运算符 ->，就像访问指向结构的指针一样。
// 与所有的指针一样，您必须在使用指针之前，对指针进行初始化。
class Box6
{
   public:
      // 构造函数定义
      Box6(double l=2.0, double b=2.0, double h=2.0)
      {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;
      }
      double Volume()
      {
         return length * breadth * height;
      }
   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};

void p10_func13()
{
    Box6 Box1(3.3, 1.2, 1.5);    // Declare box1
    Box6 Box2(8.5, 6.0, 2.0);    // Declare box2
    Box6 *ptrBox;                // Declare pointer to a class.
    
    // 保存第一个对象的地址
    ptrBox = &Box1;
    
    // 现在尝试使用成员访问运算符来访问成员
    cout << "Volume of Box1: " << ptrBox->Volume() << endl;
    
    // 保存第二个对象的地址
    ptrBox = &Box2;
    
    // 现在尝试使用成员访问运算符来访问成员
    cout << "Volume of Box2: " << ptrBox->Volume() << endl;
}

// C++ 类的静态成员
// 类的数据成员和函数成员都可以被声明为静态的。
// 我们可以使用 static 关键字来把类成员定义为静态的。当我们声明类的成员为静态时，这意味着无论创建多少个类的对象，静态成员都只有一个副本
// 静态成员在类的所有对象中是共享的。如果不存在其他的初始化语句，在创建第一个对象时，所有的静态数据都会被初始化为零。
// 我们不能把静态成员的初始化放置在类的定义中，但是可以在类的外部通过使用范围解析运算符 :: 来重新声明静态变量从而对它进行初始化
class Box7
{
public:
    static int objectCount;
    // 构造函数定义
    Box7(double l=2.0, double b=2.0, double h=2.0)
    {
        cout <<"Constructor called." << endl;
        length = l;
        breadth = b;
        height = h;
        // 每次创建对象时增加 1
        objectCount++;
    }
    double Volume()
    {
        return length * breadth * height;
    }
    static int getCount() // 静态成员函数
    {
        return objectCount;
    }
private:
    double length;     // 长度
    double breadth;    // 宽度
    double height;     // 高度
};
 
// 初始化类 Box 的静态成员
int Box7::objectCount = 0;

void p10_func14()
{
    // 在创建对象之前输出对象的总数
    cout << "Inital Stage Count: " << Box7::getCount() << endl;
    
    Box7 Box1(3.3, 1.2, 1.5);    // 声明 box1
    Box7 Box2(8.5, 6.0, 2.0);    // 声明 box2
    
    // 在创建对象之后输出对象的总数
    cout << "Final Stage Count: " << Box7::getCount() << endl;
}

int main10()
{
        p10_func14();
//    cout << "Max (20,10): " << Max(20,10) << endl;
    return 0;
}


