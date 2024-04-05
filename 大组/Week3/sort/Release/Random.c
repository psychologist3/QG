#include"record.h"
#include<time.h>
numberpoint Random(int number){
    srand(time(NULL));
    numberpoint head=(numberpoint)malloc(sizeof(number)),p=head;
    head->num=rand();
    p->last=NULL;
    for (int i = 1; i < number; i++)
    {
        p->next=(numberpoint)malloc(sizeof(number));
        p->next->last=p;
        p=p->next;
        p->num=rand();
    }
    p->next=NULL;
    return head;
}