//使用并查集对图判断是否是欧拉回路
//其中数组a用于对节点度数判断,disjoint为并查集,为判断是否是同一个回路
//优化程序需要对将函数的使用降到最低.
#include<iostream>
using namespace std;
int a[1005],disjoint[1005];
int joint_F(int k){//将k到根路径中的节点统一为根节点然后返回根节点.
    if(disjoint[k]!=k)return disjoint[k]=joint_F(disjoint[k]);
    else return k;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)disjoint[i]=i;
    int x,y;
    for(int i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        a[x]++,a[y]++;
        int rx=joint_F(x);
        int ry=joint_F(y);
        if(rx!=ry){
            disjoint[ry]=rx;
        }
    }
    a[n]=1;int j;
    for(j=0;a[j]%2==0;j++);
    if(j==n){
    int k=joint_F(1);
    for(int i=2;i<n;i++){
        if(k!=joint_F(i)){
            cout << 0;
            return 0;
        }   
    }
    cout<< 1;
    return 0;
    }
    else cout <<0;
    return 0;
}






