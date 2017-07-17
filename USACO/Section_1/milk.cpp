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
/*
One thing I do not understand from begining is what if the first n-th cheapest farmers cannot provide enough units of milk. Then I realize
that it is not the case as I suppoesd. m denotes the total number of farmers, which is sufficient to get n units of milk. Hence, reading
carefully is important. The way I think it, it would become a Bin Packing Dynamic Programming Question.


*/
