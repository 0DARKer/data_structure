// https://blog.csdn.net/xiajun07061225/article/details/8088784
#include<iostream>
using namespace std;
const int MaxVal = 9999;
const int n=5;
//搜索到根节点和虚拟键的概率
double p[n+1]={
    -1,0.15,0.1,0.05,0.1,0.2
};
double q[n+1]={
    0.05,0.1,0.05,0.05,0.05,0.1
};
int root[n+1][n+1];//记录根节点
double w[n+2][n+2];//子树概率之和
double e[n+2][n+2];//子树期望代价

void optimalBST(double *p,double *q,int n){
    for (int i=1;i<n+1;i++){//初始化只包括虚拟键的子树
        w[i][i-1]=q[i-1];
        e[i][i-1]=q[i-1];
    }
    for(int len =1 ;len <n;len++){
        for(int i=1;i<n-len+1;i++){
            int j= i+len-1;
            e[i][j]=MaxVal;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            for(int k=i;k<j;k++){
                double temp =e[i][k-1]+e[k+1][j]+w[i][j];
                if(temp<e[i][j]){
                    e[i][j]=temp;
                    root[i][j]=k;
                }
            }
        }
    }
}

