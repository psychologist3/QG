#include"Struct.h"
extern int LengthQueue(LinkQueue *Q);

LinkQueue *IsFullQueue(LinkQueue*Q){
    if(Q==NULL){
        printf("���ȴ�������\n");
         
    }else {
        if(Q->tail==NULL){
            printf("����δ��,�����Բ���%d�����ݡ�\n",LengthQueue(Q));
        }else{
            int count=1;
            while (Q->head!=Q->tail)
            {
                count++;
            }
            printf("����δ��,�����Բ���%d�����ݡ�\n",LengthQueue(Q)-count);
        }
    }
    return Q;

}