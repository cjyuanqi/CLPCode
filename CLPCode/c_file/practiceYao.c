//
//  practiceYao.c
//  CLPCode
//
//  Created by 陈俊 on 2020/7/28.
//  Copyright © 2020 陈俊. All rights reserved.

#include <stdio.h>



// 给出一个K  10 <= K <= 10^9
// A+B=K,  A>=10, B是取出A的一位数字后形成的数, 高位可以为0

// K 的范围用Long可以搞定
// 从A和B的关系推断,   A<=K
// getInfoOfA(arr,num)  取出A的各位数字, 返回A的位数,   然后生成B的数组
// 在main方法里 写个循环校验 A+B=K 等式, 并计数
int getInfoOfA(int arr[],long);
int getBrr(int arr[],long barr[],int);

int main_yao() {
    
    long k;
    int num = 0;
    int numA,numB;  // numA:A的位数  numB:B可能性取指的个数

  
    int arr[9] = {0};  // 存储A的各位数字(倒序)
    
    long barr[9] = {0}; // 存储B的可能的值
    
    scanf("%ld",&k);

    for (long i = k/2; i <= k; i++) {
        numA = getInfoOfA(arr, i);
        numB = getBrr(arr,barr, numA);
        printf("\n");
        for (int j=0; j<numB; j++) {
            printf("A:%ld, B:%ld A+B:%ld | ",i,barr[j],i+barr[j]);
            if ((barr[j] + i) == k ) {
                printf("get it --> %ld+%ld=%ld",i,barr[j],k);
                num++;
            }
            printf("\n");
        }
        
    }

    printf("\n the num is:%d", num);

    
    
    return 0;
}

int getBrr(int arr[],long barr[],int n) {
    int num = 0;
    
    long ret;
    for (int i=0; i<n; i++) {
        ret = 0;
        for (int j = n-1; j >= 0; j--) {
            if (i==j) continue;
            ret = ret * 10 + arr[j];
        }
        barr[i] = ret;
        num++;
    }
    return num;
}

int getInfoOfA(int arr[], long num) {
    int i = 0;
    int digtal = (int)(num % 10);
    num /= 10;
    arr[i++] = digtal;
    while (num > 0) {
        digtal = num % 10;
        arr[i++] = digtal;
        num /= 10;
    }
    
    return i;
    
}
