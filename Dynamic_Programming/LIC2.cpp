#include<iostream>
using namespace std;
int lis(int arr[],int n){
    int lis[n];
    for(int i=0;i<n;i++)
        lis[i]=1;
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if (arr[i]>arr[j]&&lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
    int _max;
    for(int i=0;i<n;i++)
        if(_max < lis[i])
            _max=lis[i];
    return _max;
}
int main(){
    int arr[]={10,22,9,33,21,50,41,60};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << lis(arr,n);
    return 0;
}
