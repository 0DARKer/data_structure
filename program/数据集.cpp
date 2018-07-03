#include <fstream>
#include<iostream>
#include <stdlib.h>
#include <time.h> 
using namespace std;
void creat()
{
	char ch;
	ifstream infile("file.txt",ios::in);
	if(!infile)
	{
		cout<<"open in.txt error!"<<endl;
		exit(1);
	}	
	ofstream outfile("1.6G.txt",ios::app);

	if(!outfile)
	{
		cout<<"open file.txt error!"<<endl;
		exit(1);
	}
	
	while(infile.get(ch))
	{
		if(ch>=97&&ch<=122||ch>=65&&ch<=91)
		outfile.put(ch);
		if(ch==' ')outfile<<endl;
	}
	infile.close();
	outfile.close();
}
int main()
{ 
	int i,num;	

//	srand((unsigned) time(NULL)); 
//	num=rand()%500;
	num=400;
	cout<<num<<endl;
	for(i=0;i<num;i++)
		creat();
	return 0;
}

