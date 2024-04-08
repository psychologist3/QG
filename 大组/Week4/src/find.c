#include"record.h"
extern treepoint find1(treepoint root,int number);


treepoint find(treepoint root){
    int number=0;
    printf("请输入你要查找的数据；");
    fflush(stdin);
    scanf("%d",&number);
    root=find1(root,number);
    if(root==NULL){
        printf("查找不到数据: %d\n",number);
    }
    else{
        printf("查找到数据: %d\n",number);
    }
}

treepoint find1(treepoint root,int number){
    if(root==NULL){
        
        return NULL;
    }
    else{
        if(number == root->number){
            return root;
        }
        else if(number > root->number){
            return find1(root->right,number);
        }
        else{
            return find1(root->left,number);
        }
    }

}