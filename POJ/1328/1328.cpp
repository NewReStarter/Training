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
		bool flag = 0;
		for(i = 0; i < n; ++i)
		{
			cin>>x>>y;
			int po = (d*d)-(y*y);
			if(po < 0 || d < 0) flag = 1;
			tmp = sqrt(po);
			a[i].l = x - tmp;
			a[i].r = x + tmp;
		}
		sort(a,a+n,cmp);
		// for(i = 0; i < n; ++i)
		// 	cout<<a[i].l<<" "<<a[i].r<<endl;
		for(i = 0; i < n; ++i)
		{
			interval t = a[i];
			// cout<<a[i].l<<" "<<a[i].r<<endl;
			j = i + 1;
			while(t.r >= a[j].l)
			{
				t.r = min(t.r,a[j].r);
				++j;
			}
			++ans;
			i = j-1;
		}
		if(!flag)
			cout<<"Case "<<k<<": "<<ans<<endl;
		else
			cout<<"Case "<<k<<": "<<"-1"<<endl;
	}
	return 0;
}