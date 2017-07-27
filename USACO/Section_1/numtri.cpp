/*
ID: ziliuga1
LANG: C++11
TASK: numtri
*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int a[1010][1010] {0} ;
int n;
void solve();
int main()
{
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin>>a[i][j];
		}
	}
	solve();
	return 0;
}

void solve()
{
	for(int i = n-1; i >0 ; i--)
		for(int j = 1; j <= i ; j++)
		{
			a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
		}
	cout<<a[1][1]<<endl;
}
/*
dp 101. bottom up
*/
