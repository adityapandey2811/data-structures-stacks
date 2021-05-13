#include<iostream>
#include"ss.h"
using namespace std;
int main(){
	int i,j,k,n,x,v,c,area = 0,arr[100];
	stack *top = NULL;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	pushI(&top,0);
	for(i=1;i<n;i++){
		if(top!=NULL && arr[i]<arr[top->data]){
			while(top!=NULL && arr[i]<arr[top->data]){
				k = popI(&top);
				if(isEmpty(top)){
					k = arr[k]*(i);
				}
				else{
					k = arr[k]*(i-top->data -1);
				}
				if(k>area)
					area = k;
			}
			pushI(&top,i);
		}
		else{
			pushI(&top,i);
		}
	}
	while(top!=NULL){
		k = popI(&top);
		if(isEmpty(top)){
			k = arr[k]*i;
		}
		else{
			k = arr[k]*(i-top->data-1);
		}
		if(k>area)
			area = k;
	}
	cout<<area<<endl;
}
