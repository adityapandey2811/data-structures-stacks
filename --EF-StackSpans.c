#include<stdio.h>
#include<stdlib.h>
#include"ss.h"
int main(){
    stack *top = NULL;
    int i,j,k,n,x,c,v;
    int arr[7],span[7];
    pushI(&top,0);
    span[0] = 1;
    printf("Enter: ");
    for(i=0;i<7;i++){
        scanf("%d",&arr[i]);
    }
    for(i=1;i<7;i++){
        while(!isEmpty(top) && arr[i]>=arr[top->data]){
            k = popI(&top);
            span[i] = i-k;
        }
        if(!isEmpty(top) && arr[i]<arr[top->data]){
            span[i] = i-top->data;
        }
        else{
            span[i] = i+1;
        }
        pushI(&top,i);
    }
    for(i=0;i<7;i++)
        printf("%d ",span[i]);
    return 0;
}