#include<stdio.h>
#include<stdlib.h>
//����һ���ṹ��
struct list{
    char a[10];
    struct list *last;
    struct list *next;
};
