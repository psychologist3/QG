#include"SturctList.h"

//销毁链表
void destoryList(struct list *head){
    if(head==NULL){
        printf("无链表可销毁,请先创建链表");
    }
    else {
        //链表销毁
        struct list* p = head->next;
        for(;p!=NULL;){
            free(head);
            head=p;
            p=p->next;
        }
        free(head);
    }

}