#include<stdio.h>
#include"Struct.h"
extern LinkStackPtr input();
extern LinkStackPtr exchange(LinkStackPtr head1);
extern int calculate(LinkStackPtr head);
int main(){
    while(1){
        LinkStackPtr head=NULL,p=NULL;
        LinkStack stack;
        head=input();
        head=exchange(head);
        if(head!=NULL){
            calculate(head);
        }
        putchar('\n');
    }
}