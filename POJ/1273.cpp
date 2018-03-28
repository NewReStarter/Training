#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int MAXN = 300;
int map[MAXN][MAXN];
int pre[MAXN];
bool vis[MAXN];
int m,n;

unsigned Augment()
{
	int q[MAXN*2];
	memset(pre,0,sizeof(pre));
	memset(vis,0,sizeof(vis));
	int i,v,head,rear;
	head = rear = 0;
	pre[1] = 0;
	vis[1] = 1;
	q[rear++] = 1;
	bool flag = 0;
	while(head!=rear)
	{
		v = q[head];
		//cout<<v<<endl;
		for(i = 1; i <= m; i++)
		{
			if(map[v][i] > 0 && !vis[i])
			{
				//cout<<i<<endl;
				pre[i] = v;
				vis[i] = 1;
				if(i == m)
				{
					flag = 1;
					head = rear;
					break;
				}
				else
				{
					q[rear++] = i;
				}
			}
		}
		if(head == rear)
			break;
		head++;
	}
	if(!flag)
		return 0;
	int minn = 2147483647;
	v = m;
	while(pre[v])
	{
		minn = min(minn,map[pre[v]][v]);
		v = pre[v];
	}
	v = m;
	while(pre[v])
	{
		map[pre[v]][v] -= minn;
		map[v][pre[v]] += minn;
		v = pre[v];
	}
	return minn;
}

int main()
{
	int i,j,k;
	int s,e,c;
	while(cin>>n>>m)
	{
		memset(map,0,sizeof(map));
		for(i = 0; i < n; i++)
		{
			cin>>s>>e>>c;
			map[s][e] += c;
		}
		unsigned int maxFlow = 0;
		unsigned int aug;
		//cout<<Augment()<<endl;
		while(true)
		{
			aug = Augment();
			if(aug == 0)
				break;
			maxFlow += aug;
		}
		cout<<maxFlow<<endl;
	}
	return 0;
}