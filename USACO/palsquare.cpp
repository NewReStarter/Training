/*
ID: ziliuga1
LANG: C++11
TASK: palsquare
*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int base;
string trans(int x);
bool ispal(string s);
string r(string s);
int main()
{
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
	cin>>base;
	for(int i=1; i<=300; i++)
	{
		string tmp=trans(i*i);
		if(ispal(tmp))
			cout<<r(trans(i))<<" "<<tmp<<endl;
	}
	return 0;
}

string trans(int x)
{
	string s;
	int d,m;
	while(x>=base)
	{
		m = x%base;
		if(m<10) s+=(char)(m+48);
		else s+=(char)(m+55);
		x/=base;
	}
	if(x<10) s+=(char)(x+48);
	else s+=(char)(x+55);

	return s;
}

inline bool ispal(string s)
{
	int last=s.length()-1;
	int first=0;
	while(last>=first)
	{
		if(s[last]!=s[first])
			return 0;
		last--;
		first++;
	}
	return 1;
}

string r(string s)
{
	string tmp;
	for(int i=s.length()-1; i>=0;i--)
		tmp+=s[i];
	return tmp;
}