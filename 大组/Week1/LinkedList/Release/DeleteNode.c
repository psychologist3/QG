#include"StructList.h"
//ɾ������
struct list *deleteNode(struct list *head){
    if(head==NULL){
        printf("������ɲ���,���ȴ�������\n");
    }
    else{
        struct list *p=head, *node=NULL; 
        int number =0 ;
        printf("Ҫɾ����һ����㣺");
        scanf("%d",&number);
        if(number==1){
            p=p->next;
            free(head);
            return p;
        }else{
            //ɾ����2�������ϵĽ��
            int i = 1;
            for(;i < number-1&&p->next!=NULL;i++){
                p=p->next;
            }//����Ҫɾ���Ľ�����һ�����
            if(p->next == NULL){
                    printf("���������%d�����,�����ڵ�%d����㡣\n",i,number);
                    return head;
                }
            node=p->next;
            p->next=node->next;
            free(node);
            printf("�ɹ�ɾ����%d�����\n",number);
            return head;
        }
    }
}