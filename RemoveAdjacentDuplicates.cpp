#include<iostream>
#include"ss.h"
int main(){
    stack *top = NULL;
    char arr[40] = "mississississippkkaaauaj",*s;
	s = arr;
    int i = 0,j,k,n,x,v,c;
    pushing(&top,*s);
    s++;
    while(*s!='\0'){
        if(top!=NULL && top->val == *s){
            while(top->val == *s){
                s++;
            }
            pop(&top);
            continue;
        }
        else{
            pushing(&top,*s);
        }
        s++;
    }
	displaying(top);
	return 0;
}
