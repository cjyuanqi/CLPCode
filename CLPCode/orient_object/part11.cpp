//
//  part11.cpp
//  CLPCode
//
//  Created by 陈俊 on 2020/1/3.
//  Copyright © 2020 陈俊. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

// C++ 继承
// 面向对象程序设计中最重要的一个概念是继承。
// 继承允许我们依据另一个类来定义一个类，这使得创建和维护一个应用程序变得更容易。这样做，也达到了重用代码功能和提高执行效率的效果。
// 当创建一个类时，您不需要重新编写新的数据成员和成员函数，只需指定新建的类继承了一个已有的类的成员即可。这个已有的类称为基类，新建的类称为派生类。
// 继承代表了 is a 关系。例如，哺乳动物是动物，狗是哺乳动物，因此，狗是动物，等等。


// 基类 & 派生类
// 一个类可以派生自多个类，这意味着，它可以从多个基类继承数据和函数。
// 定义一个派生类，我们使用一个类派生列表来指定基类。类派生列表以一个或多个基类命名
// 基类
class Shape
{
   public:
      void setWidth(int w)
      {
         width = w;
      }
      void setHeight(int h)
      {
         height = h;
      }
   protected:
      int width;
      int height;
};

// 派生类
class Rectangle: public Shape
{
   public:
      int getArea()
      {
         return (width * height);
      }
};

void p11_func1()
{
    Rectangle Rect;
    Rect.setWidth(5);
    Rect.setHeight(7);
    
    // 输出对象的面积
    cout << "Total area: " << Rect.getArea() << endl;
}

// 访问控制和继承
// 访问    public    protected    private
// 同一个类  yes      yes          yes
// 派生类    yes      yes          no
// 外部的类  yes       no          no

// 一个派生类继承了所有的基类方法，但下列情况除外：
// 基类的构造函数、析构函数和拷贝构造函数。
// 基类的重载运算符。
// 基类的友元函数。

// 继承类型
// 当一个类派生自基类，该基类可以被继承为 public、protected 或 private 几种类型。继承类型是通过上面讲解的访问修饰符 access-specifier 来指定的。
// 我们几乎不使用 protected 或 private 继承，通常使用 public 继承。当使用不同类型的继承时，遵循以下几个规则：
// 公有继承（public）：当一个类派生自公有基类时，基类的公有成员也是派生类的公有成员，基类的保护成员也是派生类的保护成员，基类的私有成员不能直接被派生类访问，
// 但是可以通过调用基类的公有和保护成员来访问。
// 保护继承（protected）： 当一个类派生自保护基类时，基类的公有和保护成员将成为派生类的保护成员。
// 私有继承（private）：当一个类派生自私有基类时，基类的公有和保护成员将成为派生类的私有成员。

// 多继承
// 多继承即一个子类可以有多个父类，它继承了多个父类的特性。C++ 类可以从多个类继承成员.

// 基类 Shape
class Shape2
{
   public:
      void setWidth(int w)
      {
         width = w;
      }
      void setHeight(int h)
      {
         height = h;
      }
   protected:
      int width;
      int height;
};

// 基类 PaintCost
class PaintCost2
{
   public:
      int getCost(int area)
      {
         return area * 70;
      }
};

// 派生类
class Rectangle2: public Shape2, public PaintCost2
{
   public:
      int getArea()
      {
         return (width * height);
      }
};

void p11_func2()
{
    Rectangle2 Rect;
    int area;
    
    Rect.setWidth(5);
    Rect.setHeight(7);
    
    area = Rect.getArea();
    
    // 输出对象的面积
    cout << "Total area: " << Rect.getArea() << endl;
    
    // 输出总花费
    cout << "Total paint cost: $" << Rect.getCost(area) << endl;
    
}

// C++重载运算符和重载函数
class printData
{
   public:
      void print(int i) {
        cout << "整数为: " << i << endl;
      }
 
      void print(double  f) {
        cout << "浮点数为: " << f << endl;
      }
 
      void print(char c[]) {
        cout << "字符串为: " << c << endl;
      }
};

void p11_func3()
{
    printData pd;
    
    // 输出整数
    pd.print(5);
    // 输出浮点数
    pd.print(500.263);
    // 输出字符串
    char c[] = "Hello C++";
    pd.print(c);
}

