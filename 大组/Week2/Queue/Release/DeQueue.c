#include"Struct.h"
LinkQueue * DeQueue(LinkQueue *Q){
    if(Q==NULL){
        printf("���ȴ�������\n");
         
    }else if(Q->tail==NULL){
         printf("������û������,����������ݵ�����;\n");
    }
    else{
        printf("���ӵ�������:\n");
        printf("%s",Q->head->word);
        if(Q->head==Q->tail){
            Q->tail=NULL;
        }
        else{
            Q->head=Q->head->next;
        }
        
    }
    return Q;
}