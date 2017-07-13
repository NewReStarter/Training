/*
ID: ziliuga1
LANG: C++11
TASK: milk2
*/
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

struct sp{
	int s;
	int e;
};

bool cmp(sp a, sp b)
{
	return a.s<b.s;
}

int main()
{
	int n;

	//file in

	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);
	
	sp t[5000];

	cin>>n;
	int busy=0, idle=0;

	for(int i=0;i<n;i++)
	{
		cin>>t[i].s>>t[i].e;
	}

	sort(t,t+n,cmp);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(t[i].e>=t[j].s)
				{
					busy = max(busy, t[j].e-t[i].s);
					t[i].e = max(t[j].e,t[i].e);
				}
		}
	}

	bool flag = 1;
	for (int i = 0; i < n-1; i++)
	{
		if(t[i].e<t[i+1].s)
			idle = max(t[i+1].s-t[i].e, idle);
	}
	
	cout<<busy<<" "<<idle<<endl;
	return 0;
}