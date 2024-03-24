#include"Struct.h"
LinkQueue * DeQueue(LinkQueue *Q){
    if(Q==NULL){
        printf("请先创建队列\n");
         
    }else if(Q->tail==NULL){
         printf("队列中没有内容,请先添加数据到队列;\n");
    }
    else{
        printf("出队的数据是:\n");
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