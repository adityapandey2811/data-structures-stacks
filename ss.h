#ifndef ss_h
#define ss_h

#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    char val;
    struct node *next;
}stack;
int top(stack *top){
    if(top == NULL)
        printf("Stack Empty\n");
    else
        while(top->next != NULL)
            top = top->next;
    return top->val;
}
void deleteStack(stack **top){
    stack *temp ,*link = *top;
    if(*top == NULL)
        printf("Stack Empty\n");
    while(link!=NULL){
        temp = link;
        link = link->next;
        free(temp);
    }
    *top = NULL;
}
void display(stack *top){
    if(top == NULL){
        printf("Stack Empty\n");
        return;
    }
    while(top!=NULL){
        printf("%c ",top->val);
        top = top->next;
    }
}
int isFull(){
    stack *check;
    check = (stack*)malloc(sizeof(stack));
    if(check == NULL)
        return 1;
    return 0;
}
int isEmpty(stack *top){
    if(top == NULL)
        return 1;
    return 0;
}
void push(stack **top){
    char i;
    stack *temp = *top, *link;
    if(!isFull()){
        link = (stack*)malloc(sizeof(stack));
        printf("Enter Data: ");
        fflush(stdin);
        scanf("%c",&link->val);
        if(temp == NULL){
            *top = link;
            link->next = NULL;
        }
        else{
            link->next = temp;
            *top = link;
        }
    }
}
char pop(stack **top){
    stack *temp;
    char i;
    if(top == NULL)
        printf("Stack Empty\n");
    else{
        temp = *top;
        (*top) = (*top)->next;
        free(temp);
    }
    return i;
}

#endif