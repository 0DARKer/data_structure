//这是一个哈夫曼构造程序,第一行输入N,第二行输入N个数字.
//输出N行,每行开头是输入的数字,从上到下按大小排列,每行的第二个数字表示哈夫曼代码.

#include<iostream>
#define MAX 1000000
using namespace std;
const int I=10;
typedef struct  S{
    bool a[I];
    int i=-1;
}snode;
snode s;
int push(snode &s,bool i){
    if(s.i<I){
        s.a[++s.i]=i;
        return 0;
    }
    else return -1;
}
int pop(snode &s){
    if(s.i>-1){s.i--;return 0;}
    else return -1;
}
int read(snode s){
    for(int i=0;i<=s.i;i++)
        cout << s.a[i];
    return 0;
}

typedef struct hf{
    int data;
    struct hf *Lnode;
    struct hf *Rnode;
    struct hf *next;
}*hfptr,hfnode;

hfptr hf_list(int a){
    hfptr head ;
    head = new hfnode;
    head->data=MAX;
    head->next=head;
    for(int i=0;i<a;i++){
        hfptr p =new hfnode;
        cin >> p->data;
        hfptr q=head->next;
        hfptr prev=head;
        while(q->data<p->data){
            q=q->next;prev=prev->next;
        }
        p->next = prev->next;
        prev->next=p;
    }
    return head;
}
int hf_retur(hfptr p,int i){
    if(i==-1)push(s,0);
    else if(i==1)push(s,1);

    if(p->Lnode !=NULL || p->Rnode !=NULL){
    if(p->Lnode!=NULL){
        hf_retur(p->Lnode,-1);
    }
    if(p->Rnode !=NULL){
        hf_retur(p->Rnode,1);
    }
    }
    else {
        cout << p->data << " ";
        read(s);
        cout <<endl;
        pop(s);
        return 0;
    }
    pop(s);
    return 1;
}
//int main(){
    //push(s,1);
    //push(s,1);
    //push(s,1);
    ////pop(s);
    ////pop(s);
    //read(s);
//}

int main(){
    int a;
    cin >>a ;
    hfptr p=hf_list(a);
    while(1){
        hfptr root=new hfnode;
        hfptr p1=p->next,p2=p1->next;
        if(p2->data==MAX)break;
        root->data = p1->data+p2->data;
        root->Lnode = p1;
        root->Rnode = p2;
        p=p2;
        p1=p2;p2=p2->next;
        while(p2->data<root->data){p1=p2;p2=p2->next;}
        root->next = p1->next;
        p1->next = root;
    }
    hfptr root = p->next;
    hf_retur(root,0); 
    
}

