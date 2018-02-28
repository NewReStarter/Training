#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

bool v[60][60];
int m[60][60];

int xx[] {-1,-1,-1,0,0,1,1,1};
int yy[] {-1,0,1,-1,1,-1,0,1};
int x,y;
void bfs(int sx, int sy)
{
	int qx[10000];
	int qy[10000];
	int head= 0;
	int rear = 0;
	qx[rear] = sx;
	qy[rear++] = sy;
	while(head!=rear)
	{
		for(int i = 0; i < 8; i++)
		{
			int tx,ty;
			tx = qx[head]+xx[i];
			ty = qy[head]+yy[i];
			if(tx >= 1 && tx <=y && ty >=1 && ty <= x && !v[tx][ty] && m[tx][ty])
			{
				v[tx][ty] = 1;
				qx[rear] = tx;
				qy[rear++] = ty;
			}
		}
		head++;
	}
}

int main()
{
	
	while(true)
	{
		int count = 0;
		scanf("%d%d",&x,&y);
		if(x == 0 && y==0)
			break;
		memset(m,0,sizeof(m));
		for(int i = 1; i <= y; i++)
			for(int j = 1; j<=x; j++)
				scanf("%d",&m[i][j]);
		memset(v,0,sizeof(v));

		for(int i = 1; i <= y; i++)
			for(int j = 1; j<=x; j++)
			{
				if(m[i][j] && !v[i][j])
				{
					bfs(i,j);
					count++;
				}
			}
		cout<<count<<endl;
	}
	return 0;
}