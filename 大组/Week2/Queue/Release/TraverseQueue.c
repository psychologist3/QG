#include"Struct.h"
void TraverseQueue(LinkQueue*Q){
    if(Q==NULL){
        printf("���ȴ�������\n");
    }else if(Q->tail==NULL){
         printf("������û������,����������ݵ�����;\n");
    }else{
        printf("���������������У�\n");
        int count=1;
        QueuePtr p;
        for(p=Q->head;p!=Q->tail;p=p->next,count++){
            printf("%d . %s\n",count,p->word);
        }
        printf("%d . %s\n",count,p->word);
    }

}