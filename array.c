//
//  array.c
//  BaseC
//
//  Created by 杨飞龙 on 2020/3/27.
//  Copyright © 2020 杨飞龙. All rights reserved.
//

#include <string.h>
#include "array.h"

// 一维数组等价于一级指针； 二维数组等价于数组指针

void two_dimension_to_one()
{
    int arr[3][2] = {1,2,3,4,5,6};
    int *p[3];
    int a[3] = {1,2,3};
    for (int k=0; k<3; k++) {
        printf("&a[%d]=%#X\n", k, (int)&a[k]);
    }
    printf("(int)a+1=%#X\n", (int)a+1); // 0XEFBFF4A5
//    printf("%d\n", *((int *)(0XEFBFF4A5)));
    
    for (int i=0; i<3; i++) {
        p[i] = arr[i];
    }
    
    for (int x=0; x<3; x++) {
        for (int y=0; y<2; y++) {
            printf("p[%d][%d]=%d\n", x, y, p[x][y]);
        }
    }
}

void two_dimension()
{
    int arr[2][3] = {{1,2,3}, {6,5,4}};
    int (*p)[2][3];
    int (*pp)[3];
    int *ppp;
    
    int (*a)[2][3];
    int (*aa)[3];
    int *aaa;
    
    char * c = NULL;
    
    int *iArr = (int *)arr;
    int len = sizeof(arr)/sizeof(int);
    for (int k=0; k<len; k++) {
        printf("*(iArr+%d)=%d\n", k, *(iArr+k));
    }
    printf("=========\n");
    
    p = &arr;
    pp = &arr[0]; // pp = arr;
    ppp = &arr[0][0];
    printf("sizeof(p)=%lu\n", sizeof(p));
    printf("sizeof(pp)=%lu\n", sizeof(pp));
    printf("sizeof(ppp)=%lu\n", sizeof(ppp));
    printf("sizeof(int)=%lu\n", sizeof(int));
    printf("sizeof(char)=%lu\n", sizeof(char));
    printf("sizeof(&arr)=%lu\n", sizeof(&arr));
    printf("sizeof(c)=%lu\n", sizeof(c));
    printf("=========\n");
    
    a = &arr;
    aa = *&arr;  // aa = arr;
    aaa = **&arr;
    printf("sizeof(a)=%lu\n", sizeof(a));
    printf("sizeof(aa)=%lu\n", sizeof(aa));
    printf("sizeof(aaa)=%lu\n", sizeof(aaa));
    printf("=========\n");
    
    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {
            printf("&arr[%d][%d]=%x\n", i, j, (uint)&arr[i][j]);
        }
    }
    
    printf("==========\n");
    printf("p\t=%#X\n", (uint)p);
    printf("*p\t=%#X\n", (uint)(*p));
    printf("**p\t=%#X\n", (uint)(**p));
    printf("***p\t=%#X\n", (uint)(***p));
    
    printf("==========\n");
    printf("&arr\t=%#X\n", (uint)&arr);
    printf("*(&arr)\t=%#X\n", (uint)(*&arr));
    printf("**(&arr)\t=%#X\n", (uint)(**&arr));
    printf("***(&arr)\t=%#X\n", (uint)(***&arr));
    
    printf("==========\n");
    printf("arr=%x\n", (uint)arr);
    printf("arr[0]=%x\n", (uint)arr[0]);
    printf("&arr[0]=%x\n", (uint)&arr[0]);
    printf("&arr[0][0]=%x\n", (uint)&arr[0][0]);
    printf("arr[0][0]=%d\n", (uint)arr[0][0]);
    
    printf("==========\n");
    printf("&arr+1=%x\n", (uint)(&arr+1));
    printf("arr+1=%x\n", (uint)(arr+1));
    printf("arr[0]+1=%x\n", (uint)(arr[0]+1));
    printf("&arr[0]+1=%x\n", (uint)(&arr[0]+1));
    printf("&arr[0][0]+1=%x\n", (uint)(&arr[0][0]+1));
    printf("arr[0][0]+1=%d\n", arr[0][0]+1);
}

