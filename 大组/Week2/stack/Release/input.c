#include<stdio.h>
#include"Struct.h"
#include<stdlib.h>
LinkStackPtr input(){ 
    LinkStackPtr head=(LinkStackPtr)malloc(sizeof(StackNode)),p=NULL;
    head->next=NULL;
    p=head;
    char word;
    printf("������һ�����ʽ��\n");
    fflush(stdin);
    word = getchar();
    while(word!='\n'){
        p->word=word;
        word = getchar();
        if(word!='\n')
        {
            p=p->next=(LinkStackPtr)malloc(sizeof(StackNode));
            p->next=NULL;
        }
    }
    return head;
}