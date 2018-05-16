#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

bool p(string s)
{
	int m = s.size();
	for(int i = 0; i <= (int)m/2 ; ++i)
		if(s[i] != s[m-i-1])
			return 0;
	return 1;
}

int pal(string s)
{
	int n = s.size();
	vector<int> index;
	for(int i = 0; i < n-1 ; ++i)
	{
		if(s[i] == s[n-1])
			index.push_back(i);
	}
	for(int i = 0; i < index.size(); ++i)
	{
		string tmp = s.substr(index[i],n-index[i]);
		if(p(tmp))
			return index[i]
	}
	return n-1;
}

int main()
{
	string s;
	while(cin>>s)
	{
		if(p(s))
		{
			cout<<s<<endl;
			continue;
		}
		int n = s.size();
		int index = fun(s);
		string tmp = s.substr(0,index);
		reverse(tmp.begin(),tmp.end());
		cout<<s+tmp<<endl;
	}
	return 0;
}
