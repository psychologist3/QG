#include<stdio.h>
#include<stdlib.h>
typedef struct  QNode
{ 
    char word[10];
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
    QueuePtr head;
    QueuePtr tail;
}LinkQueue;

