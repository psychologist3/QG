#include"Struct.h"
LinkQueue * EnQueue(LinkQueue *Q){
    if(Q==NULL){
        printf("请先创建队列;\n");
    }
    else if(Q->tail==NULL){
        fflush(stdin);
        printf("请输入要入队的内容:");
        scanf("%s",Q->head->word);
        Q->tail=Q->head;
        printf("入队成功；\n");
    }
    else if(Q->tail->next!=Q->head){
        fflush(stdin);
        printf("请输入要入队的内容:");
        scanf("%s",Q->tail->next->word);
        Q->tail=Q->tail->next;
        printf("入队成功；\n");
    }
    else{
        printf("队列已满,无法入队\n");
    }
    return Q;

}