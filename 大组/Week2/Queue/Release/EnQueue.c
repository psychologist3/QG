#include"Struct.h"
LinkQueue * EnQueue(LinkQueue *Q){
    if(Q==NULL){
        printf("���ȴ�������;\n");
    }
    else if(Q->tail==NULL){
        fflush(stdin);
        printf("������Ҫ��ӵ�����:");
        scanf("%s",Q->head->word);
        Q->tail=Q->head;
        printf("��ӳɹ���\n");
    }
    else if(Q->tail->next!=Q->head){
        fflush(stdin);
        printf("������Ҫ��ӵ�����:");
        scanf("%s",Q->tail->next->word);
        Q->tail=Q->tail->next;
        printf("��ӳɹ���\n");
    }
    else{
        printf("��������,�޷����\n");
    }
    return Q;

}