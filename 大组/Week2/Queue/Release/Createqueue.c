#include"Struct.h"
extern LinkQueue* DestoryQueue(LinkQueue *Q);
LinkQueue *CreateQueue(LinkQueue*Q){
    if(Q!=NULL){
        Q=CreateQueue(Q);
    }
    Q=(LinkQueue*)malloc(sizeof(LinkQueue));
    Q->head=(QNode*)malloc(sizeof(QNode));
    Q->tail=NULL;
    QNode* p = (Q->head);
    printf("请问要创建多长的队列:  ");
    int number;
    scanf("%d",&number);
    for (int i = 1; i < number; i++)
    {
        p=p->next=(QNode*)malloc(sizeof(QNode));
        p->next=NULL;
    }
    p->next=Q->head;
    printf("成功创建队列。\n");
    return Q;
}