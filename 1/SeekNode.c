#include"StructList.h"
//查找结点
void  seeknode(struct list*head){
    int number=0;
    if(head==NULL){
        printf("无链表可查找,请先创建链表\n");
    }else{
        
        printf("要查找第几个结点： ");
        scanf("%d",&number);
        int i = 1;
        for(;i<number&&head!=NULL;i++){
            head=head->next;
            }
        if(head==NULL){
                printf("链表中仅有%d个结点, 不存在第%d个结点\n",i-1,number);
            }
        else{
            printf("成功查找到第%d个结点\n",number);
        }
    }
    
}