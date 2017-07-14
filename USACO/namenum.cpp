/*
ID: ziliuga1
LANG: C++11
TASK: namenum
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

string wlist[5000];
char num[12];
int count=0;


void listInput()
{
	ifstream in;
	in.open("dict.txt");
	while(!in.eof())
	{
		string w;
		in>>w;
		wlist[count++] = w;
	}
}

string translate(string s)
{
	string tmp;
	for(int i=0; i<s.length(); i++)
	{
		if(s[i]=='A' || s[i] =='B' || s[i] == 'C')
			tmp+="2";
		else if(s[i]=='D' || s[i] =='E' || s[i] == 'F')
			tmp+="3";
		else if(s[i]=='G' || s[i] =='H' || s[i] == 'I')
			tmp+="4";
		else if(s[i]=='J' || s[i] =='K' || s[i] == 'L')
			tmp+="5";
		else if(s[i]=='M' || s[i] =='N' || s[i] == 'O')
			tmp+="6";
		else if(s[i]=='P' || s[i] =='R' || s[i] == 'S')
			tmp+="7";
		else if(s[i]=='T' || s[i] =='U' || s[i] == 'V')
			tmp+="8";		
		else if(s[i]=='W' || s[i] =='X' || s[i] == 'Y')
			tmp+="9";
	}
	return tmp;
}

int main()
{
	freopen("namenum.in","r",stdin);
	freopen("namenum.out","w",stdout);
	string num;
	cin>>num;
	listInput();
	bool flag=0;
	for(int i = 0; i < count ; i++)
	{
		if(wlist[i].length() == num.length())
			if(translate(wlist[i]) == num)
				{
					cout<<wlist[i]<<endl;
					flag=1;
				}
	}
	if(!flag) cout<<"NONE"<<endl;
	return 0;
}	


