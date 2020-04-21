//
//  pointer.h
//  BaseC
//
//  Created by 杨飞龙 on 2020/4/15.
//  Copyright © 2020 杨飞龙. All rights reserved.
//

#ifndef pointer_h
#define pointer_h

#include <stdio.h>

// function
void two_level_pointer(void);
void test_pointer_1(void);
void test_pointer_2(void);
void test_pointer_3(void);
void test_pointer(void);
void test_pointer_4(void);
void getchar_to_file(const char *filename);
void postchar_to_file(void);

// struct
typedef struct stu {
    char * name;
    char * sex;
    char * num;
    float * score;
} Stu;

enum errorNum {
    Success,
    NameError,
    SexError,
    NumError,
    ScoreError,
};

#endif /* pointer_h */
