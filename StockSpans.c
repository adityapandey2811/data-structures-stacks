#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,j,k,n,x,c,v;
    int arr[5],span[5];
    printf("Enter: ");
    for(i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<5;i++){
        span[i] = 1;
        j=i-1;
        while(j!=-1){
            if(arr[i]>arr[j]){
                span[i]++;
            }
            else{
                break;
            }
            j--;
        }
    }
    for(i=0;i<5;i++){
        printf("%d ",span[i]);
    }
    return 0;
}