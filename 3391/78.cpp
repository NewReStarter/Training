#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

string search(string s)
{
	//cout<<s<<endl;
	//get substr recur way
	if(s.size() == 1)
		return s;
	string tmp = search(s.substr(1));
	
	if(tmp[0] <= s[0])
		return s[0]+tmp;
	return tmp;
}

int main()
{
	int t;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		cout<<search(s)<<endl;
	}
	return 0;
}