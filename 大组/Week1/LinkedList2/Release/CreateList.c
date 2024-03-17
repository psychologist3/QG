#include"SturctList.h"
void destoryList(struct list *head);

void creatList(struct list** head){
    if(*head != NULL){
        //若链表不为空链表，这先销毁旧链表
        destoryList(*head);
    }
    *head = (struct list *)malloc(sizeof(struct list));
    //创建头指针
    (*head)->next=NULL;
    (*head)->last=NULL;
    printf("空链表创建成功。\n");
}