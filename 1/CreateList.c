#include"StructList.h"
#include<stdio.h>
#include<stdlib.h>
void destoryList(struct list *head);


void createList(struct list** head){
    if(*head != NULL){
        //������Ϊ�������������پ�����
        destoryList(*head);
    }
    *head = (struct list *)malloc(sizeof(struct list));
    (*head)->next=NULL;
    printf("���������ɹ���\n");
}