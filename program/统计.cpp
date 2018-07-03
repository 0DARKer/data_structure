#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<fstream>
using namespace std;

int init()
{
    map<string, int> M;
    map<string, int>::iterator j;
    string t;
    ifstream fin("3.2G.file");
    ofstream fout("freq.output");
    while(fin>>t)
        M[t]++;
    for(j=M.begin(); j!=M.end(); ++j)
        fout<<j->first<<"\t"<<j->second<<endl;
    fin.close();
    fout.close();
    return 0;
}

int main(){
    init();
    /* int a[MAX]; */
    /* while(!fin.eof()){ */
    /*     string word; */
    /*     int wordfreq; */
    /*     fin >> word >> wordfreq; */
    /*     a[wordfreq]++; */
    /* } */
    /* for(int i=MAX-1;i>=0;i--){ */
    /*     if(a[i]>0){ */
    /*         a[i]--; */
    /*         fout << i; */
    /*     } */
    /* } */
}
