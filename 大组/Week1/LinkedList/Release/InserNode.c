#include"StructList.h"
//插入结点
struct list* insertNode(struct list *head){
    if(head==NULL){
        printf("无链表可查找,请先创建链表\n");
    }
    else{
        int number = 0;
        struct list *node=(struct list*)malloc(sizeof(struct list)),*p=head;
        printf("请问要插入到第几个结点：");
        scanf("%d",&number);
        if(number==1){
            node->next =head;
            return node;
        }else{
            //插入到第2个以上的结点
            for(int i = 1;i < number-1;i++){
                p=p->next;
                if(p == NULL){
                    printf("该链表仅有%d个结点,不存在第%d个结点。\n",i,number);
                    return head;
                }
            }//查找要插入结点的上一个结点
            node->next = p->next;
            p->next =node;
            printf("成功插入到第%d个结点",number);
            return head;
        }
    }
}