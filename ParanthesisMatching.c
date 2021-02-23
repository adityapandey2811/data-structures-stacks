#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"CStack.h"
void paranthesisMatch(char arr[],int n){
    Stack *top = NULL;
    int i,k,x,v;
    while(n--){
        switch (arr[n])
        {
        case ')':
            top = pushC(top,')');
            break;
        case ']':
            top = pushC(top,']');
            break;
        case '}':
            top = pushC(top,'}');
            break;
        case '(':
            if(top!=NULL && top->data == ')')
                top = pop(top);
            else{
                printf("Unbalanced\n");
                return;
            }
            break;
        case '[':
            if(top!=NULL && top->data == ']')
                top = pop(top);
            else{
                printf("Unbalanced\n");
                return;
            }
            break;
        case '{':
            if(top!=NULL && top->data == '}')
                top = pop(top);
            else{
                printf("Unbalanced\n");
                return;
            }
            break;
        
        default:
            break;
        }
    }
    if(isEmpty(top))
        printf("Balanced\n");
    else
        printf("Unbalanced\n");
}
void main(){
    int i;
    char arr[100];
    printf("Enter: ");
    fflush(stdin);
    scanf("%[^\n]",arr);
    while(arr[i]!='\0')
        i++;
    if(i>0)
        paranthesisMatch(arr,i);
    else
        printf("Function not entered\n");
}