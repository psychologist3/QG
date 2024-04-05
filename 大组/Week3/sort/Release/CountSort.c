#include"record.h"
extern int max(int number,numberpoint head);
extern int min(int number,numberpoint head);
extern numberpoint point(numberpoint head,int n);
extern void print(numberpoint head);
extern numberpoint destory(numberpoint head);;

numberpoint CountSort(numberpoint head){
    int maxNumber=max(head->num,head->next);
    int minNumber=min(head->num,head->next);
    numberpoint head1=(numberpoint)malloc(sizeof(number)),p=head1;
    p->num=0;
    p->next=NULL;
    for(int i=0;i < maxNumber-minNumber;i++){
        p=p->next=(numberpoint)malloc(sizeof(number));
        p->num=0;
        p->next=NULL;
    }
    for(p=head;p!=NULL;p=p->next){
        point(head1,p->num-minNumber)->num++;
    }
    p=head;
    for(int i=0;i <= maxNumber-minNumber;i++){
        for(;point(head1,i)->num>0;point(head1,i)->num--){
            p->num=minNumber+i;
            p=p->next;
        }
    }
    destory(head1);
    return head;
}

int max(int number,numberpoint head){
    for(;head!=NULL;head=head->next){
        if(number < head->num){
            number=head->num;
        }
    }
    return number;
}

int min(int number,numberpoint head){
    for(;head!=NULL;head=head->next){
        if(number > head->num){
            number=head->num;
        }
    }
    return number;
}

numberpoint point(numberpoint head,int n){
    for(int i=0;i<n;i++){
        head=head->next;
    }
    return head;
}