#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ss.h"
#include<ctype.h>
int main(){
    int i = 0, flag = 0;
    char str[100];
    stack *top = NULL;
    printf("Enter Expression: ");
    fflush(stdin);
    scanf("%[^\n]",str);
    while(str[i] != '\0'){
        if(isalnum(str[i])){
            i++;
            continue;
        }
        if(str[i] == '{'){
            pushing(&top,str[i]);
        }
        else if(str[i] == '['){
            pushing(&top,str[i]);
        }
        else if(str[i] == '('){
            pushing(&top,str[i]);
        }
        else if(str[i] == '}'){
            if(top!=NULL && top->val == '{')
                pop(&top);
            else{
                flag = 1;
                printf("Matching Incorrect\n");
                break;
            }
        }
        else if(str[i] == ']'){
            if(top!=NULL && top->val == '[')
                pop(&top);
            else{
                flag = 1;
                printf("Matching Incorrect\n");
                break;
            }
        }
        else if(str[i] == ')'){
            if(top!=NULL && top->val == '(')
                pop(&top);
            else{
                flag = 1;
                printf("Matching Incorrect\n");
                break;
            }
        }
        i++;
    }
    if(flag == 0){
        if(isEmpty(top))
            printf("Correctly Matched\n");
        else
            printf("Matching Incorrect\n");
    }
}