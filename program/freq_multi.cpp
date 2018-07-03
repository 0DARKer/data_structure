#include <iostream>
#include <string>
#include <functional>
#include<fstream>
using namespace std;
int myhash(string a){
    hash<string> hash_f;
    int i=hash_f(a);
    if (i<0)i=-i;
    return i%101;
}
/* int compare_(string a,string b){ */
/*     int i; */
/*     for(i=0;a[i]!=0&&b[i]!=0;i++){ */
/*         if(a[i]>b[i])return 1; */
/*         else if (a[i]<b[i])return -1; */
/*         else continue; */
/*     } */
/*     if (a[i]!=0)return 1; */
/*     else if(b[i]!=0)return -1; */
/*     return 0; */
/* } */
int compare_(string a,string b){
    int i;
    for(i=0;a[i]!=0&&b[i]!=0;i++){
        if(a[i]>b[i])return 1;
        else if (a[i]<b[i])return -1;
        else continue;
    }
    if (a[i]!=0)return 1;
    else if(b[i]!=0)return -1;
    return 0;

}
int search_(string words[],int a,int b,string word){
    if(a>b) {
        return -1*a;
    }
    int i=(a+b)/2,j;
    j=compare_(words[i],word);
    if (j==0) return i;
    else if(j==-1)return search_(words,i+1,b,word);
    else return search_(words,a,i-1,word);
}

void initize(){
    int n=1;
    while(n<=100){
        ifstream fin ("dict.file");
        string filename = to_string(n)+".txt";
        ofstream fout(filename);
        while(!fin.eof()){
            string word;
            fin >>word;
            int hash_ = myhash(word);
            if(hash_==n){
                fout << word<<endl;
            }
        }
        n++;
        fin.close();
        fout.close();
    }
}
void words(){
    int N=1;
    /* while(N<=100){ */
    while(N==1){
        string fileinname;
        fileinname=to_string(N)+".txt";
        ifstream fin(fileinname);
        int flag=1; 
        while(flag){ 
        int n=1; 
        ofstream fout("frequency"+to_string(n)+".file",ios::app); 
        string words[1000];
        int frequency[1000];
        while(1){
            if(fin.eof()){
                flag=0;
                break;
            }
            string word;fin >> word;
            int s=search_(words,1,n,word);
            if (s==0)words[1]=word,frequency[1]++;
            else if (s>0)   frequency[s]++;
            else if(s<0){
                s=-s;
                for(int i=n;i>=s;--i){
                    words[i+1]=words[i];
                }
                words[s]=word;
                frequency[s]++;
                n++;
            }
            if(n==999)break;
        }

        for(int i=1;i<=n;i++){
            fout << words[i] << " " << frequency[i]<<endl;
            /* fout << words[i]<<endl; */
        }
        fout.close();
    }
    fin.close();
    N++;
    }
}

int main(){
    /* initize(); */
    /* words(); */

}

