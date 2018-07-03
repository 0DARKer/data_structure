#include<iostream>
#include<fstream>
using namespace std;
int compare_(string a,string b){
    for(int i=0;a[i]!=EOF&&b[i]!=EOF;i++){
        if(a[i]>b[i])return 1;
        else if (a[i]<b[i])return -1;
        else return 0;
    }
}
int search_(string words[],int a,int b,string word){
    if(a==b) {
        return -1*a;
    }
    int i,j;
    j=compare_(words[i=(a+b)/2],word);
    if (j==0) return i;
    else if(j==-1)search_(words,i,b,word);
    else search_(words,a,i,word);
}
int main(){
    ifstream fin("article.txt");
    ofstream fout1("words.txt");
    ofstream fout2("frequency.txt");
    string words[10000];
    int frequency[10000];
    int b=1;
    while(!fin.eof()){
        string word;
        fin >> word;
        int c=search_(words,1,b,word);
        if(c>0)frequency[c]++;
        else if(b==9999){
            fout1 << word;
            continue;
        }
        else if(c<0){
            c=-c;
            for(int i=b;i>=c;--i){
                words[i+1]=words[i];
            }
            words[c]=word;
        }
    }
}
