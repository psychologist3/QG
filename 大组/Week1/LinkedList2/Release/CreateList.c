#include"SturctList.h"
void destoryList(struct list *head);

void creatList(struct list** head){
    if(*head != NULL){
        //������Ϊ�������������پ�����
        destoryList(*head);
    }
    *head = (struct list *)malloc(sizeof(struct list));
    //����ͷָ��
    (*head)->next=NULL;
    (*head)->last=NULL;
    printf("���������ɹ���\n");
}