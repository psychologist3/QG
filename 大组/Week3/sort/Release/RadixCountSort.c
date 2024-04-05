#include"record.h"
extern void print(numberpoint head);
extern numberpoint point(numberpoint head,int n);
extern  int wei(int number,int n);

typedef struct sort{    
    numberpoint sort;
    struct sort *next;
}sort;
typedef struct Queue{
    sort *head;
    sort *end;
}Queue;

void addQueue(Queue *Q,numberpoint p){
    if((*Q).head==NULL){
        (*Q).head=(sort*)malloc(sizeof(sort));
        (*Q).end=(*Q).head;
    }else{
        (*Q).end=(*Q).end->next=(sort*)malloc(sizeof(sort));
        
    }
    (*Q).end->next=NULL;
    (*Q).end->sort=p;
}

numberpoint outQueue(Queue Q[10]){
    numberpoint head=NULL,p;
    sort *p1;
    for(int i=0;i<10;i++){
        if(Q[i].head!=NULL){
            if(head==NULL){
                p1=Q[i].head;
                head=p1->sort;
                p=head;
                Q[i].head=p1->next;
                free(p1);
            }
            for(;Q[i].head!=NULL;){
                p1=Q[i].head;
                p=p->next=p1->sort;
                Q[i].head=p1->next;
                free(p1);
            }
        }
    }
    p->next=NULL;
    return head;
    
}

numberpoint RadixCountSort(numberpoint head,int k){
    Queue Queue[10]={NULL};
    for(;head!=NULL;head=head->next){
        int n=wei(head->num,k);
        addQueue(&(Queue[n]),head);
    }
    int i=1;
    for(;i<10&&Queue[i].head==NULL;i++);
    if(i==10){
        head=outQueue(Queue);
        return head;
    }
    head=outQueue(Queue);
    head=RadixCountSort(head,k*10);
    return head;
    
}

int wei(int number,int n){
    return (number/n)%10;
}


