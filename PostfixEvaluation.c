#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
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
    int fval;
    char *x = exp;
    stack *top = NULL;
    while(*x!='\0'){
        if(isalnum(*x)){
            pushing(&top,*x);
        }
        else if(top->next!=NULL){
            fval = cal(top->next->val,top->val,*x);
            pop(&top);
            pop(&top);
            pushing(&top,fval+48);
        }
        else{
            break;
        }
        x++;
    }
    printf("Answer: %d",fval);
}
void postfix(char exp[]){
    int i=0;
    char c,arr[100],*n,*x;
    x = exp;
    stack *top = NULL;
    printf("Postfix: ");
    while(*x!='\0'){
        if(isalnum(*x)){
            printf("%c",*x);
            arr[i] = *x;
            i++;
        }
        else if(*x == '('){
            pushing(&top,*x);
        }
        else if(*x == ')'){
            while(top->val!='('){
                c = pop(&top);
                if(c != '('){
                    printf("%c",c);
                    arr[i] = c;
                    i++;
                }
            }
            if(top->val == '(')
                pop(&top);
        }
        else{
            while(top!=NULL && priority(top->val) >= priority(*x)){
                c = pop(&top);
                printf("%c",c);
                arr[i] = c;
                i++;
            }
            pushing(&top,*x);
        }
        x++;
    }
    while(top!=NULL){
        c = pop(&top);
        printf("%c",c);
        arr[i] = c;
        i++;
    }
    printf("\n");
    evaluate(arr);
}
int main(){
    char str[100],*arr;
    int i = 0;
    printf("Enter String: ");
    scanf("%s",str);
    postfix(str);
    return 0;
}