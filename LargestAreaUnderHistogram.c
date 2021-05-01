#include<stdio.h>
int main(){
    int i,j,k,n,x = 0,y = 0,v,c,arr[100],max = 0;
    printf("Enter: ");
    scanf("%d",&n);
    for(i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        v = i;
        if(v!=0){
            while(v>=0){
                if(arr[v]>=arr[i])
                    x = v;
                else
                    break;
                v--;
            }
        }
        v = i;
        if(v!=n-1){
            while(v<n){
                if(arr[v]>=arr[i])
                    y = v;
                else
                    break;
                v++;
            }
        }
        if(((y-x+1) * arr[i]) > max){
            max = (y-x+1) * arr[i];
        }
    }
    printf("%d",max);
}
