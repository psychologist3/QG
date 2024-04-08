#include"record.h"
treepoint Postorder(treepoint root ){//后序
    if(root==NULL){
        printf("没有数据");
    }else {
        
        if(root->left!=NULL){
            Postorder(root->left);
        }
        
         if(root->right!=NULL){
            Postorder(root->right);
        }
        printf("%d ",root->number);
    }

}
treepoint Postorder2(treepoint root ){
    if(root==NULL){
        printf("没有数据");
    }else {
        Stack stack=(Stack)malloc(sizeof(Queue)),p,stack2=NULL;
        stack->head=root;
        stack->next=NULL;
        while(stack!=NULL){
            root=stack->head;
            p=stack;
            stack=stack->next;
            p->next=stack2;
            stack2=p;
            
            if(root->left!=NULL){
                p=(Stack)malloc(sizeof(Queue));
                if(stack!=NULL){    
                    p->next=stack;
                }else{
                    p->next=NULL;
                }
                stack=p;
                stack->head=root->left;
            }
            if(root->right!=NULL){
                p=(Stack)malloc(sizeof(Queue));
                if(stack!=NULL){ 
                    p->next=stack;                
                }else{
                    p->next=NULL;
                }
                stack=p;
                stack->head=root->right;
            }
        }
        while (stack2!=NULL)
        {
            p=stack2;
            stack2=stack2->next;
            printf("%d ",p->head->number);
            free(p);
        }
        
    }
}