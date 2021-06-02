#ifndef Stack_h
#define Stack_h

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
void displayings(stack *top){
    if(top->next!=NULL){
        displayings(top->next);
    }
    printf("%c ",top->val);
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
void displayIs(stack *top){
    if(top == NULL){
        printf("Stack Empty\n");
        return;
    }
    while(top!=NULL){
        printf("%d ",top->data);
        top = top->next;
    }
}
int isFulls(){
    stack *check;
    check = (stack*)malloc(sizeof(stack));
    if(check == NULL)
        return 1;
    return 0;
}
int isEmptys(stack *top){
    if(top == NULL)
        return 1;
    return 0;
}
void pushing(stack **top, char c){
    stack *temp = *top, *link;
    if(!isFulls()){
        link = (stack*)malloc(sizeof(stack));
        link->val = c;
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
void pushI(stack **top, int c){
    stack *temp = *top, *link;
    if(!isFulls()){
        link = (stack*)malloc(sizeof(stack));
        link->data = c;
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
void push(stack **top){
    char i;
    stack *temp = *top, *link;
    if(!isFulls()){
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
    char c;
    if(top == NULL)
        printf("Stack Empty\n");
    else{
        temp = *top;
        c = temp->val;
        (*top) = (*top)->next;
        free(temp);
    }
    return c;
}
int popI(stack **top){
    stack *temp;
    int c;
    if(top == NULL)
        printf("Stack Empty\n");
    else{
        temp = *top;
        c = temp->data;
        (*top) = (*top)->next;
        free(temp);
    }
    return c;
}

#endif
