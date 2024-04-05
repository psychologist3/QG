#include"record.h"
#include<windows.h>
#include<time.h>
extern void print(numberpoint head);
extern numberpoint InsertSort(numberpoint head);
extern numberpoint Scanf(void);
extern numberpoint MergeSort(numberpoint head);
extern numberpoint QuickSort(numberpoint head);
extern numberpoint CountSort(numberpoint head);
extern numberpoint RadixCountSort(numberpoint head,int n);
extern numberpoint Random(int number);
extern numberpoint destory(numberpoint head);
extern  void write(numberpoint head,int n);
extern numberpoint read(numberpoint head);

int main(){
    numberpoint head=NULL;
    int number=0;
    while(1){
        head=destory(head);
        int choose=0;
        do{ 
            printf("1.手动输入数字\n2.随机生成数字\n3.导入文件数据。");
            printf("请做出你的选择：");
            fflush(stdin);
            scanf("%d",&choose);
            if(choose>=1&&choose<=3){
                break;
            }else{
                system("cls");
                printf("请输入1,2或3\n");
            }
        }while(1);
            switch (choose){
                case 1: head=Scanf();break;
                case 2:{
                            printf("要生成多少个随机数");
                            fflush(stdin);
                            scanf("%d",&number);
                            head=Random(number);
                            do{
                                printf("是否把数据保存为文件number\n1为是  2为否\n");
                                fflush(stdin);
                                scanf("%d",&choose);
                                if(choose<=2&&choose>=1){
                                    break;
                                }
                                printf("请选1或2 ,别乱选,谢谢。\n");
                            }while(1);
                            if(choose==1){
                                write(head,1);
                            }
                            break;
                };
                case 3:head=read(head);
                        number=10000;break;
            } 
        do{
            printf("1.插入排序     2.归并排序\n3.快速排序     4.计数排序\n5.基数排序\n");
            printf("请做出你的选择：");
            fflush(stdin);
            scanf("%d",&choose);
            if(choose>=1&&choose<=5){
                break;
            }else{
                system("cls");
                printf("请输入1到5之间的数字\n");
            }
        }while(1);
        clock_t start=clock();
        switch (choose){
            case 1: head=InsertSort(head);break;
            case 2: head=MergeSort(head);break;
            case 3: head=QuickSort(head);break;
            case 4: head=CountSort(head);break;
            case 5: head=head=RadixCountSort(head,1);break;
        }
        clock_t diff=clock()-start;
        if(number<=5000){
            printf("排序后结果为:\n");
            print(head);
            printf("共费时 %d ms\n",diff);
        }else{
            printf("排序完成,共费时 %d ms\n排序结果在result文件。",diff);
        }
    }
}

    numberpoint Scanf(void){
        printf("请输入一串数字：\n");
        numberpoint head=(numberpoint)malloc(sizeof(number)),p=head;
        p->num=0;
        p->next=p->last=NULL;
        fflush(stdin);
        char word;
        word=getchar();
        while (word!='\n')
        {
            while(word>='0'&&word<='9'){
                p->num=p->num*10+word-'0';
                word=getchar();
                }
            word=getchar();
            if(word>='0'&&word<='9'){
                p->next=(numberpoint)malloc(sizeof(number));
                p->next->last=p;
                p=p->next;
                p->num=0;
                p->next=NULL;
            }
        }
        return head;
}

numberpoint destory(numberpoint head){
    for(numberpoint p1=head;head!=NULL;){
        p1=head;
        head=head->next;
        free(p1);
    }
    return NULL;
}

 void write(numberpoint head,int n){
    FILE *fp;
    if(n==1){
        fp=fopen("number","w");
    }
    else{
        fp=fopen("result","w");
    }
    for(int i=1;head!=NULL;head=head->next,i++){

            fprintf(fp,"%8d",head->num);
            if(i==10){
                i=0;
                fprintf(fp,"\n");
            }
        }
        fprintf(fp,"@");
        fclose(fp);
    }
    

 numberpoint read(numberpoint head){
    FILE *fp=fopen("number","r");
    if(fp==NULL){
        printf("打开文件失败");
        return NULL;
    }
    else{
        head=(numberpoint)malloc(sizeof(number));
        numberpoint p=head;
        p->next=p->last=NULL;
        char word;
        fscanf(fp,"%c",&word);
        while (word<='0'||word>='9')
        {
            fscanf(fp,"%c",&word);
        }
        while(word!='@'){
            while(word>='0'&&word<='9'){
                p->num=p->num*10+word-'0';
                fscanf(fp,"%c",&word);
                }
            fscanf(fp,"%c",&word);
            if (word>='0'&&word<='9'){
                p->next=(numberpoint)malloc(sizeof(number));
                p->next->last=p;
                p=p->next;
                p->num=0;
                p->next=NULL;
            }
        }
        
    }
    return head;
 }