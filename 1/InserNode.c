#include"StructList.h"
//������
struct list* insertNode(struct list *head){
    if(head==NULL){
        printf("������ɲ���,���ȴ�������\n");
    }
    else{
        int number = 0;
        struct list *node=(struct list*)malloc(sizeof(struct list)),*p=head;
        printf("����Ҫ���뵽�ڼ�����㣺");
        scanf("%d",&number);
        if(number==1){
            node->next =head;
            return node;
        }else{
            //���뵽��2�����ϵĽ��
            for(int i = 1;i < number-1;i++){
                p=p->next;
                if(p == NULL){
                    printf("���������%d�����,�����ڵ�%d����㡣\n",i,number);
                    return head;
                }
            }//����Ҫ���������һ�����
            node->next = p->next;
            p->next =node;
            printf("�ɹ����뵽��%d�����",number);
            return head;
        }
    }
}