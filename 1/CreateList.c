#include"StructList.h"
#include<stdio.h>
#include<stdlib.h>
void destoryList(struct list *head);


void createList(struct list** head){
    if(*head != NULL){
        //若链表不为空链表，这先销毁旧链表
        destoryList(*head);
    }
    *head = (struct list *)malloc(sizeof(struct list));
    (*head)->next=NULL;
    printf("空链表创建成功。\n");
}