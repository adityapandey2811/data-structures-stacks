#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"ss.h"
int priority(char i){
    if(i == '(')
        return 0;
    else if(i == '+' || i == '-')
        return 1;
    else if(i == '*' || i == '/')
        return 2;
    return -1;
}
void postfix(char str[]){
    stack *top = NULL;
    int i, j = 0;
    char arr[100], c = '\0';
    for(i=0; str[i]!='\0'; i++){
        if(isalnum(str[i])){
            printf("%c",str[i]);
        }
        else if(str[i] == '('){
            pushing(&top, str[i]);
        }
        else if(str[i] == ')'){
            while(c != '('){
                c = pop(&top);
                if(c != '(')
                    printf("%c",c);
            }
        }
        else{
            while(top != NULL && priority(top->val) >= priority(str[i])){
                c = pop(&top);
                printf("%c",c);
            }
            pushing(&top, str[i]);
        }
    }
    while(!isEmpty(top)){
        printf("%c",pop(&top));
    }
}
int main(){
    int i;
    char str[100];
    stack *top = NULL;
    printf("Enter Expression: ");
    scanf("%[^\n]",str);
    postfix(str);
}