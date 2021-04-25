#include<stdio.h>
#include<stdlib.h>
#include"ss.h"
void giveBlock(stack **top, int i){
    stack *temp = *top;
    temp = (stack*)malloc(sizeof(stack));
    temp->data = i;
    temp->next = NULL;
    *top = temp;
}
int main(){
    int i;
    stack *top = NULL,*end = NULL,*temp = NULL;
    while(i!=-1){
        printf("Enter: ");
        scanf("%d",&i);
        if(i == -1){
            continue;
        } else{
            if(top == NULL){
                giveBlock(&top,i);
                end = top;
            } else{
                giveBlock(&temp,i);
                if(i<top->data){
                    temp->next = top;
                    top = temp;
                } else{
                    end->next = temp;
                    end = temp;
                }
            }
        }
    }
    displayI(top);
    printf("\n%d",top->data);
    return 0;
}