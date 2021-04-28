#include<stdio.h>
#include<stdlib.h>
typedef struct arrstack{
    int size, top1, top2, *arr;
}stack;
int isFull(stack *top){
    return (top->top1 == top->top2-1) || (top->top1-1 == top->top2); 
}
int isEmpty(stack *top, int i){
    if(i == 0 && (top->size == top->top2 && top->top1 == -1))
        return 1;
    else if(i == 1 && top->top1 == -1)
        return 1;
    else if(i == 2 && top->size == top->top2)
        return 1;
    return 0;
}
void display(stack *top, int i){
    if(i == 1){
        for(i=0;i<=top->top1;i++)
            printf("%d ",top->arr[i]);
    }
    else if(i == 2){
        for(i=top->size-1;i>=top->top2;i--)
            printf("%d ",top->arr[i]);
    }
    else if(i == 0){
        for(i=0;i<top->size;i++){
            if(i>top->top1 && i<top->top2)
                continue;
            printf("%d ",top->arr[i]);
        }
    }
    else{
        printf("Wrong Input!!!");
    }
    printf("\n");
}
void push(stack **top, int i){
    stack *v1 = *top;
    if(i == 1 && !isFull(v1)){
        v1->top1++;
        scanf("%d",&v1->arr[v1->top1]);
    }
    else if(i == 2 && !isFull(v1)){
        v1->top2--;
        scanf("%d",&v1->arr[v1->top2]);
    }
    else if(isFull(v1)){
        printf("Stack Full!!!\n");
    }
    else{
        printf("Wrong Input\n");
    }
}
void pop(stack **top, int i){
    stack *v1 = *top;
    if(i == 1 && !isEmpty(v1,1)){
        v1->top1--;
    }
    else if(i == 2 && !isEmpty(v1,2)){
        v1->top2++;
    }
    else if(isEmpty(v1,0)){
        printf("Stack Empty!!!\n");
    }
    else{
        printf("Wrong Input\n");
    }
}
int main(){
    int i,j,k,n = 0,x,v,c;
    stack *v1 = NULL;
    v1 = (stack*)malloc(sizeof(stack));
    v1->size = 10;
    v1->top1 = -1;
    v1->top2 = v1->size;
    v1->arr = (int*)malloc(sizeof(int)*v1->size);
    while(n!=-1){
        printf("1 Push1\n2 Push2\n3 Pop1\n4 Pop2\n5 Show1\n6 Show2\n7 ShowAll\n-1 Exit\n");
        scanf("%d",&n);
        if(n == 1)
            push(&v1,1);
        else if(n == 2)
            push(&v1,2);
        else if(n == 3)
            pop(&v1,1);
        else if(n == 4)
            pop(&v1,2);
        else if(n == 5)
            display(v1,1);
        else if(n == 6)
            display(v1,2);
        else if(n == 7)
            display(v1,0);
    }
    

    return 0;
}