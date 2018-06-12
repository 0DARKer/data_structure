#include<iostream>
#define SUCC 1
#define NOTFOUND 0
using namespace std;
typedef struct B{
    int D;
    struct B *L;
    struct B *R;
}Bnode , *Bptr;

Bptr search(int x,Bptr p){//检索树的搜索算法
    if(p==NULL)return NULL;
    if(x==p->D)return p;
    if(x<p->D)return search(x,p->L);
    else return search(x,p->R);
}
void insert(int x,Bptr &p){//检索树的插入算法
    if(p==NULL){//使用递归时对调用函数中变量的修改可以使用返回值或者是引用
        p=new Bnode;
        p->D=x;
        p->L=p->R=NULL;
        return;
    }
    if(x<p->D)return insert(x,p->L);
    else return insert(x,p->R); 
}



Bptr create(){//依赖函数insert(int x,Bptr &p).在终端中读取一个n长的树串,返回它的检索树根节点指针
    Bptr root; 
    int x;
    root =NULL;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >>x;
        insert(x,root);
    }
    return root;
}
int delete(int x,Bptr root){
   
}

//int main(){
    //int a;
    //Bptr root = create();
    //cin >> a;
//}
int deleteT(int x, Bptr root){
    p=NULL;
    f=root;
    q=root->Rson;
    while(q!=NULL){
        if(x==q->D){
            p=q;q=NULL; 
        }
        else if(x<q->D){
            f=q;q=q->L;
        }
        else {
            f=q;
            q=q->R
        }
    }
    if(p==NULL)return NOTFOUND;
    if(p->R==NULL)//1.无右儿子
      if(p==f->L){
          f->L=p->L;free(p);
      }
      else{
          f->R=p->L;free(p);
      }
    else if(p->L==NULL)//2.无左儿子
        if(p==f->L){
            f->L=p->R;free(p);
        }
        else{
            f->L=p->L;free(p);
        }
    else{//3.两个儿子都有
        s=p->L;
        if(s->R==NULL){
            p->D=s->D;
            p->L=s->L;
            free(s);
        }
        else {
            r=s->R;
            while(r->R!=NULL){
                s=r;r=r->R;
            }
            p->D=r->D;
            s->R=r->L;
            free(r);
        }
    }        
}
