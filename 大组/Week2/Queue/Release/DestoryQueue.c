#include"Struct.h"
LinkQueue* DestoryQueue(LinkQueue *Q){
    if(Q==NULL){
        printf("�޶��п�����,���ȴ�������\n");
        return 0;
    }
    QueuePtr p1=Q->head,p2=p1->next;
    p1->next=NULL;
    while (p2!=NULL)
    {   
        p1=p2;
        p2=p2->next;
        free(p1);
    }
    printf("����������ɡ�\n");
    return NULL;
}