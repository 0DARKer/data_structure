#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node *nodeptr;
typedef struct node{
  char *word;
  int count ;
  nodeptr next;
}node;
#define NHASH 29989
#define MULT 31
nodeptr bin[NHASH];
unsigned int hash(char *p){
  unsigned int h=0;
  for(;*p;p++)
    h=MULT*h+*p;
  return h%NHASH;
}
void incword(char *s){
  int h=hash(s);
  nodeptr p;
  for(p=bin[h];p!=NULL;p=p->next){
    if (strcmp(s,p->word)==0){
      (p->count)++;
      return ;
    }
  }
  p=malloc(sizeof(bin[0]));
  p->count = 1;
  p->word=malloc(strlen(s)+1);
  strcpy(p->word,s);
  p->next=bin[h];
  bin[h]=p;
}

int main(){
  int i;
  char buf[20];
  nodeptr p;
  FILE *fin;
  FILE *fout;
  fin=fopen("dict.input","r");
  fout=fopen("freq.output","a+");
  for(i=0;i<NHASH;i++)
    bin[i]=NULL;
  while(fscanf(fin,"%s",buf)!=EOF)
    incword(buf);
  for(i=0;i<NHASH;i++)
    for(p=bin[i];p!=NULL;p=p->next)
        fprintf(fout,"%s %d\n",p->word,p->count);
  return 0;
}
