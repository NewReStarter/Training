#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

const int MAXN = 30010;
int parent[MAXN];
int ans[MAXN];

int find(int x)
{
	return parent[x] == x ? x : parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
	int xroot = find(x);
	int yroot = find(y);
	if(xroot != yroot)
		parent[xroot] = yroot;
}

void makeset(int x){ parent[x] = x; }

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(ans,0,sizeof(ans));
		int n,m;
		cin>>n>>m;
		for (int i = 1; i <= n; i++)
			makeset(i); 
		for(int i = 0; i < m; i++)
		{
			int x,y;
			cin>>x>>y;
			merge(x,y);
		}
		int maxn = 1;
		for(int i = 1; i <= n; i++)
		{
			ans[find(i)]++;
			maxn = max(maxn,ans[find(i)]);
		}
		cout<<maxn<<endl;
	}
	return 0;
}