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
    printf("����Ҫ�����೤�Ķ���:  ");
    int number;
    scanf("%d",&number);
    for (int i = 1; i < number; i++)
    {
        p=p->next=(QNode*)malloc(sizeof(QNode));
        p->next=NULL;
    }
    p->next=Q->head;
    printf("�ɹ��������С�\n");
    return Q;
}