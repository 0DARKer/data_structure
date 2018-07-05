#include<iostream>
using namespace std;
struct L{
  char *word;
  int count ;
  struct L *next;
};
L *bin[MAX];
const int  MAX = 29989
const int MULT =31//hash的乘数
unsigned int hash(char *p){
  unsigned int h=0;
  for(;*p;p++)
    h=MULT*h+*p;
  return h%MAX;
}
void incword(char *s){
  int h=hash(s);
  L *p;
  for(p=bin[h];p!=NULL;p=p->next)
    if(p->word==)

}
int main(){
  for(int i=0;i<MAX;i++)
    bin[i]=NULL;
  string t;
  ifstream fin("input");
  while(!fin.eof()){
    fin >> t;
    incword(t);
  }
  L *p;
  for(int i=0;i<MAX;i++)
    for(p=bin[i];p!=NULL;p=p->next)
      fout << p->word << " "<< p->count <<endl;
}
