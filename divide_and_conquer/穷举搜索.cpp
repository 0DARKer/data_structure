//运用穷举法对一个集合内的元素进行穷举,分别判断元素的性质,从而找到答案..
//问题:长度为n的数列A和整数m,判断A中任意几个元素的和能否得到m,A中每一个
//元素只能用一次.
//输入:
//n
//n个整数(代表A)
//q
//q个整数mi(代表每个不同的mi值)
#include<stdio.h>
int n,A[50];
int fun(int i,int m){
  if(m==0)return 1;
  if(i>=n)return 0;
  int ret=fun(i+1,m)||fun(i+1,m-A[i]);//兵分两路.A中第i个元素有两种选择,是否参与运算.
                                      //只要兼顾到每一种选择,就能判断出能否满足条件
  return ret;
}
int main(){
  int i;
  int m;
  int q;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&m);
    if(fun(0,m)==1)printf("YES\n");
    else printf("NO\n");
  }
}
