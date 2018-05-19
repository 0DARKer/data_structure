#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct Llist{
    char sn[8];
    int sno;
    int math;
    int engl;
    int comp;
    char clas;
    struct Llist *next;
}*ptr;
ptr head ;

ptr valuen(){//无bug
    int i;
    ptr p;
    float avg ;
	p = (ptr)malloc(sizeof(struct Llist));
	cin >> p->sn >> p->sno >> p->math >> p->engl >> p->comp ;
	avg = (p->math+p->engl+p->comp)/3;
	if(avg>90)p->clas ='A';
	else if(avg>80)p->clas='B';
	else if(avg>60)p->clas='C';
	else p->clas = 'D';
    return p;
}

int input(){//无bug
	int m;
	int i;
    ptr p,q;
	cout << "输入学生数量>" << endl;
    cin >> m;
	cout << "输入学生信息 >"<< endl;
	for(i=0;i<m;i++){
        p=valuen(); 
		if(head==NULL){
			head = p;
			head->next = NULL;
		}
		else{
            q=head ;
			while(q->next !=NULL)q=q->next;
            q->next = p;
            p->next=NULL;
		}
	}
    return 1;
}

void output(ptr p){//无bug 
    cout << "数据:"<<endl;
    while(p!=NULL){
        cout << p->sn <<" "<< p->sno << " " << p->math << " " << p->engl << " "<< p->comp << " " <<p->clas << endl; 
        p=p->next;
    }
}

void search(){//无bug
	int i,n,m;
	ptr p=head;
	cout << "search sno:" << endl;
	cin >> n;
	while(n!=p->sno ){p=p->next;if(p==NULL){printf("nothing...");return;}}
    cout << p->sn <<" "<< p->sno << " " << p->math << " " << p->engl << " "<< p->comp << " " <<p->clas << endl; 
}
int insert(){//无bug
    ptr p,prev;
    int x;
    cout << "请输入要插入的学生记录:" << endl ;
    p=valuen();
    cout << "请输入要插入的位置:" << endl;
    cin >> x;
    if(x<=1){p->next = head;head=p;}
    else{
        prev=head,x--;
        while((--x) && (prev->next !=NULL)){prev=prev->next;}
        p->next=prev->next;
        prev->next = p;
    }

    return 1;
}

int _delete(){//无bug
    int n,m;
    ptr p,q;
    if(head==NULL)return 0;
    p=q=head;
    cout << "请输入删除的学生学号: " << endl;
    cin >> n;
    while(p->sno!=n ){q=p;p=p->next;if(p==NULL)return 0;}
        if(p==q){
            head = p->next;
            
        }
        else q->next = p->next;
        free(p);
        return 1;
}

int clean(ptr &p){
    if(p==NULL)return 0;
    if(p->next != NULL){
        clean(p->next);    
    }
    free(p);
    p=NULL;
    return 1;
}

int sort(){
         ptr h1,prev,p,q,r;//r为将插入的节点,prev,p为h1中的指针,q为head中的指针
         h1 =(ptr)malloc(sizeof(struct Llist));
         if(head!=NULL){*h1=*head;h1->next = NULL;}
         else { cout << "NULL"<<endl ;return 0;}
         q=head;
         for(q=q->next;q!=NULL;q=q->next) {
            prev=p=h1;    
            while(p->sno<=q->sno){prev=p; p=p->next;if(p==NULL) break;}
            r=(ptr)malloc(sizeof(struct Llist));
            *r=*q;
            if(prev==p){
            r->next = prev;
            h1=r;
            }
            else{
                r->next=prev->next;
                prev->next = r;
         }
    }
     output(h1);
     return 1;   
}

int main(){
	int  m;
    do{	
        cout << "1.输入 2.输出 3.搜索 4.插入 5.删除 6.排序 7.清除 8.退出" <<endl ;
        cin >> m;
		switch (m){
			case 1: if(input())cout << "输入成功!\n";break;
			case 2: output(head);break;
			case 3:search();break;
            case 4:if(insert())cout << "插入成功!\n";break;
            case 5:if(_delete())cout << "删除成功!\n";else cout<< "删除失败!可能没有这个值\n";break;
            case 6:sort();break;
            case 7:if(clean(head)) cout << "清除成功!\n";break;
            case 8:break;
            default : m=8 ;break;
		}
    }while(m!=8);
    cout << "press any key to continue! "<< endl ;
    getchar();
}


