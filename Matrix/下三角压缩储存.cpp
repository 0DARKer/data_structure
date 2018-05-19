#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int b[n*(n+1)/2];
    for(int i=0;i<n*(n+1)/2;i++){
        cin >> b[i];
    }
    int m;
    cin >> m;
    m-=1;
    for(int i=0;i<n;i++){
        if(i<=m)cout << b[m*(m+1)/2 + i]<< " ";
        else cout << 0<< " ";
    }
}
