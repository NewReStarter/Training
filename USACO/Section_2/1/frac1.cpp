/*
ID: ziliuga1
LANG: C++11
TASK: frac1
*/
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct num{
	string p;
	double v;
}a[40000];
bool v[161][161] {0};
int n;
inline bool cmp(num &a, num &b)
{
	return a.v<b.v;
}

int gcd(const int m, const int n)
{
	if(n==0) return m;
	else gcd(n,m%n);
}

string toStr(const int a)
{
	return to_string(a);
}

int main()
{
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	cin>>n;
	int len=0;
	for(int i = 1; i<=n; i++)
		for(int j=0; j<=i; j++)
		{
			if(!v[i/(gcd(i,j))][j/(gcd(i,j))])
			{
				string up,down;
				up = toStr(j/(gcd(i,j)));
				down = toStr(i/(gcd(i,j)));
				v[i/(gcd(i,j))][j/(gcd(i,j))]=1;
				a[len].p = up + "/" + down;
				a[len++].v=(double)j/(double)i;

			}
		}
	sort(a,a+len,cmp);
	for(int i=0;i<len;i++)
		cout<<a[i].p<<endl;
	return 0; 
}

/*
notice that a double can not be divided 0, or float point exception
*/
