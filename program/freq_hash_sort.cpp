#include <iostream>
#include<fstream>
using namespace std;
const int  MAX=29989;
const int MULT =31;
unsigned int hash_(string t){
  unsigned int hash_return=0 ;
  for(int i=0;t[i]!=EOF;i++)
    hash_return = hash_return*MULT + t[i];
  return hash_return%MAX;
}
struct L{
  string word;
  int count ;
  struct L *next;
};
L * bin[MAX]={NULL};
void incword(string t){
  unsigned int h = hash_(t);
  L *p;
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
void exchange(L *p,L *q){
  L *r;
  *r=*p,*p=*q,*q=*r;
}
int main(){
  ifstream fin("dict.input");
  ofstream fout("freq.output");
  while(!fin.eof()){
    string t;
    fin >>t;
    // if(!fin.eof())
    incword(t);
    // else break;
  }
  L *p,*q;
  for(int i=0;i<MAX;i++){
    for(p=bin[i]->next,q=bin[i];p!=NULL;p=p->next)
      if(q->count >)
  }
  fin.close();
  fout.close();
}
