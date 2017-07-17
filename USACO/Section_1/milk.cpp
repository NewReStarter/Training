/*
ID: ziliuga1
LANG: C++11
TASK: milk
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct farmer{
	int v;//volume
	int p;//price
};

bool cmp(farmer &a, farmer &b)
{
	return a.p<b.p;
}



int main()
{
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);

	int n,m;//n->total amount m->maxiunm farmer
	farmer f[5000];
	cin>>n>>m;
	for(int i=0; i<m; ++i)
		cin>>f[i].p>>f[i].v;
	sort(f,f+m,cmp);
	int total=0,cost=0;
	int idx=0;
	while(total < n)
	{
		if(total+f[idx].v <= n)
		{
			total+=f[idx].v;
			cost+=f[idx].v*f[idx].p;
		}
		else{
			int rest = n-total;
			total = n;
			cost+=rest*f[idx].p;
		}
		++idx;
	}
	cout<< cost <<endl;
	return 0;

}