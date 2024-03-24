#include"Struct.h"
LinkQueue *ClearQueue(LinkQueue*Q){
    if(Q==NULL){
        printf("请先创建队列;\n");
    }else{
        Q->tail=NULL;
        printf("清空完成；\n");

    }
    return Q;
}