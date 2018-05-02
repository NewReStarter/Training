#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 200;
int G[maxn][maxn];
int vis[maxn];
int matched[maxn];
int m,n;
int s,e,t;
int k;

bool find(int x)
{
	//cout<<x<<" ";
	for(int i = 1; i < m; ++i)
	{
		if(G[x][i] == 1 && !vis[i])
		{
			vis[i] = 1;
			if(!matched[i] || find(matched[i]))
			{
				matched[i] = x;
				return 1;
			}
		}
	}
	return 0;
}

int hungry(int n)
{
	int cnt = 0;
	for(int i = 1; i < n; ++i)
	{
		memset(vis,0,sizeof(vis));
		if(find(i))
			++cnt;
	}
	return cnt;
}

inline void read(int& x)
{
    char c = getchar(); x = 0;
    while(c < '0' || c > '9') c = getchar();
    while(c <= '9' && c >= '0') x = x*10+c-48, c = getchar();
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		memset(G,0,sizeof(G));
		memset(matched,0,sizeof(matched));
		read(m);
		read(k);
		//cout<<n<<m<<k;
		for(int i = 0; i < k; ++i)
		{
			read(s);read(e);
			if(s!=0&&e!=0)
				G[s][e] = 1;
		}
		
		cout<<hungry(n)<<endl;
	}
	return 0;
}