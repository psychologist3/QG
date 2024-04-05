#include"record.h"
extern void print(numberpoint head);
extern void Insert(numberpoint k,numberpoint p);

numberpoint InsertSort(numberpoint head){
    numberpoint p =head;
    for(p =head->next;p!=NULL;){
        for(numberpoint k=p->last;;k=k->last){
            if (k==NULL){
                k=p;
                p=p->next;
                k->last->next=k->next;
                if(k->next!=NULL){
                    k->next->last=k->last;
                }
                k->next=head;
                head->last=k;
                k->last=NULL;
                head=k;
                break;
            }else if(k->num<p->num){
                if(p->next!=NULL){
                    p=p->next;
                    Insert(k,p->last);
                    }else{
                        Insert(k,p);
                        return head;
                    }
                
                break;
            }
            
        }
    }

}
void Insert(numberpoint k,numberpoint p){
    if(k->next!=p){
        numberpoint p1;
        p->last->next=p->next;
        if(p->next!=NULL){
            p->next->last=p->last;
        }
        p1=k->next;
        k->next=p;
        p1->last=p;
        k->next->last=k;
        p1->last->next=p1;
}
    }
    
    