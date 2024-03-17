#include"StructList.h"
#include"Statement.h"

int main(){
    //定义链表头指针
    struct list * head=NULL;
    //输出菜单  
    //定义变量
    int choose = 0; 
    for(;choose!=7;){
        printf("1.创建空链表\n");
        printf("2.销毁链表\n");
        printf("3.插入结点\n");
        printf("4.删除结点\n");
        printf("5.查找链表\n");
        printf("6.奇偶互换\n");
        printf("7.退出\n");
        printf("====================================\n");
        printf("请输入要执行的操作对应的数字:  ");
        scanf("%d",&choose);
        system("cls");
        switch(choose){
            case 1 :createList(&head);break;
            case 2 :destoryList(head);
                    head=NULL;break;
            case 3:head=insertNode(head);break;
            case 4:head=deleteNode(head);break;
            case 5:seeknode(head);break;
            case 6:head=exchange(head);break;
            default:printf("无此选项,请宠信选择。");break;
        }
    }
    
}



