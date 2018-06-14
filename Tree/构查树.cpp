//这个程序输入先序和中序,从而构造一棵树,并输出树
#include<iostream>
using namespace std;
typedef struct T{
  int data;
  struct T *Lnode;
  struct T *Rnode;
}Tnode,*Tptr;
Tptr createT(int a[],int x,int y,int b[],int n,int m){
  Tptr p = new Tnode;
  p->data=a[x];
  int i;
  for(i=n;i<m;i++){if(b[i]==a[x])break;}
  if(b[i]!=a[x])return NULL;
  p->Lnode = createT(a,x+1,x-n+i,b,n,i-1);
  p->Rnode = createT(a,x-n+i+1,y,b,i+1,m);
  return p;
}
void afterorder(Tptr p){
  if(p==NULL)return ;
  afterorder(p->Lnode);
  afterorder(p->Rnode);
  cout << p->data;
  return ;
}
int main(){
  int N;
  cin >> N;
  int a[N],b[N];
  for(int i=0;i<N;i++){cin >> a[i];}
  for(int i=0;i<N;i++){cin >> b[i];}
  Tptr root=createT(a,0,N-1,b,0,N-1);
  afterorder(root);
  return 0;
}
