//本程序实现prim算法从给定图中生成最小生成树.
//输入:节点个数N ,点集,边集个数M,节点关系和权值
//输出:最小生成树的边集

#include<iostream>
using namespace std;
typedef struct L{
  int quan;
  int connect;
  struct L *next;
}Lnode,*Lptr;
typedef struct G {
  int data;
  bool check;
  struct L *head;
}Gnode;
int main(){
  int N;
  cin >>N;
  Gnode g[N+1];
  for(int i=0;i<N;i++){
    g[i].head=NULL;
    cin >> g[i].data;
    g[i].check=0;
  }
  int M;
  cin  >> M;
  for(int i=0;i<M;i++){
    int a,b,c;
    cin >> a>>b>>c;
    for(int i=0;i<N;i++){
      if(g[i].data==b){for(int j=i;i<N;i++){
        if(g[i].data==a){Lptr p=new Lnode;p->data=j;p->next=g[i].head;g[i].head=p;}
      }}
      if(g[i].data==a){for(int j=i;j<N;j++){
        if(g[i].data==b){Lptr p=new Lnode ; p->data=j;p->next=g[i].head;g[i].head=p;}
      }}
    }
  }

}
