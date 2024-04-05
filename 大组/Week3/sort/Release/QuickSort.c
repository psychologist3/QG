#include"record.h"
extern void print(numberpoint head);
extern void Sort2(numberpoint start,numberpoint end);
extern numberpoint Sort(numberpoint left,numberpoint right,int number);

numberpoint QuickSort(numberpoint head){
    if(head->next!=NULL){
        numberpoint right;
        right=head;
        int number=head->num;
        while (right->next!=NULL)
        {
            right=right->next;
        }
        Sort2(head,right);
    }
    return head;
    
}

void Sort2(numberpoint start,numberpoint end){
    if(start!=end&&start!=NULL&&end!=NULL){
        int number=start->num;
        numberpoint size =Sort(start,end,start->num);
        if(size!=start){
            Sort2(start,size->last);
        }
        
        if(size!=end){
            Sort2(size->next,end);
        }
    }
    
}

numberpoint Sort(numberpoint left,numberpoint right,int number){
    if(right==left) {
        return left;
    }
    numberpoint head=left;
    int n=1;
    while(1){
        if(right==left) {
            left->num=number;
            return left;
        }
        if(n==1){
            if(right->num < number){
                left->num=right->num;
                left=left->next;
                n=2;
            }else{
                right=right->last;
                n=1;
            }
        }else if(n==2){
            if(left->num > number){
                right->num=left->num;
                right=right->last;
                n=1;
            }else{
                left=left->next;
                n=2;
            }

        }
        
        
    }


    /*
    if(right==left) {
        return left;
    }
    if(n==1){
        if(right->num < number){
                left->num=right->num;
                return Sort(left->next,right,number,2);
            }else {
                return Sort(left,right->last,number,1);
            }
    }else if(n==2){
        if(left->num > number){
                right->num=left->num;
                return Sort(left,right->last,number,1);
            }else{
                return Sort(left->next,right,number,2);
            }
    }
    */
}