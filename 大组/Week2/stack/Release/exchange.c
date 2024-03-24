#include<stdio.h>
#include"Struct.h"
#include<stdlib.h>
extern LinkStackPtr push(LinkStack stack,int word);
extern LinkStackPtr pop(LinkStack stack,int *word);
extern LinkStackPtr Boundary(LinkStackPtr boundary);

LinkStackPtr exchange(LinkStackPtr head1){
    LinkStack linkstack={NULL,0}; 
    LinkStackPtr p1=NULL,p2=NULL;
    if(head1!=NULL){
        LinkStackPtr head2=(LinkStackPtr)malloc(sizeof(StackNode));
        p2=head2;
        p2->next=NULL;
        while(head1!=NULL){
            if(head1->word>='0'&&head1->word<="9"){
                p2->word=head1->word;
                while(head1->next!=NULL&&head1->next->word>='0'&&head1->next->word<="9"){
                    p1=head1;
                    head1=head1->next;
                    free(p1);
                    p2=p2->next=(LinkStackPtr)malloc(sizeof(StackNode));
                    p2->word=head1->word;
                }
                p2=Boundary(p2);
            }else if(head1->word=='+'||head1->word=='-'||head1->word=='*'||head1->word=='/'){
                while(linkstack.top!=NULL&&((linkstack.top->word=='*'||linkstack.top->word=='/')||((linkstack.top->word=='+'||linkstack.top->word=='-')&&(head1->word=='+'||head1->word=='-')))){
                    linkstack.top=pop(linkstack,&p2->word);
                    p2=Boundary(p2);
                }
                linkstack.top=push(linkstack,head1->word);
            }else if(head1->word=='('){
                linkstack.top=push(linkstack,head1->word);
            }else if(head1->word==')'){
                while(linkstack.top!=NULL&&linkstack.top->word!='('){
                    linkstack.top=pop(linkstack,&p2->word);
                    p2=Boundary(p2);
                }
                if(linkstack.top->word=='('){
                    linkstack.top=pop(linkstack,&p2->word);
                }
            }else if(head1->word==' '){

            }
            else{
                printf("存在非法字符,无法计算,请重新输入。\n");
                while(head1!=NULL){
                    p1=head1;
                head1=head1->next;
                free(p1);
                }
                while(head2!=NULL){
                    p1=head2;
                head2=head2->next;
                free(p1);
                }
                return NULL;
            }
            p1=head1;
            head1=head1->next;
            free(p1);
        }
        while(linkstack.top!=NULL){
            linkstack.top=pop(linkstack,&p2->word);
            p2=Boundary(p2);
        } 
        return head2;
}
    }
   

LinkStackPtr Boundary(LinkStackPtr boundary){
    boundary=boundary->next=(LinkStackPtr)malloc(sizeof(StackNode));
    boundary->word=' ';
    boundary=boundary->next=(LinkStackPtr)malloc(sizeof(StackNode));
    boundary->word=' ';
    boundary->next=NULL;
    return boundary;
}