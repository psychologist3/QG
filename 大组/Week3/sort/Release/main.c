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
            printf("1.�ֶ���������\n2.�����������\n3.�����ļ����ݡ�");
            printf("���������ѡ��");
            fflush(stdin);
            scanf("%d",&choose);
            if(choose>=1&&choose<=3){
                break;
            }else{
                system("cls");
                printf("������1,2��3\n");
            }
        }while(1);
            switch (choose){
                case 1: head=Scanf();break;
                case 2:{
                            printf("Ҫ���ɶ��ٸ������");
                            fflush(stdin);
                            scanf("%d",&number);
                            head=Random(number);
                            do{
                                printf("�Ƿ�����ݱ���Ϊ�ļ�number\n1Ϊ��  2Ϊ��\n");
                                fflush(stdin);
                                scanf("%d",&choose);
                                if(choose<=2&&choose>=1){
                                    break;
                                }
                                printf("��ѡ1��2 ,����ѡ,лл��\n");
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
            printf("1.��������     2.�鲢����\n3.��������     4.��������\n5.��������\n");
            printf("���������ѡ��");
            fflush(stdin);
            scanf("%d",&choose);
            if(choose>=1&&choose<=5){
                break;
            }else{
                system("cls");
                printf("������1��5֮�������\n");
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
            printf("�������Ϊ:\n");
            print(head);
            printf("����ʱ %d ms\n",diff);
        }else{
            printf("�������,����ʱ %d ms\n��������result�ļ���",diff);
        }
    }
}

    numberpoint Scanf(void){
        printf("������һ�����֣�\n");
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
        printf("���ļ�ʧ��");
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