#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int xx[] {1,2,2,1,-1,-2,-2,-1};
int yy[] {2,1,-1,-2,-2,-1,1,2};

bool map[10][10];
bool v[10][10];
struct node{
	int x;
	int y;
	int c;
};

int main()
{
	int n;
	int sx,sy;
	int tx,ty;
	scanf("%d",&n);
	char ch[10];
	for(int k = 1;k <= n;k++)
	{
		memset(map,0,sizeof(map));
		memset(v,0,sizeof(v));
		for(int i = 1;i <= 8; i++)
		{
			cin>>ch;
			for(int j = 0; j < 8; j++)
			{
				if(ch[j]=='#')
				{
					sx = i;
					sy = j+1;
				}
				else if(ch[j]=='@')
				{
					tx = i;
					ty = j+1;
				}
				else if(ch[j]=='*')
					map[i][j+1] = 1;
				else
					map[i][j+1] = 0;
			}
		}
		// for(int i = 1 ; i <= 8 ; i++)
		// {
		// 	for(int j = 1 ; j <= 8 ; j++)
		// 		cout<<map[i][j];
		// 	cout<<endl;
		// 	cout<<endl;
		// }

		int head,rear;
		head = rear = 0;
		node q[1000];
		q[0].x=sx;
		q[0].y=sy;
		q[0].c=0;
		v[sx][sy]=1;
		rear++;
		while(head!=rear)
		{
			if(q[head].x==tx && q[head].y==ty)
			{
				printf("Case %d: %d\n",k,q[head].c);
				break;
			}
			for(int i = 0; i < 8; i++)
			{
				int tmpx = q[head].x+xx[i];
				int tmpy = q[head].y+yy[i];
				if(tmpx >=1 && tmpx <=8 && tmpy >= 1 && tmpy <= 8 && !map[tmpx][tmpy] && !v[tmpx][tmpy])
				{
					node tmp;
					tmp.x = tmpx;
					tmp.y = tmpy;
					tmp.c = q[head].c+1;
					v[tmpx][tmpy] = 1;
					q[rear++] = tmp;
				}
			}
			head++;
		}
		if(head == rear)
			printf("Case %d: IMPOSSIBLE\n",k);
	}
	return 0;

}