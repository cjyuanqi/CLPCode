//
//  part0.c
//  CLPCode
//
//  Created by 陈俊 on 2020/2/27.
//  Copyright © 2020 陈俊. All rights reserved.

#include <stdio.h>

void moveTwo(char x, char y) {
    printf("%c->%c ",x,y);
}

void hanoi(int n, char one, char two , char three) {
    if (n == 1) {
        moveTwo(one, three);
    }else {
        hanoi(n-1, one, three, two);
        moveTwo(one, three);
        hanoi(n-1, two, one, three);
    }
}

int main0()
{
    int n;
    scanf("%d",&n);
    hanoi(n, '1', '2', '3');
    printf("\n");
    return 0;
}





