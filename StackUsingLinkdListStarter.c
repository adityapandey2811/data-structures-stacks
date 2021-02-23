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
void main(){
    Stack *s = NULL;
    int i,k;
    printf("Enter:\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Top\n6. IsEmpty\n7. Is Full\n8. Delete Stack\n9. End\n");
    while(i!=9){
        printf("Enter: ");
        scanf("%d",&i);
        switch (i){
        case 1:
            s = push(s);
            break;
        case 2:
            s = pop(s);
            break;
        case 3:
            peek(s);
            break;
        case 4:
            display(s);
            break;
        case 5:
            if(s!=NULL)
                printf("%d\n",s->data);
            else
                printf("Stack Empty!!!\n");
            break;
        case 6:
            isEmpty(s);
            break;
        case 7:
            isFull(s);
            break;
        case 8:
            s = deleteStack(s);
            break;
        default:
            break;
        }
    }
}