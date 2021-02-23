#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}Stack;
int isEmpty(Stack *top){
    if(top == NULL)
        return 1;
    return 0;
}
int isFull(Stack *top){
    Stack *s = NULL;
    s = (Stack*)malloc(sizeof(Stack));
    if(s == NULL)
        return 1;
    return 0;
}
Stack* deleteStack(Stack *top){
    Stack *s = NULL;
    if(!isEmpty(top)){
        while(top!=NULL){
            s = top;
            top = top->next;
            free(s);
        }
        return top;
    }
    else{
        printf("Stack not available!!!\n");
        return NULL;
    }
}
Stack* push(Stack *top){
    Stack *s = NULL;
    if(!isFull(top)){
        s = (Stack*)malloc(sizeof(Stack));
        printf("Enter Data: ");
        scanf("%d",&s->data);
        s->next = top;
        top = s;
        printf("Pushed: %d\n",s->data);
    }
    else
        printf("Memory Not Available!!!\n");
    return top;
}
Stack* pop(Stack *top){
    Stack *s = top;
    if(!isEmpty(top)){
        top = top->next;
        printf("Popped: %d\n",s->data);
        free(s);
    }
    else
        printf("Stack Empty!!!\n");
    return top;
}
int peek(Stack *top){
    Stack *s = top;
    int k;
    if(!isEmpty(top)){
        printf("Enter k: ");
        scanf("%d",&k);
        if(k<=0){
            printf("Backchodi matt kro beta!!!\n");
            return -1;
        }
        while(--k && s->next != NULL){
            s = s->next;
        }
        while(s->next != NULL){
            s = s->next;
            top = top->next;
        }
        if(k != 0){
            printf("Invalid index!!!\n");
            return -1;
        }
        else{
            printf("Peeked: %d\n",top->data);
            return top->data;
        }
    }
    else
        printf("Stack not available!!!\n");
    return -1;
}
void display(Stack *top){
    if(top == NULL){
        printf("Stack Empty!!!\n");
        return;
    }
    if(top->next == NULL){
        printf("%d ",top->data);
        return;
    }
    else{
        display(top->next);
        printf("%d ",top->data);
    }
}