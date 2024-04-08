#include"record.h"
treepoint insert(treepoint root,int number){
    if(root==NULL){
        root =(treepoint)malloc(sizeof(tree));
        root->left=root->right=NULL;
        root->number=number;
        return root;
    }
    else{
        treepoint leaf=root;
        while(1){
            if(number < leaf->number){
                if(leaf->left==NULL){
                    leaf=leaf->left=(treepoint)malloc(sizeof(tree));
                    leaf->left=leaf->right=NULL;
                    leaf->number=number;
                    return root;
                }
                else if(leaf->left!=NULL){
                    leaf=leaf->left;
                }
            }else if(number > leaf->number){
                if(leaf->right==NULL){
                    leaf=leaf->right=(treepoint)malloc(sizeof(tree));
                    leaf->left=leaf->right=NULL;
                    leaf->number=number;
                    return root;
                }
                else if(leaf->right!=NULL){
                    leaf=leaf->right;
                }
            }else{
                return root;
            }    
        }
    }
}