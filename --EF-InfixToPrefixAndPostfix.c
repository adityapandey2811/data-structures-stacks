#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"CStack.h"
void reverse(char arr[]){
    int i = 0, n = 0;
    char x;
    while(arr[n]!='\0'){
        if(arr[n] == '(')
            arr[n] = ')';
        else if(arr[n] == ')')
            arr[n] = '(';
        n++;
    }
    n--;
    while(i != n){
        x = arr[i];
        arr[i] = arr[n];
        arr[n] = x;
        i++;
        n--;
    }
}
int priority(char x){
    if(x == '(')
        return 0;
    else if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
}
void postfix(char *arr, int k){
    int i=0;
    char str[100];
    Stack *top = NULL;
    while(*arr != '\0'){
        if(isalnum(*arr)){
            // printf("%c",*arr);
            str[i] = *arr;
            i++;
        }
        else if(*arr == '(')
            top = pushC(top, *arr);
        else if(*arr == ')'){
            while(top->data != '('){
                // printf("%c",top->data);
                str[i] = top->data;
                i++;
                top = pop(top);
            }
            top = pop(top);
        }
        else{
            while(top != NULL && priority(top->data) >= priority(*arr)){
                // printf("%c",top->data);
                str[i] = top->data;
                i++;
                top = pop(top);
            }
            top = pushC(top, *arr);
        }
        arr++;
    }
    while(top!=NULL){
        // printf("%c",top->data);
        str[i] = top->data;
        i++;
        top = pop(top);
    }
    str[9] = '\0';
    if(k == 1){
        reverse(str);
        printf("Prefix: %s\n",str);
    }
    else{
        printf("Postfix: %s\n",str);
    }
}
void main(){
    char arr[100];
    printf("Expression: ");
    scanf("%s",arr);
    postfix(arr,0);
    reverse(arr);
    printf("Reverse: %s\n",arr);
    postfix(arr,1);
}
