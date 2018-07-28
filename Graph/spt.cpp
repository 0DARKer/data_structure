/**********************************************************
 * Author        : 0DARKer
 * Email         : 18851733010@163.com
 * github        : https://github.com/0DARKer
 * Last modified : 2018-07-17 21:02
 * Filename      : spt.cpp
 * Description   : 输入执行次数T和各个不同的N值,表示从1到N为顶点的图,两顶点满足j=i+1,j=3i有边(权为1),求1到N的最小路径.
 * *******************************************************/
#include <iostream>
using namespace std;
int main() {
int T;
cin>>T;
while(T)
{
int n;
int count=0;
cin>>n;
while(n>1)
{
if(n%3==0)
{
n=n/3;
count++;
}
else
{
n=n-1;
count++;
}
}
cout<<count<<"\n"; 
T--;
} return 0; 
}
