#include"Struct.h"
LinkQueue *ClearQueue(LinkQueue*Q){
    if(Q==NULL){
        printf("���ȴ�������;\n");
    }else{
        Q->tail=NULL;
        printf("�����ɣ�\n");

    }
    return Q;
}