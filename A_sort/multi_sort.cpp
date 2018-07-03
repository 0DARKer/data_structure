//shell排序
//非递归的快速排序
//递归的快速排序
//堆排序
//归并排序
//基数排序
#include<iostream>
using namespace std;
int print_(int arr[],int n){
    for(int i =0;i<n;i++)
        cout << arr[i]<<" ";
    return 0;
}
//shell排序
int shell(int arr[],int n){
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i+=1){
            int temp=arr[i];
            int j;
            for(j=i;j>=gap&&arr[j-gap]>temp;j-=gap)
                arr[j]=arr[j-gap];
            arr[j]=temp;
        }
    }
    return 0;
}
//非递归的快速排序
//递归的快速排序
void swap(int *a,int *b){
    int t=*a;
    *a=*b   ;
    *b=t;
}
int partion(int arr[],int low,int high){
    int pivot =arr[high];
    int i=(low-1);
    for(int j=low ;j<=high-1;j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}
void un_quicksort(int arr[],int N){
    int low[N],high[N],top=-1;
    top++,low[top]=0,high[top]=N-1;
    while(top!=-1){
        int l=low[top],h=high[top];top--;
        int pi=partion(arr,l,h);
        if(l<pi-1)
            top++,low[top]=l,high[top]=pi-1;
        if(pi+1<h)
            top++,low[top]=pi+1 ,high[top]=h;
        
    }

}
void ex_quicksort(int arr[],int low,int high){
    if(low <high ){
        int pi = partion(arr,low,high);
        ex_quicksort(arr,low,pi-1);
        ex_quicksort(arr,pi+1,high);
    }
}

//堆排序
/* void heapsort(int a[],int low,int high){ */
/*     while(low<=high){ */
/*     int m=2*low; */
/*     int max_=a[low]; */
/*     while(m<=high){ */
/*         if(m<high) */
/*             if(a[m]<a[m+1]) */
/*                 m++; */
/*         if(max_<a[m]){ */
/*             max_=a[m]; */
/*             m=m*2; */
/*         } */
/*         else */ 
/*             break; */
/*     } */ 
/*     a[m/2]=a[low]; */
/*     a[low]=max_; */
/*     low++; */
/*     } */   
/* } */

void heapify(int arr[],int n,int i){
    int largest =i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n&&arr[l]>arr[largest])
        largest=l;
    if(r<n&&arr[r]>arr[largest])
        largest=r;
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapsort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
int main(){
    int N;
    cin >> N;
    int a[N];
    for(int i=0;i<N;i++)
        cin >>a[i];
    /* shell(a,N); */
    /* un_quicksort(a,N); */
    /* heapsort(a,N); */
    print_(a,N);
}
