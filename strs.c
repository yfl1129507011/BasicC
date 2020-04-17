//
//  strs.c
//  BaseC
//
//  Created by 杨飞龙 on 2020/3/27.
//  Copyright © 2020 杨飞龙. All rights reserved.
//

#include "array.h"
#include <string.h>


// 输入字符串打印字符串的长度
void display_string_length(void)
{
    char strs[100] = {0};
    long length = 0;
    
    printf("Please Input string: ");
    // gets(strs);  // gets获取字符串
    scanf("%s", strs); // scanf获取字符串
    
    length = strlen(strs);
    
    printf("Input strings is [%s] and length is [%ld] \n", strs, length);
}

// 链接2个字符串
void display_string_strcat(void)
{
    char greetings[100] = "hello!";
    char names[20] = {0};
    
    printf("Input Your Name:");
    scanf("%s", names);
    
    strcat(greetings, names);
    puts(greetings);
}


// 复制字符串
void display_string_strcpy(void)
{
    char str[50] = {0};
    
    printf("Input string:");
    gets(str);
    
    long len = strlen(str);
    char cpyStr[len];
    strcpy(cpyStr, str);
    puts(cpyStr);
}


// 设置密码
void confirm_password()
{
    char password1[7], password2[7];
    
    printf("Please Input six password：");
    gets(password1);
    
    printf("Please Input six password again: ");
    gets(password2);
    
    int i = strcmp(password1, password2);
    if (i == 0) {
        printf("set password success!\n");
    }else{
        printf("password is not same!\n");
    }
}
