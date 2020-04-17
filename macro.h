//
//  macro.h
//  BaseC
//
//  Created by 杨飞龙 on 2020/3/27.
//  Copyright © 2020 杨飞龙. All rights reserved.
//

#ifndef macro_h
#define macro_h

#include <stdio.h>

// 宏定义
#define LIMIT 925
#define M (m*m + 2*m)

// 带参数的宏定义
#define MAX(a,b) (a>b) ? a : b
#define SQ(y) (y)*(y)

// 宏参数的字符串化
#define STR(s) #s

// 宏参数的连接
#define CONNECT1(a, b) a##e##b
#define CONNECT2(a, b) a##b##00

void number_is_limit(void);
void lucky_number(void);
void define_string(void);
void macro_connect(void);
void predefine_example(void);

#endif /* macro_h */
