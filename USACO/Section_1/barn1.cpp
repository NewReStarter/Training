/*
ID: ziliuga1
LANG: C++11
TASK: barn1
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

bool cmp(int &a, int &b)
{
	return a>b;
}

int m,s,c;
int idle[200]={0};
bool line[200]={0};
int main()
{
	freopen("barn1.in","r",stdin);
	freopen("barn1.out","w",stdout);
	cin>>m>>s>>c;
	int maxm=0, minm=s;
	int tmp;
	for(int i=0;i<c;i++)
	{
		cin>>tmp;
		line[tmp]=1;
		maxm = max(maxm,tmp);
		minm = min(minm,tmp);
	}
	int len=maxm-minm;
	int count = 0;
	int idx=0;
	for(int i=minm;i<=maxm;i++)
	{
		if(!line[i])
			++count;
		else
		{
			idle[idx++]=count;
			count=0;
		}
	}
	sort(idle,idle+s,cmp);
	for(int i=0;i<m-1;i++)
		len-=idle[i];
	cout<<len+1<<endl;
	return 0;

}