//
//  part0.c
//  CLPCode
//
//  Created by 陈俊 on 2020/4/14.
//  Copyright © 2020 陈俊. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fwtest()
{
        FILE *fp = NULL;
        
        fp = fopen("/Users/chenjun/Work/prac/test0.txt", "w");
        fprintf(fp, "This is testing for printf....\n");
        fputs("this is a test for fputs\n", fp);
        fputc('h', fp);
        fclose(fp);
}

void frtest()
{
    FILE *fp = NULL;
    char buff[255];

    fp = fopen("/Users/chenjun/Work/prac/test0.txt", "r");

    fscanf(fp, "%s",buff);
    printf("1: %s\n",buff);

    fgets(buff, 255, fp);
    printf("2: %s\n",buff);

    fgets(buff, 255, fp);
    printf("3: %s\n",buff);
}

// 有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前20项之和。
void test0()
{
//    int up=2,down=1,temp;
//    double part = 1.0 * up / down;
//    double sum = 0;
//
//    for (int i=1; i <= 20; i++) {
//        sum += part;
//        temp = up;
//        up += down;
//        down = temp;
//        part = 1.0 * up / down;
//    }
//
//    printf("%lf\n",sum);
    
   
    float a=2.0f,b=1.0f,t;
    float sum = 0.0;
    for (int i=1; i<=20; i++) {
        sum += a/b;
        t = a;
        a += b;
        b = t;
    }
    
    printf("%9.6f\n",sum);
    
}

// 求1+2!+3!+...+20!的和。
void test1()
{
    long long sum = 0;
    long long n=1;
    for (int i=1; i<=20; i++) {
        n = n*i;
        sum += n;
    }
    
    printf("%lld\n",sum);
}

// 题目：利用递归方法求5!。

int fac(int n){
    if(n==0 || n==1) return 1;
    else return n * fac(n-1);
}
void test2()
{
    int ret = fac(5);
    printf("%d\n",ret);
}

// 给一个不多于5位的正整数，要求：一、求它是几位数，二、逆序打印出各位数字。
void test3() {
    int n;
    scanf("%d",&n); // 54321
    int n5,n4,n3,n2,n1;
    n5 = n/10000;
    n4 = n % 10000 / 1000;
    n3 = n % 1000 / 100;
    n2 = n % 100 / 10;
    n1 = n % 10;
    
    printf("%d %d %d %d %d\n",n1,n2,n3,n4,n5);
}


// Monday Friday  Wednesday    Thursday  Tuesday  Saturday Sunday'
// 题目：请输入星期几的第一个字母来判断一下是星期几，如果第一个字母一样，则继续判断第二个字母。
void test4()
{
    char c;
    scanf("%c",&c);
    getchar();
    switch (c) {
        case 'f':
            printf("Friday\n");
            break;
            
        case 'm':
            printf("Monday\n");
            break;
            
        case 'w':
            printf("Wednesday\n");
            break;
            
        case 't':
            printf("please input the next char!\n");
            scanf("%c",&c);
            if (c == 'h') {
                printf("Thursday\n");
            }else if(c == 'u') {
                printf("Tuesday\n");
            }
            break;
            
        case 's':
            printf("please input the next char!\n");
            scanf("%c",&c);
            if (c == 'a') {
                printf("Saturday\n");
            }else if(c == 'u') {
                printf("Sunday\n");
            }
            break;
            
        default:
            break;
    }
}

// 题目：删除一个字符串中的指定字母，如：字符串 "aca"，删除其中的 a 字母。
char result[256] = {0};
char * deleteCharactersFromString(char * str, char c){
    
    for (int i=0; i <256; i++) {
        result[i] = 0;
    }
    
    int len = (int)strlen(str);
    int index = 0;
    for (int i=0; i < len; i++) {
        if (c != str[i]) result[index++] = str[i];
    }
    result[index] = '\0';
    
    return result;
}

void test5()
{
    char *str = "tiantiandongting\n";
    printf("%s\n",deleteCharactersFromString(str, 't'));
}

// 题目：判断一个数字是否为质数。
// 程序分析：质数（prime number）又称素数，有无限个。一个大于1的自然数，除了1和它本身外，不能被其他自然数整除。
void test6()
{
    int n;
    scanf("%d",&n);
    
    for (int i=2; i <= n/2; i++) {
        if (n % i == 0){
            printf("%d is not a prime!\n",n);
            return;
        }
    }
    
    printf("%d is a prime\n",n);
}

// 题目：字符串反转，如将字符串 "www.runoob.com" 反转为 "moc.boonur.www"。
char * reverseStr(char *str) {
    int len = (int)strlen(str);
    int pre=0, rail=len-1;
    char t;
    
    
    while (pre < rail) {
        t = str[pre];
        str[pre] = str[rail]; // 为什么这里有问题?
        str[rail] = t;
        pre++;
        rail--;
        printf("%s\n",str);
    }
    
    return str;
}

void test7()
{
//    printf("%s",reverseStr("china"));
    
    char *str = "www.runoob.com";
    int len = (int)strlen(str);
    
    for (int i=len-1; i>=0; i--) {
        printf("%c",str[i]);
    }
    printf("\n");
    
    
}

void test8(){
    FILE *fp;
    char *filename = "/Users/chenjun/Work/prac/test0.txt";
    char ch;
    
    if ( (fp = fopen(filename, "w")) == NULL) {
        printf("failed open the file\n");
        exit(0);
    }
    
    ch = getchar();
    while (ch != '#') {
        putc(ch, fp); // 将字符输入到文件
        putchar(ch); // 将字符打印到屏幕
        ch = getchar();
    }
    
    putchar(10); // 打印换行
    fclose(fp); // 关闭文件
}

void test9()
{
    FILE *in,*out;
    char * inName = "/Users/chenjun/Work/prac/test0.txt";
    char * outName = "/Users/chenjun/Work/prac/test1.txt";
    
    char ch;
    
    if((in = fopen(inName, "r")) == NULL){
        printf("open read file failed\n");
        exit(0);
    }
    
    if ((out = fopen(outName, "w")) == NULL) {
        printf("open write file failed\n");
        exit(0);
    }
    
    ch = getc(in);
    while (ch != EOF) {
        putc(ch, out);
        putchar(ch);
        ch = getc(in);
    }
    
    fclose(in);
    fclose(out);
}

void test10()
{
    FILE *fp;
    char str[3][10],temp[10];
    int n=3;
    
    printf("please input strings:\n");
    for (int i=0; i<n; i++)   // 输入字符串
        gets(str[i]);
    
    for(int i=0; i<n; i++) { // 对字符数组进行排序
        int k=i;
        for (int j=i+1; j<n; j++) {
            if (strcmp(str[k], str[j]) > 0) k = j;
        }
        
        if (k != i) {
            strcpy(temp, str[i]);
            strcpy(str[i], str[k]);
            strcpy(str[k],temp);
        }
        
    }
    
    // 打开文件
    if((fp = fopen("/Users/chenjun/Work/prac/test2.txt", "w")) == NULL) {
        printf("open file failed\n");
        exit(0);
    }
    
    // 向文件写入字符串
    for(int i=0; i<n; i++) {
        fputs(str[i], fp);
        fputs("\n", fp);
        puts(str[i]);
    }
    
    fclose(fp);
}


int main_part0()
{
    test10();
    return 0;
}
