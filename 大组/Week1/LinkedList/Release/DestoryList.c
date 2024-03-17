#include<stdio.h>
#include"StructList.h"

//销毁链表
void destoryList(struct list *head){
    if(head==NULL){
        printf("无链表可查找,请先创建链表\n");
    }
    else {
        //多个结点的链表销毁
        struct list* p = head->next;
        for(;p!=NULL;){
            free(head);
            head=p;
            p=p->next;
        }
        free(head);
        printf("链表销毁成功。");
    }
}