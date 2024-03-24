#include"Struct.h"
#include<stdio.h>
#include<stdlib.h>
extern LinkStackPtr push(LinkStack stack,int word);
extern LinkStackPtr pop(LinkStack stack,int *word);

int calculate(LinkStackPtr head){
    LinkStack stack={NULL,0};
    LinkStackPtr p=NULL;
    int result=0,number=0;
    while(head!=NULL){
        if(head->word==' '){

        }else if(head->word>='0'&&head->word<='9'){
                stack.top=push(stack,head->word-'0');
                while(head->next!=NULL&&head->next->word>='0'&&head->next->word<='9'){
                    head=head->next;
                    stack.top=pop(stack,&number);
                    number=number*10+head->word-'0';
                    stack.top=push(stack,number);
                }
            }else if(stack.top!=NULL&&stack.top->next!=NULL){
                stack.top=pop(stack,&result);
                stack.top=pop(stack,&number);
                if(head->word=='+'){ 
                    result+=number;
                    stack.top=push(stack,result);
                }else if(head->word=='-'){
                    result=number-result;
                    stack.top=push(stack,result);
                }else if (head->word=='*'){    
                    result*=number;
                    stack.top=push(stack,result);
                }else if (head->word=='/')
                {   
                    result=number/result;
                    }
                stack.top=push(stack,result);
                
            }else{
                printf("表达式有误\n");
                while(head!=NULL){
                    p=head;
                    head=head->next;
                    free(p);
                }
                while(stack.top!=NULL){
                    stack.top=pop(stack,NULL);
                }
                return 0;
            }

        p=head;
        head=head->next;
        free(p);
        
    }
    stack.top=push(stack,NULL);
    printf("答案为:%d\n",result);
    
}