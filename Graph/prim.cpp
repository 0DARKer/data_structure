//本程序实现prim算法从给定图中生成最小生成树.
//输入:节点个数N ,点集,边集个数M,节点关系和权值
//输出:最小生成树的边集
#include<iostream>
using namespace std;
const int MAX=1000000;
const int V=500;
void _init(int key[],bool MSTset[],int parent[],int v){
    for(int i=0;i<v;i++)
    {
        parent[i]=-1;
        key[i]=MAX;
        MSTset[i]=0;
    }
    key[0]=0;
}
int minikeyindex(int key[],bool MSTset[],int v){
    for(int i=0,j=0;i<v;i++){
        if(MSTset[i]==false)
            if(key[i]<key[j])j=i;
    }
    return j;
}
void main(){
    cin >> v;
    int graph[v];
    int parent[v];
    int key[v];
    bool MSTset[v];
    _init(key,MSTset,parent,v);
    int index_;
    int sum=0;
    while(sum<v){
    MSTset[index_ = minikeyindex(key,MSTset,v)]++;
    for(int i=0;i<v;i++){
        if(graph[index_][i]!=0 && MSTset[i]==false)
            if(graph[index_][i]<key[i])key[i]=graph[index_][i],parent[i]=index_;
    }
    sum++
    }
    for(int i=0;i<n;i++){
        if(parent[i]==-1)
    }
}
