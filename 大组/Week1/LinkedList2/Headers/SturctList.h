#include<stdio.h>
#include<stdlib.h>
//定义一个结构体
struct list{
    char a[10];
    struct list *last;
    struct list *next;
};
