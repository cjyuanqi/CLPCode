//
//  TraverseCharArr.c
//  CLPCode
//
//  Created by 陈俊 on 2020/8/1.
//  Copyright © 2020 陈俊. All rights reserved.
//

#include <stdio.h>

void traverse() {
    char str[100];
    int i, j, len;
    char temp;
    scanf("%s", str);
    len=strlen(str);
    for (i = 0, j = len-1; i <= j; --j, ++i)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    printf("%s", str);
}

int main() {
    traverse();
}
