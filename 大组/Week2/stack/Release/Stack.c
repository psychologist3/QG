#include<stdio.h>
#include"Struct.h"
#include<stdlib.h>

LinkStackPtr push(LinkStack stack,int word){
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    stack.count++;
    p->word=word;
    p->next=stack.top;
    stack.top=p;
    return stack.top;
}

LinkStackPtr pop(LinkStack stack,int *word){
    if(stack.top!=NULL){
        stack.count--;
        LinkStackPtr p = stack.top;
        stack.top=stack.top->next;
        if(word!=NULL&&p->word!='('){
            *word=p->word;
        }
        free(p);
        return stack.top;}
    
}

