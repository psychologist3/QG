#include<stdio.h>
#include"StructList.h"

//��������
void destoryList(struct list *head){
    if(head==NULL){
        printf("������ɲ���,���ȴ�������\n");
    }
    else {
        //���������������
        struct list* p = head->next;
        for(;p!=NULL;){
            free(head);
            head=p;
            p=p->next;
        }
        free(head);
        printf("�������ٳɹ���");
    }
}