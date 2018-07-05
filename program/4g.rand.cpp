//对文件的切词还是不够大,这个程序对切词的文件中的每个词随机扩大..
//好像有bug.
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    char a[20];
    int i,j;
    //利用ofstream类的构造函数创建一个文件输出流对象来打开文件 
    ofstream fout( "/home/darker/4G.txt" );  
    if ( ! fout){
        cout << "文件不能打开" <<endl;
    }
    else{
        while(1){
            j=rand()%(15-1+1)+1;
        for(i=0;i<j;i++){
            if (rand()%2==1){
                a[i]=rand()%('z'-'a'+1)+'a';
            }
            else {
                a[i]=rand()%('Z'-'A'+1)+'A';
            }
        }
        a[++i]='\n';
        fout << a << endl; 
        }
    }
}