void one_dimension_func(char *ch)
{
    printf("ch=%x\n", (uint)ch);
    printf("ch+1=%x\n", (uint)ch+1);
    printf("strlen(ch)=%lu\n", strlen(ch));
}

// 一维数组的理解
void one_dimension_to_two()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    const int size = 5;
    int (*p)[size] = (int(*)[size])arr;
    int step = sizeof(arr)/sizeof(int[size]);
    
    for (int i=0; i<step; i++) {
        for (int j=0; j<size; j++) {
            printf("p[%d][%d]=%d\n", i, j, p[i][j]);
        }
        putchar(10);
    }
}

void one_dimension()
{
    char str[10] = "FenLon";
    const int size = sizeof(str);
    int i = 0;
    char * ch = str;
    int len = 0;
    
    while (*ch != '\0') {
        len++;
        ch++;
    }
    printf("len=%d\n", len);
    for (int j=0; j<len; j++) {
        printf("%c\n", str[j]);
    }
    printf("===============\n");
    
    for (; i<size; i++){
        printf("&str[%d]=%x\n", i, (int)&str[i]);
    }
    
    printf("===============\n");
    printf("str=%x\n", (uint)str);
    printf("*str=%c\n", *str);
    printf("&str=%x\n", (uint)&str);
    printf("str[0]=%c\n", str[0]);
    printf("str[0]=%x\n", str[0]);
    printf("str[0]=%d\n", str[0]);
    printf("&str[0]=%x\n", (uint)&str[0]);
    printf("*&str[0]=%c\n", *&str[0]);
    
    printf("===============\n");
    printf("str+1=%x\n", (uint)(str+1));
    printf("*str+1=%c\n", *(str+1));
    printf("&str+1=%x\n", (uint)(&str+1));
    printf("str[0]+1=%c\n", str[0]+1);
    printf("str[0]+1=%x\n", str[0]+1);
    printf("str[0]+1=%d\n", str[0]+1);
    printf("&str[0]+1=%x\n", (uint)(&str[0]+1));
    printf("*&str[0]+1=%c\n", *(&str[0]+1));
    
    one_dimension_func(str);
}

// 自定义函数，用来输出数组元素
void display_array(int arr[], int len)
{
    int i;
    for (i=0; i<len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//c语言数组是静态的，不能插入或删除元素
void static_array_example()
{
    int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int nums_new1[9], nums_new2[11], i;
    
    // 删除nums第6个元素
    for(i=0; i<10; i++){
        if (i < 6) {
            nums_new1[i] = nums[i];
        }else if (i > 6){
            nums_new1[i-1] = nums[i];
        }
    }
    display_array(nums_new1, 9);
    
    // 在nums第6个元素后面插入整数25
    for(i=0; i<10; i++){
        if (i < 7) {
            nums_new2[i] = nums[i];
        }else if(i > 7){
            nums_new2[i+1] = nums[i];
        }else{
            nums_new2[i] = 25;
            nums_new2[i+1] = nums[i];
        }
    }
    display_array(nums_new2, 11);
    
}

void static_array_example_good(void)
{
    int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int nums_new1[9], nums_new2[11], i;
    
    // 删除nums第6个元素后存入nums_new1[9]
    // 在nums第6个元素后面插入整数25后存入nums_new2[11]
    for(i=0; i<10; i++){
        if (i == 6) { // 删除第6个元素
            nums_new2[i] = nums[i];
        }else if(i == 7){  // 第6个元素后面插入整数25
            nums_new1[i-1] = nums[i];
            nums_new2[i] = 25;
            nums_new2[i+1] = nums[i];
        }else if(i < 6){
            nums_new1[i] = nums_new2[i] = nums[i];
        }else{
            nums_new1[i-1] = nums[i];
            nums_new2[i+1] = nums[i];
        }
    }
    display_array(nums_new1, 9);
    display_array(nums_new2, 11);
}

