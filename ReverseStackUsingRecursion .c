#include<stdio.h>
#include<stdlib.h>
#include"ss.h"
stack *rev = NULL;
stack* insertReverse(char x){
    pushing(&rev,x);
    return rev;
}
stack* reverse(stack *top){
    char i;
    if(top!=NULL){
        i = pop(&top);
        rev = insertReverse(i);
        reverse(top);
    }
    else{
        return NULL;
    }
    return rev;
}
int main(){
    int i;
    stack *top = NULL;
    for(i=1;i<=9;i++){
        pushing(&top,i+48);
    }
    display(top);
    top = reverse(top);
    printf("\n");
    display(top);
    return 0;
}