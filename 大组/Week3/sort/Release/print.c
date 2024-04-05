#include"record.h"
void print(numberpoint head){
    for(int i=1;head!=NULL;head=head->next,i++){
        printf("%8d ",head->num);
        if(i==10){
            i=0;
            putchar('\n');
        }
    }
    putchar('\n');
}