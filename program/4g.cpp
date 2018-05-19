#include<iostream>
#include<fstream>
using namespace std;
int main(){

    ifstream fin("/home/darker/4g/dict2");
    ofstream fout("/mnt/file.txt",ios::app);
    string a;
    char b[1000];
    cout << "读取文件,写入文件...."<<endl;
    while(!fin.eof()){
        fin >> a;
        for(int i=0,j=0;a[i]!='\000';i++){
        if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')){
            b[j++]=a[i];
            while(++i){
                if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')){
                b[j++]=a[i];
                }
                else {
                b[j++]='\000';
               if (j<30) 
                fout << b<<endl;
                j=0;
                break;
                }
            }
        } 
    }
    }
    cout << "完成!"<< endl;

}
