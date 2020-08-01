//
//  chapter4.cpp
//  CLPCode
//
//  Created by 陈俊 on 2020/1/3.
//  Copyright © 2020 陈俊. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

enum CPU_Rank {P1=1, P2,P3,P4,P5,P6,P7};

class CPU
{
private:
    CPU_Rank rank;
    int frequency;
    float voltage;
    
public:
    CPU(CPU_Rank r, int f, float v)
    {
        
    }
};
