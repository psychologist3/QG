#include"record.h"
treepoint Inorder(treepoint root ){//中序
    if(root==NULL){
        printf("没有数据");
    }else {
        if(root->left!=NULL){
            Inorder(root->left);
        }
        printf("%d ",root->number);
         if(root->right!=NULL){
            Inorder(root->right);
        }
        
    }

}
treepoint Inorder2(treepoint root ){
    if(root==NULL){
        printf("没有数据");
    }else {
        Stack stack=NULL,p;
        treepoint now=root;
        while(now!=NULL|| stack!=NULL){
            while(now!=NULL){
                p=(Stack)malloc(sizeof(Queue));
                if(stack!=NULL){    
                    p->next=stack;
                }else{
                    p->next=NULL;
                }
                stack=p;
                stack->head=now;
                now=now->left;
            }
            p=stack;
            stack=stack->next;
            now=p->head;
            printf("%d ",p->head->number);
            free(p);
            now=now->right;
        }
        
        
    }
}