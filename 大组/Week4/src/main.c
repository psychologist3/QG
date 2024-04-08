#include"record.h"
extern treepoint Scanf(void);
extern treepoint preorder (treepoint root);
extern treepoint Inorder(treepoint root );
extern treepoint Inorder2(treepoint root );
extern treepoint Postorder(treepoint root );
extern treepoint insert(treepoint root,int number);
extern treepoint find(treepoint root);
extern treepoint delete(treepoint root);
extern treepoint preorder2 (treepoint root);
extern treepoint Postorder2(treepoint root );
extern void destory(treepoint root);
extern void levelOrder(treepoint root);

int main(){
    treepoint root=NULL;
    int choose=0,number;
    while(1){
        do{
            printf("\n1.输入数据         2.插入数据\n");
            printf("3.先序遍历(递归)   4.先序遍历(非递归)\n");
            printf("5.中序遍历(递归)   6.中序遍历(非递归)\n");
            printf("7.后序遍历(递归)   8.后序遍历(非递归)\n");
            printf("9.查找数据         10.层序遍历\n");
            printf("请输入你的选择：\n");
            fflush(stdin);
            scanf("%d",&choose);    
            if(choose>=1&&choose<=10){
                break;
            }
            printf("请输入 1 到 10 之间的数字\n\n");
        }while (1);
        switch (choose)
        {
        case 1: if(root!=NULL){
                    destory(root);
                    root=NULL;
                }
                root=Scanf();
            break;
        case 2:printf("要插入什么数据：\n");
        fflush(stdin);
        scanf("%d",&number);
                root=insert(root,number);
                printf("插入成功");
                break;
        case 3:preorder(root);
            break;
        case 4:preorder2(root);break;
        case 5:Inorder(root);break;
        case 6:Inorder2(root);break;
        case 7:Postorder(root);break;
        case 8:Postorder2(root);break;
        case 9:find(root);break;
        case 10:levelOrder(root);break;
                }
    }
}

treepoint Scanf(void){
    treepoint root=NULL;
    printf("请输入一些数字\n");
    char word;
    fflush(stdin);
    word=getchar();
    for(;word <= '0' || word >= '9' ;word=getchar());
    int number = 0;
    while (1){
        while(word >= '0'&&word <= '9'){
            number = number*10 + word-'0';
            word=getchar();
            if(word<'0'||word>'9'){
                root=insert(root,number);
                number=0;
                break;
            }
        }
        if(word=='\n'){
            return root;
        }
        word=getchar();
    }
    return root;
}
void destory(treepoint root){
    if (root->left!=NULL)
    {
        destory(root->left);
    }
     if(root->right!=NULL){
        destory(root->right);
    }
    free(root);
}