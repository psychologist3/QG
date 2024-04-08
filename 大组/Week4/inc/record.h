#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
    struct tree *left;
    struct tree  *right;
    int number;
}tree,*treepoint;

typedef struct Queuepoint{
    tree *head;
    struct Queuepoint *next;
}Queuepoint,*QueuepointPtr,*Stack;

typedef struct Queue{
    Queuepoint *head;
    Queuepoint *end;
}Queue;



