#include"Struct.h"
extern int LengthQueue(LinkQueue *Q);

LinkQueue *IsFullQueue(LinkQueue*Q){
    if(Q==NULL){
        printf("请先创建队列\n");
         
    }else {
        if(Q->tail==NULL){
            printf("队列未满,还可以插入%d条数据。\n",LengthQueue(Q));
        }else{
            int count=1;
            while (Q->head!=Q->tail)
            {
                count++;
            }
            printf("队列未满,还可以插入%d条数据。\n",LengthQueue(Q)-count);
        }
    }
    return Q;

}