#include"Struct.h"
int LengthQueue(LinkQueue*Q){
    QueuePtr p=Q->head;
    int count=0;
    do{
        count++;
        p=p->next;
    }while(p!=Q->head);
    return count;
}