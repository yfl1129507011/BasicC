//
//  macro.c
//  BaseC
//
//  Created by 杨飞龙 on 2020/3/27.
//  Copyright © 2020 杨飞龙. All rights reserved.
//

#include "macro.h"

// 判断输入的数字是否超过限制
void number_is_limit()
{
    int num = 0;
    printf("Input number:");
    scanf("%d", &num);
    
    if (num > LIMIT) {
        printf("number:%d is limit[%d]\n", num, LIMIT);
    }else{
        printf("number:%d is available\n", num);
    }
}

// 输入一个数字，输出一个幸运数字
void lucky_number()
{
    int m = 0;
    int luckyNum = 0;
    
    printf("Input number:");
    scanf("%d", &m);
    
    if (m > 10) {
        luckyNum = SQ(m+3); // (m+3)*(m+3)
    }else{
        luckyNum = M*m+M-m; // (m*m + 2*m)*m + (m*m + 2*m) - m
    }
    printf("your lucky number:%d\n", luckyNum);
}

// 强制转化为字符串格式
void define_string()
{
    char str[10] = {0};
    int num = 0;
    
    printf("input string:");
    scanf("%s", str);
    
    printf("%s STR is %s\n", str, STR(str));  // str
    
    printf("input number:");
    scanf("%d", &num);
    
    printf("%d STR is %s\n", num, STR(str));  // str
    
    printf("%s\n", STR(yangfeilong));
    printf("%s\n", STR("yangfeilong"));
}

// 宏参数的连接
void macro_connect(void)
{
    printf("%f\n", CONNECT1(8.5, 2)); // 8.5e2
    
    printf("%d\n", CONNECT2(12, 34)); // 123400
    
}


// 预定义宏
void predefine_example()
{
    printf("Date: %s\n", __DATE__);  // 表示当前的编译日期
    printf("Time: %s\n", __TIME__);  // 表示当前的编译时间；
    printf("File: %s\n", __FILE__);  // 表示当前源文件的名称；
    printf("Line: %d\n", __LINE__);  // 表示当前源代码的行号；
}
