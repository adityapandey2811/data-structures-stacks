#include<iostream>
#include"ss.h"
using namespace std;
int main(){
    int i,j,k,n,x,v,c,arr[20],nge[20];
    cin>>n;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    stack *top = NULL;
    for(i=0;i<n;i++){
        if(top!=NULL && arr[top->data] < arr[i]){
            while(top!=NULL && arr[top->data] < arr[i]){
                k = popI(&top);
                nge[k] = arr[i];
            }
            pushI(&top,i);
        }
        pushI(&top,i);
    }
    while(top!=NULL){
        k = popI(&top);
        nge[k] = -1;
    }
    for(i=0;i<n;i++){
        cout<<nge[i]<<" ";
    }
}
