#include"Struct.h"
extern int LengthQueue(LinkQueue *Q);

LinkQueue *IsEmptyQueue(LinkQueue*Q){
    if(Q==NULL){
        printf("请先创建队列\n");
         
    }else {
        if(Q->tail==NULL){
            printf("队列为空,还可以插入%d条数据。\n",LengthQueue(Q));
        }else{
            int count=1;
            while (Q->head!=Q->tail)
            {
                count++;
            }
            printf("队列不为空,还可以插入%d条数据。\n",LengthQueue(Q)-count);
        }
    }
    return Q;

}