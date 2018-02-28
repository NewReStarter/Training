#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int map[150][150];
int dis[150][150];

int xx[4] {0,1,0,-1};
int yy[4] {1,0,-1,0};

struct node{
	int x;
	int y;
};

int main()
{
	int i,j,n,c;
	c=1;
	while(true)
	{
		cin>>n;
		if(n==0)
			break;
		for(i = 0; i<n; i++)
			for(j = 0; j<n; j++)
				cin>>map[i][j];
		int head,rear;
		head=rear=0;
		memset(dis,125,sizeof(dis));
		node q[200000];
		dis[0][0] = map[0][0];
		node s;
		s.x = 0;
		s.y = 0;
		q[rear++]=s;
		while(head!=rear)
		{
			for(i = 0; i<4; i++)
			{
				node tmp;
				tmp.x = q[head].x+xx[i];
				tmp.y = q[head].y+yy[i];
				if(tmp.x>=0 && tmp.x < n && tmp.y>=0 && tmp.y < n && dis[tmp.x][tmp.y] > dis[q[head].x][q[head].y] + map[tmp.x][tmp.y])
				{
					dis[tmp.x][tmp.y] = dis[q[head].x][q[head].y] + map[tmp.x][tmp.y];
					q[rear++]=tmp;
				}
			}
			head++;
		}
		printf("Problem %d: %d\n",c++,dis[n-1][n-1]);
	}
	return 0;
}