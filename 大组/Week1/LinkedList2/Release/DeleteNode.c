#include"SturctList.h"
//ɾ�����
struct list *deleteNode(struct list *head){
    if(head==NULL){
        printf("������ɲ���,���ȴ�������");
    }
    else{
        struct list *p=head, *node=NULL; 
        int number =0 ;
        printf("Ҫɾ����һ����㣺");
        scanf("%d",&number);
        if(number==1){
            p=p->next;
            if(p!=NULL){
                p->last=NULL;
            }
            free(head);
            return p;
        }else{
            //ɾ����2�������ϵĽ��
            int i = 1;
            for(;i < number-1&&p->next!=NULL;i++){
                p=p->next;
            }//����Ҫɾ��������һ�����
            if(p->next==NULL){
                    printf("�����н���%d�����, �����ڵ�%d�����",i,number);
                    return head;
                }
            node=p->next;
            p->next=node->next;
            if(p->next!=NULL){
                (p->next)->last=p;
            }
            free(node);
            printf("�ɹ�ɾ����%d�����",number);
            return head;
        }
    }


}