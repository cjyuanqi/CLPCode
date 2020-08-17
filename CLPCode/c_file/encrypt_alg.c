//
//  encrypt_alg.c
//  CLPCode
//
//  Created by 陈俊 on 2020/8/1.
//  Copyright © 2020 陈俊. All rights reserved.
//

#include <stdio.h>
#include <string.h>

// 编写加密程序，加密规则为：将所有字母转化为该字母后的第三个字母，即A->D、B->E、C->F、......、Y->B、Z->C。
// 小写字母同上，其他字符不做转化。输入任意字符串，输出加密后的结果。
// 例如：输入"I love 007"，输出"L oryh 007"
void encrpt_algrithm(char *str) {
    
    int length = (int)strlen(str);
    
    char c;
    
    for (int i=0; i < length; i++) {
        c = str[i];
        
        if (c >= 'a' && c <= 'z') {
            c += 3;
            if (c > 'z') {
                c = 'a' + c - 'z';
            }
            str[i] = (char)c;
            continue;
        }
            
        
        if (c >= 'A' && c <= 'Z') {
            c += 3;
            if (c > 'Z') {
                c = 'A' + c - 'Z';
            }
            str[i] = (char)c;
        }
        
    }
}

int main_encrpt(){
    char *str = "abc123ABC";
    encrpt_algrithm(str);
    printf("%s\n",str);
}
