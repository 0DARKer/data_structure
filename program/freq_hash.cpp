#include <iostream>
#include<fstream>
using namespace std;
const int  MAX=29989;
const int MULT =31;
unsigned int hash_(string t){
  unsigned int hash_return=0 ;
  for(int i=0;i<t.size();i++)
    hash_return = hash_return*MULT + t[i];
  return hash_return%MAX;
}
typedef struct L{
  string word;
  int count ;
  struct L *next;
}*Lptr;
Lptr bin[MAX]={NULL};
void incword(string t){
  unsigned int h = hash_(t);
  Lptr p;
  for(p=bin[h];p!=NULL;p=p->next){
    if(p->word==t){
      (p->count)++;
      return ;
    }
  }
  p=new struct L;
  p->word=t;
  p->count =1;
  p->next=bin[h];
  bin[h]=p;
  return ;
}
/* int main(){ */
/*   string a; */
/*   int n=0; */
/*   ifstream fin ("dict.input"); */
/*   while(n<100){ */
/*     fin >> a; */
/*     cout <<a; */
/*     int b=hash_(a); */
/*     cout << a; */
/*     cout <<b << endl; */
/*     n++; */
/* } */
/* } */
/* // */
Lptr insert(Lptr &head,Lptr q){
   Lptr p,prev,retu;
   if(head==NULL){
       head=q;
       retu=q->next;
       q->next=NULL;
       return retu;
   }
   else {
       p=head;
       prev=NULL;
       while(p!=NULL && p->count > q->count)prev=p,p=p->next;
       if(prev==NULL){
           retu=q->next;
           q->next=head->next;
           head=q;
           return retu;

       }
       else {
           retu = q->next;
           q->next= prev->next;
           prev->next=q;
           return retu;
       }
   }
}
//
// L * sort(L *q){
//   if(q==NULL)return NULL;
//   L *head;
//   head=NULL;
//   for(;q!=NULL;q=q->next){
//     L *p,*prev;
//     prev=NULL;
//     p=head;
//     while(p!=NULL&&p->count > q->count)prev=p,p=p->next;
//     if(prev!=NULL)p=insert(prev,q);
//     else {
//         L * buf;
//         head=q;
//         buf=q->next;
//         q->next=NULL;
//         q=buf;
//
//     }
//   }
//   return head;
// }
// L *sort_arr(L * bin[]){
//   for(int i=0;i<MAX;i++){
//     bin[i]=sort(bin[i]);
//   }
//   L * head;
//   head=NULL;
//     int n=MAX;
//     while(n>0){
//         L *prev,*p;
//         prev=NULL;
//         p=head;
//         n=MAX;
//
//   for(int i=0;i<MAX;i++){
//     while(bin[i]==NULL){
//       n--;
//       continue;
//     }
//     L * q;
//     prev=NULL;
//     q=bin[i];
//     while(p->count >q->count )prev=p,p=p->next;
//     if(prev!=NULL)bin[i]=insert(prev,q);
//     else bin[i]=insert(head,q);
//     }
//   }
//   return head;
// }
 void print_(Lptr head){
   ofstream fout("output");
   Lptr p;
   p=head;
   if(head==NULL){
       cout << NULL;
       return;
   }
   while(p){
     fout << p->word<< " "<< p->count <<endl;
     p=p->next;
 }
   fout.close();
}
// int main(){
//     L * p = new L ;
//     p->count =1;
//     L * q = new L;
//     q->count  =2;
//     L * r=insert (p,q);
//     print_(p);
//     sort(p);
//     print_(p);
//     cout << r;
//
//
//
// }
Lptr  sort_(){
    Lptr head,p;
    head=NULL;
    for(int i=0;i<MAX;i++)
        for(p=bin[i];p!=NULL;)
            p=insert(head,p);
    return head;
}
 int main(){
   ifstream fin("3.2G.input");
   while(!fin.eof()){
     string t;
     fin >>t;
     // if(!fin.eof())
     incword(t);
     // else break;
   }
    L *head;
    head=sort_();
    /* head = sort_arr(bin); */
    /* print_(head); */
    print_(head);
   fin.close();
 }
