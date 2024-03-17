#include"StructList.h"
//µ¥Á´±íÆæÅ¼µ÷»»
struct list * exchange(struct list*head){
    struct list* p1 =head,*p2=NULL,*p3=NULL;
    if(head->next==NULL){
        return head;
    }
    else{
        head=head->next;
    }
    for(;p1!=NULL&&p1->next!=NULL;){
        p2=p1->next;
        p1->next=p2->next;
        p2->next=p1;
        if(p3!=NULL){
            p3->next=p2;
        }
        p3=p1;
        p1=p1->next; 
        }
    return head;
}
    