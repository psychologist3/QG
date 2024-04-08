#include"record.h"
treepoint preorder (treepoint root){//先序
    if(root==NULL){
        printf("没有数据");
    }else {
        printf("%d ",root->number);
        if(root->left!=NULL){
            preorder(root->left);
        }
         if(root->right!=NULL){
            preorder(root->right);
        }
        
    }

}

treepoint preorder2 (treepoint root){
    if(root==NULL){
        printf("没有数据");
    }else {
        Stack stack=(Stack)malloc(sizeof(Queue)),p;
        stack->head=root;
        stack->next=NULL;
        while(stack!=NULL){
            root=stack->head;
            p=stack;
            stack=stack->next;
            free(p);
            printf("%d ",root->number);
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

        }
        

    }
}