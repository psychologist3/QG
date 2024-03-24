#include"Struct.h"
void TraverseQueue(LinkQueue*Q){
    if(Q==NULL){
        printf("请先创建队列\n");
    }else if(Q->tail==NULL){
         printf("队列中没有内容,请先添加数据到队列;\n");
    }else{
        printf("队列中数据内容有：\n");
        int count=1;
        QueuePtr p;
        for(p=Q->head;p!=Q->tail;p=p->next,count++){
            printf("%d . %s\n",count,p->word);
        }
        printf("%d . %s\n",count,p->word);
    }

}