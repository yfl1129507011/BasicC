//
//  pointer.c
//  BaseC
//
//  Created by 杨飞龙 on 2020/4/15.
//  Copyright © 2020 杨飞龙. All rights reserved.
//

#include <malloc/_malloc.h>
#include <string.h>
#include "pointer.h"

void test_pointer_4()
{
    char * ch[] = {"Fenlon", "Jim", "Tom", "Frank"};
    int len = sizeof(ch)/sizeof(ch[0]);
    int sumLen = 0;
    char * c = (char *)ch[0]; // (char *)(*ch)
    
    for (int i=0; i<len; i++) {
        printf("ch[%d]=%#X\n", i, (int)ch[i]);
        printf("&ch[%d]=%#X\n", i, (int)&ch[i]);
        printf("ch[%d]=%s\n", i, ch[i]);
        printf("--------\n");
        sumLen += strlen(ch[i])+1;
    }
    
    for (int i=0; i<sumLen; i++) {
        printf("*(c+%d)=%c\n", i, *(c+i));
        printf("*(ch[0]+%d)=%c\n", i, *(ch[0]+i));
        printf("*(*ch+%d)=%c\n", i, *(*ch+i));
    }
    printf("==========\n");
    printf("&ch=%#X\n", (int)&ch);
    printf("&ch+1=%#X\n", (int)(&ch+1));
    printf("ch=%#X\n", (int)ch);
    printf("ch+1=%#X\n", (int)ch+1);
    printf("*ch=%#X\n", (int)(*ch));
    printf("*ch+1=%#X\n", (int)(*ch+1));
    printf("ch[0]=%#X\n", (int)ch[0]);
    printf("ch[0]+1=%#X\n", (int)(ch[0]+1));
    printf("&ch[0]=%#X\n", (int)&ch[0]);
    printf("&ch[0]+1=%#X\n", (int)(&ch[0]+1));
    printf("==========\n");
    
    for (int i=0; i<len; i++) {
        for (int j=0; j<strlen(ch[i]); j++) {
            printf("ch[%d][%d]=%c\n", i, j, ch[i][j]);
            printf("&ch[%d][%d]=%#X\n", i, j, (int)&ch[i][j]);
        }
    }
    
}

void test_pointer()
{
    int func_num = 4;
    switch (func_num) {
        case 1:
            test_pointer_1();
            break;
        case 2:
            test_pointer_2();
            break;
        case 3:
            test_pointer_3();
            break;
        case 4:
            test_pointer_4();
            break;
        default:
            two_level_pointer();
            break;
    }
}

// 二级以上指针的步长是地址的长度（8）
void test_pointer_3()
{
    int *p = NULL;
    int **pp = NULL;
    int ***ppp = NULL;
    
    printf("p=%#X\t p+1=%#X\n", (int)p, (int)(p+1));
    printf("pp=%#X\t pp+1=%#X\n", (int)pp, (int)(pp+1));
    printf("ppp=%#X\t ppp+1=%#X\n", (int)ppp, (int)(ppp+1));
}

int molloc_struct(Stu ** student)
{
    *student = (Stu *)malloc(sizeof(Stu));
    (*student)->name = (char *)malloc(10);
    if ((*student)->name == NULL) {
        return NameError;
    }
    (*student)->num = (char *)malloc(20);
    if ((*student)->num == NULL) {
        return NumError;
    }
    (*student)->sex = (char *)malloc(1);
    if ((*student)->sex == NULL) {
        return SexError;
    }
    (*student)->score = (float *)malloc(sizeof(float));
    if ((*student)->score == NULL) {
        return ScoreError;
    }
    
    return Success;
}

void test_pointer_2()
{
    Stu * stu1 = NULL;
    int errStatus = molloc_struct(&stu1);
    if (errStatus != Success) {
        printf("error status=%d\n", errStatus);
        return;
    }
    strcpy(stu1->name, "fenlon");
    *(stu1->sex) = 'x';
    strcpy(stu1->num, "1123434");
    *(stu1->score) = 99.8;
}

void edit_array(int arr[], int size)
{
    for (int i=0; i<size; i++) {
        arr[i] = 0;
    }
}

void test_pointer_1()
{
    int arr[3] = {9, 8, 7};
    for (int i=0; i<3; i++) {
        printf("arr[%d]=%d\n", i, arr[i]);
    }
    printf("=======\n");
    edit_array(arr, 3);
    
    for (int i=0; i<3; i++) {
        printf("arr[%d]=%d\n", i, arr[i]);
    }
}

void two_level_pointer()
{
    int a = 1, b = 2;
    int *p = &a;
    int **pp = &p;
    
    printf("&a=%#X\n", (int)&a);
    printf("&b=%#X\n", (int)&b);
    printf("p=%#X\n", (int)p);
    printf("pp=%#X\n", (int)pp);
    printf("========\n");
    
    *pp = &b;
    
    printf("&a=%#X\n", (int)&a);
    printf("&b=%#X\n", (int)&b);
    printf("p=%#X\n", (int)p);
    printf("pp=%#X\n", (int)pp);
}
