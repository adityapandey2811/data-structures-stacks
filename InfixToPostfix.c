#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"CStack.h"
#include<ctype.h>
int priority(char i){
    if(i == '(')
        return 0;
    else if(i == '+' || i == '-')
        return 1;
    else if(i == '*' || i == '/')
        return 2;
}
void infixToPostfix(char arr[]){
    char *i,x;
    Stack *top = NULL;
    i = arr;
    while(*i!='\0'){
        if(isalnum(*i))
            printf("%c",*i);
        else if(*i == '('){
            top = pushC(top, *i);
        }
        else if(*i == ')'){ 
            while(top->data != '('){
                printf("%c",top->data);
                top = pop(top);
            }
            top = pop(top);
        }
        else{
            while(top!=NULL && priority(top->data) >= priority(*i)){
                printf("%c",top->data);
                top = pop(top);
            }
            top = pushC(top, *i);
        }
        i++;
    }
    while(top!=NULL){
        printf("%c",top->data);
        top = pop(top);
    }
}
void main(){
    char arr[100];
    printf("Enter function: ");
    scanf("%[^\n]",arr);
    infixToPostfix(arr);
}