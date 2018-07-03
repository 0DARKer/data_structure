#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("dict.txt");
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
/* int main(){ */
/*     string a,b[5]; */
/*     cin >>a; */
/*     b[1]="dao"; */
/*     b[2]="mong"; */
/*     b[3]="sheng"; */
/*     cout << search_(b,1,3,a); */

/* } */
/* int main(){ */
/*     int flag=1; */
/*     while(flag){ */
/*         int n=1; */
/*         ofstream fout(a); */
        flag=1
        string words[1000];
        int frequency[1000];
        while(1){
            if(fin.eof()){
                flag=0;
                break;
            }
            string word;
            fin >> word;
            int s=search_(words,1,n,word);
            if(s>0)frequency[s]++;
            else if(n==999)break;
            else if(s<0){
                s=-s;
                for(int i=n;i>=s;--i){
                    words[i+1]=words[i];
                }
                words[s]=word;
                n++;
            }
        }
        for(int i=1;i<=n;i++){
            fout << words[i] << " " << frequency[i]<<endl;
        }
        flag++;
        
    }
    fin.close();
    ifstream fin2("frequency.txt");
    ofstream fout2("words.txt");
    while(!fin2.eof()){
        string a;
        int b;
        fin2 >> a>>b;
    }

}
