#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream fin("3.2G.txt");
    while(1){
        string a;
        fin >> a;
        cout << a<< endl;

    }
}
