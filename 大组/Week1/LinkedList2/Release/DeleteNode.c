#include"SturctList.h"
//删除结点
struct list *deleteNode(struct list *head){
    if(head==NULL){
        printf("无链表可查找,请先创建链表");
    }
    else{
        struct list *p=head, *node=NULL; 
        int number =0 ;
        printf("要删除哪一个结点：");
        scanf("%d",&number);
        if(number==1){
            p=p->next;
            if(p!=NULL){
                p->last=NULL;
            }
            free(head);
            return p;
        }else{
            //删除第2个及以上的结点
            int i = 1;
            for(;i < number-1&&p->next!=NULL;i++){
                p=p->next;
            }//查找要删除结点的上一个结点
            if(p->next==NULL){
                    printf("链表中仅有%d个结点, 不存在第%d个结点",i,number);
                    return head;
                }
            node=p->next;
            p->next=node->next;
            if(p->next!=NULL){
                (p->next)->last=p;
            }
            free(node);
            printf("成功删除第%d个结点",number);
            return head;
        }
    }


}