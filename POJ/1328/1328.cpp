#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 1000;
struct interval{
	double l,r;
	interval():l(0),r(0){}
	interval(double _l, double _r):l(_l),r(_r){}
}a[MAXN+10];

bool cmp(const interval& a, const interval& b) {return a.l < b.l;}

int main()
{
	int i,j,k=0;
	int n,d;
	int x,y;
	double tmp;
	int ans;
	while(cin>>n>>d)
	{
		if(n==0 && d == 0)
			break;
		++k;
		ans = 0;
		for(i = 0; i < n; ++i)
		{
			cin>>x>>y;
			tmp = sqrt((d*d)-(y*y));
			a[i].l = x - tmp;
			a[i].r = x + tmp;
		}
		sort(a,a+n,cmp);
		for(i = 0; i < n; ++i)
		{
			j = i + 1;
			while(a[i].r >= a[j].l)
			{
				++j;
			}
			ans++;
			i = j;
		}
		cout<<"Case "<<k<<": "<<ans<<endl;
	}
	return 0;
}