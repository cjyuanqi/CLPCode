//
//  ClassifyChar.c
//  CLPCode
//
//  Created by 陈俊 on 2020/8/17.
//  Copyright © 2020 陈俊. All rights reserved.
//

#include <stdio.h>
#include<string.h>

char str[101]={0};
char letter[101]={0};
char num[101]={0};

int main(){
    char other[101]={0};
    scanf("%s",str);
    int l_id=0;int n_id=0;int o_id=0;
    for(int i=0;i<=strlen(str);i++){
        if(str[i]>='a' && str[i]<='z') letter[l_id++]=str[i];
        else if(str[i]>='A' && str[i]<='Z') letter[l_id++]=str[i];
        else if(str[i]>='0' && str[i]<='9') num[n_id++]=str[i];
        else other[o_id++]=str[i];
    }
    printf("%s\n",letter);
    printf("%s\n",num);
    printf("%s\n",other);

return 0;
}
