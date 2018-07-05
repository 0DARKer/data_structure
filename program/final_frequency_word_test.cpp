//这是program的汇报.
#include <iostream>
#include<fstream>
using namespace std;
const int  MAX=29989;
const int MULT =31;
unsigned int hash_(string t){//my hash function.
  unsigned int hash_return=0 ;
  for(int i=0;i<t.size();i++)
    hash_return = hash_return*MULT + t[i];
  return hash_return%MAX;
}
typedef struct L{//word ,count Linklist
  string word;
  int count ;
  struct L *next;
}*Lptr;
Lptr bin[MAX]={NULL};
void incword(string t){//index by hash ,function hash find a hash number for each word.
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

Lptr insert(Lptr &head,Lptr q){//insert a node to a Linklist by sort;
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
       while(p!=NULL && (p->count > q->count || (p->count == q->count && p->word<q->word)))prev=p,p=p->next;
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
void print_(Lptr head){//print the sorted word to file"output"
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
Lptr  sort_(){//sort the word by count 
    Lptr head,p;
    head=NULL;
    for(int i=0;i<MAX;i++)
        for(p=bin[i];p!=NULL;)
            p=insert(head,p);
    return head;
}
int main(){
   ifstream fin("3.2G.input");
   while(1){
     string t;
     fin >>t;
     if(!fin.eof())
     incword(t);
     else break;
   }
    L *head;
    head=sort_();
    print_(head);
   fin.close();
 }
