#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int parent[1000100],ans[1000100];

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

struct edge{
	int x;
	int y;
	edge(): x(0),y(0) {};
	edge(int xx, int yy): x(xx),y(yy){}
}e[1000100];

int main()
{
	int n,m,x,y,v;
	while(true)
	{
		cin>>n>>m;
		if(n == 0 && m == 0) break;
		int maxn = 0;
		int size = 0;
	    for(int i = 1; i<=n; i++)
	    {
	    	parent[i] = i;
	    	ans[i] = 0;
	    }
		for(int i = 0; i < m; i++)
		{
			cin>>x>>y>>v;
			if(v>maxn)
			{
				e[0] = edge(x,y);
				maxn = v;
				size = 1;
			}
			else if(v == maxn)
			{
				e[size++] = edge(x,y);
			}
		}

		for(int i = 0; i < size; i++)
			merge(e[i].x,e[i].y);
		int cnt = 0;
		for(int i = 0; i <= n; i++)
		{
			ans[find(i)]++;
			cnt = max(cnt,ans[find(i)]);
		}
		cout<<cnt<<endl;
	}
}