#include"SturctList.h"

//��������
struct list* insertNode(struct list *head){
    if(head==NULL){
        printf("������ɲ���,���ȴ�������");
    }
    else{
        int number = 0;
        printf("����Ҫ���뵽�ڼ�����㣺");
        scanf("%d",&number);
        struct list *node=(struct list*)malloc(sizeof(struct list)),*p=head;
        if(number==1){
            node->next =head;
            head->last =node;
            node->last =NULL;
            return node;
        }else{
            //���뵽��2�����ϵĽ��
            for(int i = 1;i < number-1;i++){
                p = p->next;
                if(p == NULL){
                    printf("���������%d�����,�����ڵ�%d����㡣",i,number);
                    return head;
                }
            }//����Ҫ���������һ�����
            node->next = p->next;
            if(node->next!=NULL){//����Ϊĩ���
                (node->next)->last=node;
            }
            node->last=p;
            p->next =node;
            return head;
        }
    }
}

