#include"Struct.h"
LinkQueue *GetHeadQueue(LinkQueue*Q){
    if(Q==NULL){
        printf("���ȴ�������\n");
         
    }else if(Q->tail==NULL){
         printf("������û������,����������ݵ�����;\n");
    }else {
        printf("��ͷ������Ϊ:\n");
        printf("%s\n",Q->head->word);
    }
    return Q;

}