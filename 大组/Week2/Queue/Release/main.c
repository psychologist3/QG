#include"Struct.h"
#include"hh.h"
int main(){
    int choose = 0;
    LinkQueue *Queue=NULL;
    while(choose!=11){
        printf("\n1.�������        2.���ٶ���\n");
        printf("3.���            4.����\n");
        printf("5.���            6.�鿴��ͷ\n");
        printf("7.����            8.�п�\n");
        printf("9.���г���        10.��������\n");
        printf("11.�˳�\n");
        printf("���������ѡ��:");
        fflush(stdin);
        scanf("%d",&choose);
        system("cls");
        switch(choose){
            case 1:Queue=CreateQueue(Queue); break;
            case 2:Queue=DestoryQueue(Queue);break;
            case 3:Queue=EnQueue(Queue);break;
            case 4:Queue=DeQueue(Queue);break;
            case 5:Queue=ClearQueue(Queue);break;
            case 6:GetHeadQueue(Queue);break;
            case 7:IsEmptyQueue(Queue);break;
            case 8:IsFullQueue(Queue); break;
            case 9:printf("���г���Ϊ%d\n",LengthQueue(Queue));break;
            case 10:TraverseQueue(Queue);
            case 11:break;
            default:printf("��������ȷ��ѡ��,���Ҹ㡣");
        }
    }

}
