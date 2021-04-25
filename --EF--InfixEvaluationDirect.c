#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"ss.h"
int priority(char x){
    if(x == '(')
        return 0;
    else if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
    return -1;
}
int cal(char v1, char v2, char op){
    int i1 = (int)v1-48,i2 = (int)v2-48;
    if(op == '+')
        i1+=i2;
    else if(op == '-')
        i1-=i2;
    else if(op == '*')
        i1*=i2;
    else if(op == '/')
        i1/=i2;
    return i1;
}
void evaluate(char exp[]){
    int i=0;
    char *x = exp,c;
    stack *optor = NULL,*opand = NULL;
    while(*x!='\0'){
        if(isalnum(*x)){
            pushing(&opand,*x);
        }
        else if(*x == '('){
            pushing(&optor,*x);
        }
        else if(*x == ')'){
            while(optor->val!='('){
                c = pop(&optor);
                if(c!='('){
                    i = cal(opand->next->val,opand->val,c);
                    pop(&opand);
                    pop(&opand);
                    pushing(&opand,i+48);
                }
            }
            pop(&optor);
        }
        else{
            while(optor!=NULL && priority(optor->val) >= priority(*x)){
                c = pop(&optor);
                if(c!='('){
                    i = cal(opand->next->val,opand->val,c);
                    pop(&opand);
                    pop(&opand);
                    pushing(&opand,i+48);
                }
            }
            pushing(&optor,*x);
        }
        x++;
    }
    while(optor!=NULL){
        c = pop(&optor);
        i = cal(opand->next->val,opand->val,c);
        pop(&opand);
        pop(&opand);
        pushing(&opand,i+48);
    }
    printf("\nAnswer: %c",opand->val);
}
int main(){
    char str[100];
    printf("Enter: ");
    scanf("%s",str);
    evaluate(str);
    return 0;
}