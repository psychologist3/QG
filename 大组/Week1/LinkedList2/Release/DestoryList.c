#include"SturctList.h"

//��������
void destoryList(struct list *head){
    if(head==NULL){
        printf("�����������,���ȴ�������");
    }
    else {
        //��������
        struct list* p = head->next;
        for(;p!=NULL;){
            free(head);
            head=p;
            p=p->next;
        }
        free(head);
    }

}