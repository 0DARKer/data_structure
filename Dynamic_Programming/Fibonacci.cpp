//使用DP的Memoization解决Overlapping Subproblem
//求nth Fibonacci数
#include<iostream>
using namespace std;
int lookup[100];
void init(){
    for(int i=0;i<100;i++)
        lookup[i]=0;
}
int Fib(int n){
    if(lookup[n]!=0)return lookup[n];
    else if(n<=1){
        lookup[n]=n;
    }
    else {
        lookup[n]=Fib(n-1)+Fib(n-2);
    }
    return lookup[n];
}

int main(){
    int n;
    while(1){
    cin >> n;
    cout << Fib(n)<<endl;
    }   
}
