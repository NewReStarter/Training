#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

int map[110][110];
long long dis[110];
int n;


int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(map,50,sizeof(map));
		memset(dis,0,sizeof(dis));
		for(int i = 0; i < m; i++)
		{
			int x,y,v;
			cin>>x>>y>>v;
			map[x][y] = v;
			map[y][x] = v;
		}
		for(int i = 1; i<= n; i++)
			map[i][i] = 0;

		for(int k = 1; k<=n; k++)
			for(int i = 1; i<=n; i++)
				for(int j = 1; j<=n; j++)
				{
					if(map[i][j] > map[i][k] + map[k][j])
						map[i][j] = map[i][k] + map[k][j];
				}

		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
			{
				dis[i] += map[i][j];
			}

		// for(int i = 1; i <= n; i++)
		// {
		// 	for(int j = 1; j <= n; j++)
		// 		cout<<map[i][j]<<" ";
		// 	cout<<endl;
		// }

		long long minn = dis[1];
		int c = 1;
		for(int i = 2; i<= n; i++)
		{
			if(dis[i]<minn)
			{
				c = i;
				minn = dis[i];
			}
		}
		cout<<c<<endl;
	}
	return 0;
}