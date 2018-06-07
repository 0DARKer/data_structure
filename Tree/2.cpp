#include<iostream>
using namespace std;
typedef struct Tree{
    int data;
    struct Tree *L;
    struct Tree *R;
}*tre;

tre create(int a[],int i,int j, int b[],int m,int n){
    tre p;
    p=(tre)malloc(sizeof(struct Tree));
    p->data=a[j];
   int x; 
    for ( x = m; x<=n && a[j]!=b[x] ; x++) {
        ; 
    }
    if (a[j]!=b[x]) { 
        return NULL; 
    } 
    p->L=create(a,i,i+x-m-1, b,m,x-1);
    p->R=create(a,i+x-m,j-1, b,x+1,n);
    return p;
}

void preorder(tre p){
    if (p==NULL) { 
        return; 
    } 
    cout << p->data;
    preorder(p->L);
    preorder(p->R);

}

int main(){
    int x;
    cin >> x;
    int a[x],b[x];
    for (int i = 0; i < x ; i++) {
        cin >> a[i]; 
    } 
    for (int i = 0; i < x ; i++) {
        cin >> b[i]; 
    } 
    tre p[100];
    int j=1;
    p[0] = create(a,0,x-1 ,b,0,x-1);
    preorder(p[0]);
    for(int i=0;p[i]!=NULL&&j<100;i++){
        cout << p[i]->data;
        p[j++]=p[i]->L;
        p[j++]=p[i]->R;
    }
}
