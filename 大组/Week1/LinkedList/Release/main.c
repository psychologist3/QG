#include"StructList.h"
#include"Statement.h"

int main(){
    //��������ͷָ��
    struct list * head=NULL;
    //����˵�  
    //�������
    int choose = 0; 
    for(;choose!=7;){
        printf("1.����������\n");
        printf("2.��������\n");
        printf("3.������\n");
        printf("4.ɾ�����\n");
        printf("5.��������\n");
        printf("6.��ż����\n");
        printf("7.�˳�\n");
        printf("====================================\n");
        printf("������Ҫִ�еĲ�����Ӧ������:  ");
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
            default:printf("�޴�ѡ��,�����ѡ��");break;
        }
    }
    
}



