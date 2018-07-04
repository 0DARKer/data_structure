//shell排序
//非递归的快速排序
//递归的快速排序
//堆排序
//归并排序
//基数排序
#include<iostream>
using namespace std;
int print_(int arr[],int n){
    int j=0;
    for(int i =1;i<7;i++){
        cout << arr[i*n/6-1];
        if(i!=6)cout << "...";
      }
      cout << endl;
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
void re_quicksort(int arr[],int low,int high){
    if(low <high ){
        int pi = partion(arr,low,high);
        re_quicksort(arr,low,pi-1);
        re_quicksort(arr,pi+1,high);
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

void heapify(int arr[],int n,int subroot){
    int largest =subroot;
    int l=2*subroot+1;
    int r=2*subroot+2;
    if(l<n&&arr[l]>arr[largest])
        largest=l;
    if(r<n&&arr[r]>arr[largest])
        largest=r;
    if(largest!=subroot){
        swap(arr[subroot],arr[largest]);
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

//归并排序
void merge(int arr[],int low,int middle,int high){
  int r=middle-low+1;
  int l=high -middle;
  int right[r];
  int left[l];
  int k=low;
  for(int i=0;i<r;i++)
    right[i]=arr[k++];
  for(int j=0;j<l;j++)
    left[j]=arr[k++];
  int i=0;
  int j=0;
  k=low;
  while(i<r&&j<l){
    if(right[i]<=left[j])
      arr[k]=right[i++];
    else
      arr[k]=left[j++];
    k++;
  }
  while(i<r)
    arr[k++]=right[i++];
  while(j<l)
    arr[k++]=left[j++];
}
void mergesort(int arr[],int low,int high){
  if(low<high){
    int m=low+(high-low)/2;//*****标星,避免大于high和low
    mergesort(arr,low,m);
    mergesort(arr,m+1,high);
    merge(arr,low,m,high);
  }
}
//计数排序
const int BIGGEST=200;
void countingsort(int arr[],int n,int exp=1 ){
  int output[n];
  int count[10];
  for(int i=0;i<10;i++){
    count[i]=0;
  }
  for(int i=0;i<n;i++){
    count[(arr[i]/exp)%10]++;
  }
  for(int i=1;i<10;i++){
    count[i]+=count[i-1];
  }
  for(int i=n-1;i>=0;i--){
    output[count[(arr[i]/exp)%10]-1]=arr[i];
    --count[(arr[i]/exp)%10];
  }
  for(int i=0;i<n;i++){
    arr[i]=output[i];
  }
}
int getMax(int arr[],int n){
    int max=arr[0];
    for(int i=1;i<n;i++){
      if(arr[i]>max)
        max=arr[i];
    }
    return max;
}
void radixsort(int arr[],int n){
  int m=getMax(arr,n);
  for(int i=1;m/i>0;i*=10){
    countingsort(arr,n,i);
  }
}
// int main(){
//   int N ;
//   cin >> N;
//   int a[N];
//   for(int i=0;i<N;i++)
//   a[i]=rand()%BIGGEST;
//   cout <<getMax(a,N);
//   countingsort(a,N,1);
//   print_(a,N);
// }
void init(int a[],int b[],int n){
  for(int i=0;i<n;i++)
    b[i]=a[i];
}
int main(){
    cout <<"此程序输入一个数,然后生成随机数组成的数组,每个随机数不大于BIGGEST=200.每行按行一种排序方式输出大致排序和所花时间.\n输入>";
    int N;
    cin >> N;
    int     a[N],   b[N],   c[N],   d[N],   e[N],   f[N];
    // time_t ta1,ta2,tb1,tb2,tc1,tc2,td1,td2,te1,te2,tf1,tf2;
    for(int i=0;i<N;i++){
        a[i]=b[i]=rand()%BIGGEST;
      }

    // time(&ta1);
    shell(b,N);
    // time(&ta2);
    cout << "shellsort:";
    print_(b,N);
    // cout << "time:"<<(ta2-ta1)<<"s"<<endl;
init(a,b,N);
    // time(&tb1);
    un_quicksort(b,N);
    // time(&tb2);
    cout << "un_quicksort";
    print_(b,N);
    // cout << "time:"<<tb2-tb1<<"s"<<endl;
init(a,b,N);
    // time(&tc1);
    re_quicksort(b,0,N-1);
    // time(&tc2);
    cout << "re_quicksort:";
    print_(b,N);
    // cout << "time:"<<tc2-tc1<<"s"<<endl;
init(a,b,N);
    // time(&td1);
    heapsort(b,N);
    // time(&td2);
    cout << "heapsort:";
    print_(b,N);
    // cout << "time:"<<td2-td1<<"s"<<endl;
init(a,b,N);
    // time(&te1);
    mergesort(b,0,N-1);
    // time(&te2);
    cout << "mergesort:";
    print_(b,N);
    // cout << "time:"<<te2-te1<<"s"<<endl;
init(a,b,N);
    // time(&tf1);
    radixsort(b,N);
    // time(&tf2);
    cout << "radixsort:";
    print_(b,N);
    // cout << "time:"<<tf2-tf1<<"s"<<endl;
}
