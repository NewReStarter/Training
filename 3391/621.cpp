#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 55;
bool c[N][N];
int b[N][N],d[N][N];

struct edge{
	int u,v,w;
	edge(): u(0),v(0),w(0) {};
	edge(int uu, int vv, int ww):  u(uu),v(vv),w(ww) {}
}e[N*N];

bool cmp(const edge& e1, const edge& e2){
	return e1.w < e2.w;
}

int main()
{
	int n,i,j,k,size;
	while(scanf("%d",&n)!=EOF && n)
	{
		size = 0;
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				cin>>c[i][j];
		for(i = 0; i < n; i++)
			for(j = 0; j <= n; j++)
				cin>>b[i][j];
		for(i = 0; i < n; i++)
			for(j = 0; j <= n; j++)
				cin>>d[i][j];

		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				if(c[i][j])
					b[i][j] = 0;

		for(i = 0; i < n; i++)
			for(j = 0; j <= i; j++)
				e[size++] = edge(i,j,b[i][j]);

		sort(e,e+size,cmp);
		
	}
}