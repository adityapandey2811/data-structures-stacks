#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,k,n;
    int arr[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<n;i++){
        if((i+1)!=n)
            k = arr[i+1];
        for(j=i+1;j<n;j++){
            if(arr[i]<arr[j] && arr[j]<=k)
                k = arr[j];
        }
        if(arr[i]<k)
            cout<<k<<" ";
        else
            cout<<arr[i]<<" ";
    }
  return 0;
}
