#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxn = 400;
const int INF = 0x3f3f3f3f;

int n,m;
int v[maxn][maxn];

void floyd()
{
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				v[i][j] |= (v[i][k] & v[k][j]);
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF){
	int a,b;
	memset(v,0,sizeof(v));
	for(int i = 1; i <= m; ++i)
	{
		cin>>a>>b;
		v[a][b] = 1;
	}
	floyd();
	int ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		int tmp = 0;
		for(int j = 1; j <= n; ++j)
		{
			if(v[i][j] || v[j][i])
				tmp++;
		}
		if(tmp == n-1) ans++;
	}
	cout<<ans<<endl;
	}
	return 0;
}