#include"record.h"
extern treepoint find1(treepoint root,int number);
extern treepoint directPredecessor(treepoint root);
extern treepoint delete1(treepoint root,int number);


treepoint delete(treepoint root){
    int number;
    printf("要删除哪个数据: \n ");
    fflush(stdin);
    scanf("%d",&number);
    if(find1(root,number)==NULL){
        printf("不存在数据  %d \n");
        return root;
    };
    return delete1(root,number);

}

treepoint delete1(treepoint root,int number){
    treepoint head=root;
    while (1){
        if(number > root->number){
            if(root->right==NULL){
                printf("不存在数据: %d\n",number);
                return NULL;
            }else{
                if(number !=root->right->number){
                    root=root->right;
                }else{
                    break;
                }
            }    
        }else if(number < root->number){
            if(root->left==NULL){
                printf("不存在数据: %d\n",number);
                return NULL;
            }else{
                if(number !=root->left->number){
                    root=root->left;
                }else{
                    break;
                }
            }
        }else if(root->number==number){
            break;
        }
    }
    treepoint left,right,p;
    if(number==root->number){
        left=root->left;
        right=root->right;
        p=directPredecessor(root);
        if(right==p){
            return p;
        }else{
            p->left=left;
            p->right=right;
            free(root);
        }
    }
    else if(number > root->number){
        left=root->right->left;
        right=root->right->right;
        p=directPredecessor(root->right);
        if(right==p){
            root->right=p;
            return p;
        }else{
            p->left=left;
            p->right=right;
            free(root->right);
            root->right=p;
        }
        
    }else if(number < root->number){
        left=root->left->left;
        right=root->left->right;
        p=directPredecessor(root->left);
        if(right==p){
            root->right=p;
            return p;
        }else{
            p->left=left;
            p->right=right;
            free(root->left);
            root->left=p;
        }
        
    }
    return head;
}

treepoint directPredecessor(treepoint root){
    treepoint p=root,last=NULL;
    int number=root->number;
    if(root->left==NULL){
        p=root->right;
        free(root);
        return p;
    }else{
        root=root->left;
    }
    while (1){
        if(root->right!=NULL){
            last=root;
            root=root->right;            
        }else{
            if(root->left==NULL){
                last->right=NULL;
                return root;
            }else{
                last->right=root->left;
                return root;
            }
        }
    }
}
