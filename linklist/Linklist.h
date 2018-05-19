#include<stdio.h>
#include<stdlib.h>
typedef struct Llist{
	int data;
	struct Llist *next;
};

void insert(struct Llist *nodeprev,int data){//在在给定节点后面插入给定数据块.
	struct Llist *nodedata;
	nodedata = (struct Llist *)malloc(sizeof(struct Llist));
	nodedata->data = data;
	nodedata->next = nodeprev->next;
	nodeprev->next = nodedata;
}
struct Llist *create_Llist(){
	struct Llist *nodehead;
	nodehead = (struct Llist *)malloc(sizeof(struct Llist));
	nodehead->data = 0;
	nodehead->next = NULL;
	return nodehead;
}
void delete(struct Llist *nodeprev , struct Llist *nodedata){
	nodeprev->next = nodedata->next ;
	free(nodedata);
}
struct Llist *search(struct Llist *nodehead , int data){
	struct Llist *nodeprev;
	nodeprev=nodehead;
	while(nodeprev->next !=NULL){
		if(nodeprev->next->data > data ){
			return nodeprev;
		}
		nodeprev=nodeprev->next;
	}
	return nodeprev;
}
void print_Llist(struct Llist *nodehead){
	struct Llist *nodedata;
	nodedata = nodehead;
	do{
		nodedata=nodedata->next;
		printf("%d ",nodedata->data);
	}while(nodedata->next !=NULL);
}
void cutjishu(struct Llist *nodehead){//方案劣1
	struct Llist *nodenew,*nodenew_end;
	struct Llist *nodedata,*nodeprev;
	nodenew_end = nodenew=(struct Llist *)malloc(sizeof(struct Llist));
	nodenew->next=NULL;

	nodeprev = nodedata = nodehead;
	while(nodeprev->next->next !=NULL){
		nodedata=nodeprev->next;
		if(nodedata->data%2){
			insert(nodenew_end,nodedata->data);
			delete(nodeprev,nodedata);
			free(nodedata);
			}
		else nodeprev=nodeprev->next;
	}
	nodeprev->next->next = nodenew->next;
}
