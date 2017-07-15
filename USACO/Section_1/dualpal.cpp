/*
ID: ziliuga1
LANG: C++11
TASK: dualpal
*/

#include <iostream>
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
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);
	int n,s;
	int flag;
	cin>>n>>s;
	int count = 0;
	while(count < n)
	{
		++s;
		for(base=2;base<=10;base++)
		{
			if(ispal(trans(s)))
				++flag;
		}
		if(flag>=2)
		{
			cout<<s<<endl;
			++count;
		}
		flag=0;
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

	return r(s);
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
/*
Use same idea as palsquare.cpp. Adding a flag to mark the number of presentations matches the requirement
*/
