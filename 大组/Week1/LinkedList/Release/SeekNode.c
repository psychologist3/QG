#include"StructList.h"
//���ҽ��
void  seeknode(struct list*head){
    int number=0;
    if(head==NULL){
        printf("������ɲ���,���ȴ�������\n");
    }else{
        
        printf("Ҫ���ҵڼ�����㣺 ");
        scanf("%d",&number);
        int i = 1;
        for(;i<number&&head!=NULL;i++){
            head=head->next;
            }
        if(head==NULL){
                printf("�����н���%d�����, �����ڵ�%d�����\n",i-1,number);
            }
        else{
            printf("�ɹ����ҵ���%d�����\n",number);
        }
    }
    
}