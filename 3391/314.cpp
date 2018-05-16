#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 120000;
string s1,s2;

struct kmp
{
	int f[maxn];

	void process(string s)
	{
		f[0] = -1;
		for(int i = 0, j = -1; s[i];)
		{
			while(j>=0 && s[j]!=s[i]) j = f[j];
			f[++i] = ++j;
		}
	}

	int match(string T, string P)
	{
		int i,j,n=T.size(),m=P.size();
		for(i = 0, j = 0; T[i] ;)
		{
			while(j >= 0 && T[i]!=P[j]) j = f[j];
			i++,j++;
			if(j==m) return m;
		}
		return j;
	}
} kk;

int main()
{
	while(cin>>s1)
	{
		s2 = s1;
		reverse(s2.begin(),s2.end());
		kk.process(s2);
		int idx = kk.match(s1,s2);
		cout<<s1;
		for(int i = idx; s2[i]; ++i)
			cout<<s2[i];
		cout<<endl;
	}
	return 0;
}