// C++ 多态
// 当类之间存在层次结构，并且类之间是通过继承关联时，就会用到多态。
// C++ 多态意味着调用成员函数时，会根据调用函数的对象的类型来执行不同的函数。
class Shape3 {
   protected:
      int width, height;
   public:
      Shape3( int a=0, int b=0)
      {
         width = a;
         height = b;
      }
      virtual int area() // 不加virtual时是静态多态, 有时也称早绑定
      {
         cout << "Parent class area :" <<endl;
         return 0;
      }
};

class Rectangle3: public Shape3{
   public:
      Rectangle3( int a=0, int b=0):Shape3(a, b) { }
      int area ()
      {
         cout << "Rectangle class area :" <<endl;
         return (width * height);
      }
};
class Triangle3: public Shape3{
   public:
      Triangle3( int a=0, int b=0):Shape3(a, b) { }
      int area ()
      {
         cout << "Triangle class area :" <<endl;
         return (width * height / 2);
      }
};

void p11_func4()
{
    Shape3 *shape;
    Rectangle3 rec(10,7);
    Triangle3  tri(10,5);
    
    // 存储矩形的地址
    shape = &rec;
    // 调用矩形的求面积函数 area
    shape->area();
    
    // 存储三角形的地址
    shape = &tri;
    // 调用三角形的求面积函数 area
    shape->area();
}

// 虚函数
// 虚函数 是在基类中使用关键字 virtual 声明的函数。在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接到该函数。
// 我们想要的是在程序中任意点可以根据所调用的对象类型来选择调用的函数，这种操作被称为动态链接，或后期绑定。

// 纯虚函数
// 您可能想要在基类中定义虚函数，以便在派生类中重新定义该函数更好地适用于对象，但是您在基类中又不能对虚函数给出有意义的实现，这个时候就会用到纯虚函数。
// pure virtual function  可将Shape3中的虚函数定义为如下形式.
// virtual int area() = 0;


// 数据抽象
class Adder{
   public:
      // 构造函数
      Adder(int i = 0)
      {
        total = i;
      }
      // 对外的接口
      void addNum(int number)
      {
          total += number;
      }
      // 对外的接口
      int getTotal()
      {
          return total;
      };
   private:
      // 对外隐藏的数据
      int total;
};

void p11_func5()
{
    Adder a;
    
    a.addNum(10);
    a.addNum(20);
    a.addNum(30);
    
    cout << "Total " << a.getTotal() <<endl;
}

// C++ 接口 & 抽象类
// 接口描述了类的行为和功能，而不需要完成类的特定实现。
// C++ 接口是使用抽象类来实现的，抽象类与数据抽象互不混淆，数据抽象是一个把实现细节与相关的数据分离开的概念。
// 如果类中至少有一个函数被声明为纯虚函数，则这个类就是抽象类。纯虚函数是通过在声明中使用 "= 0" 来指定的
// 设计抽象类（通常称为 ABC）的目的，是为了给其他类提供一个可以继承的适当的基类。抽象类不能被用于实例化对象，它只能作为接口使用。
class Box
{
   public:
      // 纯虚函数
      virtual double getVolume() = 0;  // 有纯虚函数, 因此Box类是抽象类
   private:
      double length;      // 长度
      double breadth;     // 宽度
      double height;      // 高度
};

// 基类
class Shape4
{
public:
   // 提供接口框架的纯虚函数
   virtual int getArea() = 0;
   void setWidth(int w)
   {
      width = w;
   }
   void setHeight(int h)
   {
      height = h;
   }
protected:
   int width;
   int height;
};

// 派生类
class Rectangle4: public Shape4
{
public:
   int getArea()
   {
      return (width * height);
   }
};
class Triangle4: public Shape4
{
public:
   int getArea()
   {
      return (width * height)/2;
   }
};

void p11_func6()
{
    Rectangle4 Rect;
    Triangle4  Tri;
    
    Rect.setWidth(5);
    Rect.setHeight(7);
    // 输出对象的面积
    cout << "Total Rectangle area: " << Rect.getArea() << endl;
    
    Tri.setWidth(5);
    Tri.setHeight(7);
    // 输出对象的面积
    cout << "Total Triangle area: " << Tri.getArea() << endl;
}

int main11()
{
    p11_func6();
    return 0;
}
