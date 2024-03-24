#include"Struct.h"
#include"hh.h"
int main(){
    int choose = 0;
    LinkQueue *Queue=NULL;
    while(choose!=11){
        printf("\n1.构造队列        2.销毁队列\n");
        printf("3.入队            4.出队\n");
        printf("5.清空            6.查看对头\n");
        printf("7.判满            8.判空\n");
        printf("9.队列长度        10.遍历队列\n");
        printf("11.退出\n");
        printf("请输入你的选择:");
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
            case 9:printf("队列长度为%d\n",LengthQueue(Queue));break;
            case 10:TraverseQueue(Queue);
            case 11:break;
            default:printf("请输入正确的选择,别乱搞。");
        }
    }

}
