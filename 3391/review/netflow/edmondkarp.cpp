#include <iostream>
#include <queue>
using namespace std;

const int maxn = 500;
int G[maxn][maxn];
int Prev[maxn];		// previous node on the path
bool vis[maxn];
int n,m;			// m -> number of vertex & n -> number of edge
// 1 -> source  m -> sink
int Augment()
{
	int v;
	int i;
	deque<int> q;
	memset(Prev,0,sizeof(Prev));
	memset(vis,0,sizeof(vis));
	Prev[1] = 0;
	vis[1] = 1;
	q.push_back(1);
	bool flag = 0;
	while(!q.empty())
	{
		v = q.front();
		q.pop_front();
		for(int i = 1; i <= m; ++i)
		{
			if(G[v][i] > 0 && !vis[i])
			{
				Prev[i] = v;
				if(i == m)
				{
					flag = 1;
					q.clear();
					break;
				}
				else
					q.push_back(i);
			}
		}
	}
	if(!flag)
		return 0;
	int nMinFlow = 1<<30;
	v = m;
	while(Prev[v])
	{
		nMinFlow = min(nMinFlow,G[Prev[v]][v]);
		v = Prev[v];
	}
	v = m;
	while(Prev[v])
	{
		G[Prev[v]][v] -= nMinFlow;
		G[v][Prev[v]] += nMinFlow;
		v = Prev[v];
	}

	return nMinFlow;	
}

int main()
{
	while(cin>>m>>n)
	{
		int i,j,k;
		int s,e,c;
		memset( G,0,sizeof(G));
		for( i = 0;i < n;i ++ ) 
		{
			cin >> s >> e >> c;
			G[s][e] += c; //两点之间可能有多条边 }
			int MaxFlow = 0;
			int aug;
			while(1)
			{
				aug = Augment();
				if(aug == 0) break;
				MaxFlow += aug; 
			}
			cout << MaxFlow << endl;
		}
	}
	return 0;
}