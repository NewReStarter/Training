// kruskal
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

inline void read(int& x)
{
    char c = getchar(); x = 0;
    while(c < '0' || c > '9') c = getchar();
    while(c <= '9' && c >= '0') x = x*10+c-48, c = getchar();
}

struct edge{
	int u,v,c;
	edge(): u(0),v(0),c(0) {};
	edge(int uu, int vv, int cc): u(uu),v(vv),c(cc) {}
}e[20010];

int size;
const int MAXN = 20010;
//int map[MAXN][MAXN];
int parent[MAXN];

bool cmp(const edge& e1, const edge& e2)
{
	return e1.c < e2.c;
}

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

int main()
{
	int p,r,i,j,x,y,v,ans,cnt;
	while(true)
	{
		read(p);
		if(p == 0) break;
		memset(parent,0,sizeof(parent));
		size = 0;
		//memset(map,20,sizeof(map));
		read(r);
		for(i = 0; i < r; i++)
		{
			read(x);
			read(y);
			read(v);
			//map[x][y] = v;
			e[i] = edge(x,y,v);
		}
		
		sort(e,e+r,cmp);
		for(i = 0; i < p; i++)
			parent[i] = i;
		cnt = ans = 0;
		for(i = 0; cnt < p-1; i++)
		{
			if( find(e[i].u)!= find(e[i].v) ) 
			{
				cnt++;
				ans += e[i].c;
				merge(e[i].u,e[i].v);
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}