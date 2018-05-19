#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#define M 20
#define MAX 100
using namespace std;
double elem[M],_char[M];
int te,tc;
int a[127];

int push(int &top,double s[],double a){
    if(top==M-1)return -1;
    s[++top]=a;
    return 0;
}
int pop(int &top,double s[],double &a){
    if(top==-1)return -1;
    a=s[top--];
    return 0;
}

void initrc(){ 
    int i;
    for(i=0;i<127;i++)a[i]=MAX;
    a['+']=1,a['-']=1,a['*']=2,a['/']=2,a['^']=3,a['(']=MAX-1,a[',']=0,a[')']=-1,a['@']=-2;
    a['s']=MAX-2,a['c']=MAX-2;a['r']=MAX-2;//这里s表示sin,c表示cos,要想增添新函数或者修改原函数,需要修改本处,calculate()函数,以及get_char()函数.
  
}
double calculate(double &m){//取出运算符计算,结果储存在m,返回零就将m值存入elem中
    double c,x,y,z=1;
    if(pop(tc,_char,c)==0){
        switch((int)c){
            case '+':pop(te,elem,x),pop(te,elem,y);m= y+x;return 0;
            case '-':pop(te,elem,x),pop(te,elem,y);m= y-x;return 0;
            case '*':pop(te,elem,x),pop(te,elem,y);m= y*x;return 0;
            case '/':pop(te,elem,x),pop(te,elem,y);m= y/x;return 0;
            case '^':pop(te,elem,x),pop(te,elem,y);for(int i=0;i<x;i++)z*=y;m=z ;return 0;
            case 's':pop(te,elem,x),m=sin(x);return 0;
            case 'c':pop(te,elem,x),m=cos(x);return 0;
            case 'r':pop(te,elem,x),m=sqrt(x);return 0;
            case '(':return 1;
            case ',':return 1; 
            case ')':return 1;
            case '@':return 1;
            default : return -1;
        }
    }
}
double get_char(char C[],double &d){//常量的更改在这
char c;
int i=0;
while(1){
    c=getchar();
    if((c>='a' && c<='z')||(c>='A' && c<='Z')){
        C[++i]=c;
        continue;
    }
    else {
        C[++i]='\000';
        !strcmp(C,"sin") ? d='s',C[9]='a'://通过标记C[9]来确定输入的字符串是函数(a)还是常量(1)还是无意义(\000)
            !strcmp(C,"cos") ? d='c',C[9]='a':
            !strcmp(C,"sqrt") ? d='r',C[9]='a':
            !strcmp(C,"pi") ? d=3.141592654,C[9]='1':C[9]='\000';
        return c;
    }
}
}
double getelem(double &d){
    char c;
    double decimal =0;
    while (1){
        c=getchar();
        if(c>='0'&&c<='9'){
        d=d*10+c-'0';
        decimal*=0.1;
        continue ;
        }  
        else if(c=='.'){
            decimal=1;
            continue;
        }
        else {
            decimal==0 ? d=d:d=d*decimal;
            return c;
        }
    }
}
int main(){
    double c;
    double m;
    double d=0;
    char C[10];
    initrc();
    te=tc=-1;
    while((c=getchar())!=EOF){
        if(c>='0'&&c<='9'){
            d=d*10+c-'0';
            c=getelem(d);
            push(te,elem,d),d=0;
        } 
        if((c>='a' && c<='z')||(c>='A' && c<='Z')){
            C[0]=(char)c;
            c=get_char(C,d);
            if (C[9]=='\000') cout << "unknown type !"<<endl ,te=tc =-1; 
            else if(C[9]=='1')push(te,elem,d);
            else if(C[9]=='a')push(tc,_char,d);
            d=0;
        }
        if(c=='\n'){
            while(tc!=-1){
                if(calculate(m)==0)
                push(te,elem,m);
            }
            pop(te,elem,m);
            te=tc=-1;
             cout<<setiosflags(ios::fixed)<<setprecision(2)<< m << endl;
            continue;
        }

        while(a[(int)c]<=a[(int)_char[tc]] && tc !=-1){
            if(calculate(m)==0){
            push(te,elem,m);
            }
        }
        if (a[(int)c]!=MAX && a[(int)c]!=0) {
            push(tc,_char,c);
            if( a[(int)c]==MAX-1)push(tc,_char,'@');
        }
    }
} 
