#include<stdio.h>
#include<stdlib.h>
typedef struct number{
    int num;
    struct number *last;
    struct number *next;
}number,*numberpoint;
