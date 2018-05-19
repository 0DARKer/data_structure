#include<stdio.h>
void f(int a[],int left,int right)

{
   int x=a[left],i=left,j=right;
   if (i>=j)
   {return;}
   while (i<j)
   {
     while (i<j&&a[j]>=x)
     j--;
     a[i]=a[j];
     while (i<j&&a[i]<=x)
     i++;
     a[j]=a[i];
   }
   a[i]=x;
   f(a,left,i-1);
   f(a,i+1,right);
}
int main(){
	int m,i;
	int a[1000];
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
	f(a,0,m-1);
	for(i=0;i<m;i++)
		printf("%d",a[i]);
}
