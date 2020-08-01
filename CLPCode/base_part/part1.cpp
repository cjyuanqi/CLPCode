//
//  helloworld.cpp
//  CLPCode
//
//  Created by 陈俊 on 2019/12/31.
//  Copyright © 2019 陈俊. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

// 可以使用 typedef 为一个已有的类型取一个新的名字  typedef type newname;
typedef int feet;

/*
 * 创建枚举，需要使用关键字 enum。枚举类型的一般形式如下
 * 默认情况下，第一个名称的值为 0，第二个名称的值为 1，第三个名称的值为 2，以此类推
 */
enum color {
    red,
    green,
    blue
};

int main1()
{
    cout << "type: \t\t" << "************size**************"<< endl;
    cout << "bool: \t\t" << "所占字节数：" << sizeof(bool);
    cout << "\t最大值：" << (numeric_limits<bool>::max)();
    cout << "\t\t最小值：" << (numeric_limits<bool>::min)() << endl;
    
    cout << "int: \t\t" << "所占字节数: " << sizeof(int);
    cout << "\t最大值: " << (numeric_limits<int>::max)();
    cout << "\t\t最小值: " << (numeric_limits<int>::min)() << endl;
    
    cout << "feet: \t\t" << "所占字节数: " << sizeof(feet);
    cout << "\t最大值: " << (numeric_limits<feet>::max)();
    cout << "\t\t最小值: " << (numeric_limits<feet>::min)() << endl;
    
    cout << "type: \t\t" << "************size**************"<< endl;
    
    color c = blue;
    
    cout << "c = "+to_string(c) << endl;
    return 0;
}
