#include"Struct.h"
LinkQueue *GetHeadQueue(LinkQueue*Q){
    if(Q==NULL){
        printf("请先创建队列\n");
         
    }else if(Q->tail==NULL){
         printf("队列中没有内容,请先添加数据到队列;\n");
    }else {
        printf("队头的数据为:\n");
        printf("%s\n",Q->head->word);
    }
    return Q;

}