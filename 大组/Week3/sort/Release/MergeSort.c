#include"record.h"
extern void print(numberpoint head);
extern  numberpoint hec(numberpoint p1,numberpoint p2);

numberpoint MergeSort(numberpoint head){
    numberpoint p1=head,p2=NULL;
    if(head->next!=NULL){
        p2=head->next;
        while(p2->next!=NULL){
            p1=p1->next;
            p2=p2->next;
            if(p2->next==NULL){
                break;
            }
            p2=p2->next;
            }
        p2=MergeSort(p1->next);
        p1->next=NULL;
        p1=MergeSort(head);    
    }
    return hec(p1,p2);
    

}

numberpoint hec(numberpoint p1,numberpoint p2){
    numberpoint p,point,p2_next;
    if(p1==NULL){
        return p2;
    }
    if(p2==NULL){
        return p1;
    }
    p=p1->num <p2->num ?p1:p2;
    point=p;
    while(1){
        if(point==p1){
            p1=p1->next;
            if(p1==NULL){
                point->next=p2;
                return p;
            }
            if(p2==NULL){
                point->next=p1;
                return p;
            }
            point=point->next=p1->num <p2->num ?p1:p2;
        }else if(point==p2){
            p2=p2->next;
            if(p1==NULL){
                point->next=p2;
                return p;
            }
            if(p2==NULL){
                point->next=p1;
                return p;
            }
            point=point->next=p1->num <p2->num ?p1:p2;
        }

        
        
        /*if(p1!=NULL&&p2!=NULL){
        p=p1->num <p2->num ?p1:p2;
        if(p==p1){
            for(;p1->next!=NULL && p1->next->num < p2->num;p1=p1->next);
            p1->next=hec(p1->next,p2);
        }else{
            for(;p2->next!=NULL && p2->next->num < p1->num;p2=p2->next);
            p2->next=hec(p2->next,p1);
        }
        return p;
    }else if(p1==NULL){
        return p2;
    }
    else {
        return p1;
    }*/
    }
    
}