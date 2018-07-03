#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORD 40
#define MAXSIZE 288888
struct linklist{
	char word[MAXWORD];
	int count;
	struct linklist *lchild,*rchild;
};
struct line{
	char word[MAXWORD];
	int count;
	struct line *next;
};
struct link{
	struct line *next;
};
struct link LINK[MAXSIZE][26];
char * getWord(unsigned char c,FILE *fp);
struct linklist * search(struct linklist *p,char array[]);
struct linklist * insert(struct linklist *p,char array[]);
void inorder(struct linklist *p);
void insertline(struct linklist *p);
int main(){
	int i,j,count;
	unsigned char c;
	char words[MAXWORD];
	FILE *fp,*fw;
	struct linklist *p=NULL,*r;
	struct line *q;
	fp=fopen("dict.file","r");
	fw=fopen("wordfreq.txt","w");
	while (!feof(fp))
	{
		c=fgetc(fp);
		if (isalpha(c))
		{
			strcpy(words,getWord(c,fp));
			if ((r=search(p,words))!=NULL)
			{
				r->count++;
			}
			else{
				p=insert(p,words);
			}
		}
	}
	for (i=0;i<MAXSIZE;i++)
	{
		for (j=0;j<26;j++)
		{
			LINK[i][j].next=NULL;
		}	
	}
	inorder(p);
	count=0;
	for (i=MAXSIZE-1;i>=0;i--)
	{
		for (j=0;j<26;j++)
		{
			if (LINK[i][j].next!=NULL)
			{
				for (q=LINK[i][j].next;q!=NULL;q=q->next)
				{
					if (count<100)
					{
						printf("%s %d\n",q->word,q->count);
						count++;
					}
					fprintf(fw,"%s %d\n",q->word,q->count);				
				}
			}
		}
	}
	return 0;
}
char * getWord(unsigned char c,FILE *fp){
	char *ptr=(char *)malloc(MAXWORD),*f;
	//f是ptr的首地址
	f=ptr;
	while (isalpha(c))
	{
		*ptr++=tolower(c);
		c=fgetc(fp);
	}
	*ptr='\0';
	return f;
}
struct linklist * search(struct linklist *p,char array[]){
	struct linklist *r=NULL;
	r=p;
	while(r!=NULL)
	{
		if (strcmp(r->word,array)==0)
		{
			return r;
		}
		else if (strcmp(r->word,array)>0)
		{
			r=r->lchild;
		}
		else{
			r=r->rchild;
		}
	}
	return NULL;
}
struct linklist * insert(struct linklist *p,char array[]){
	if (p==NULL)
	{
		p=(struct linklist * )malloc(sizeof(struct linklist));
		strcpy(p->word,array);
		p->count=1;
		p->lchild=p->rchild=NULL;
	}
	else if (strcmp(p->word,array)>0)
	{
		p->lchild=insert(p->lchild,array);
	}
	else{
		p->rchild=insert(p->rchild,array);
	}
	return p;
}
void insertline(struct linklist *p){
	int i;
	struct line *q,*r,*pre=NULL;
	q=(struct line *)malloc(sizeof(struct line));
	strcpy(q->word,p->word);
	q->count=p->count;
	q->next=NULL;
	i=(q->word)[0]-'a';
	if (LINK[p->count][i].next==NULL)
	{
		LINK[p->count][i].next=q;
	}
	else{
		for (r=LINK[p->count][i].next;r!=NULL;pre=r,r=r->next)
		{
			if (strcmp(r->word,p->word)>0)
			{
				break;
			}
		}
		if (r==LINK[p->count][i].next)
		{
			LINK[p->count][i].next=q;
		}
		else{
			pre->next=q;
		}
		q->next=r;
	}
}
void inorder(struct linklist *p){
	if (p!=NULL)
	{
		inorder(p->lchild);
		insertline(p);
		inorder(p->rchild);
	}
}
