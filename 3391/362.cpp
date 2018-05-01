#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn=1000;  
 
int l,w,n,d;

struct  Point
{
	int x,y;
};

Point po[maxn];

int dis2(const Point& a, const Point& b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

const int maxm = 30000 + 5;
const long long INF = 0x3f3f3f;

struct Edge {
    int from, to, cap, flow;
    Edge(){}
    Edge(int from, int to, int cap, int flow) {
        this->from = from;
        this->to = to;
        this->cap = cap;
        this->flow = flow;
    }
};

struct Dinic {
    int n, m, s, t;
    Edge edges[maxm];
    int head[maxn];
    int nxt[maxm];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];

    void init(int n) {
        this -> n = n;
        memset(head, -1, sizeof(head));
        m = 0;
    }

    void AddEdge(int u, int v, int c) {
        edges[m] = Edge(u, v, c, 0);
        nxt[m] = head[u];
        head[u] = m++;
        edges[m] = Edge(v, u, 0, 0);
        nxt[m] = head[v];
        head[v] = m++;
    }

    bool BFS() {
        memset(vis, 0, sizeof(vis));
        queue<int>Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while (!Q.empty()) {
            int x = Q.front(); Q.pop();
            for (int i = head[x]; i != -1; i = nxt[i]) {
                Edge& e = edges[i];
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int DFS(int x, int a) {
        if (x == t || a == 0) return a;
        int flow = 0, f;
        for (int& i = cur[x]; i != -1; i = nxt[i]) {
            Edge& e = edges[i];
            if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap-e.flow))) > 0) {
                e.flow += f;
                edges[i^1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }

    int Maxflow(int s, int t) {
        this -> s = s; this -> t = t;
        int flow = 0;
        while (BFS()) {
            for (int i = 0; i < n; i++)
                cur[i] = head[i];
            flow += DFS(s, INF);
        }
        return flow;
    }
} H;


void init()
{
	H.init(2*n+2);
	for(int i = 1; i <= n; ++i)
	{
		cin>>po[i].x>>po[i].y;
		H.AddEdge(2*i,2*i+1,1);
	}

	for(int i = 1; i <= n; ++i)
	{
		if(po[i].y<=d)
			H.AddEdge(0,2*i,1);
		if(w-po[i].y<=d)
			H.AddEdge(2*i+1,2*n+2,1);
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; j++)
		{
			if(i!=j && dis2(po[i],po[j]) <= (4*d*d) )
			{
				H.AddEdge(2*i+1,j*2,1);
				H.AddEdge(2*j+1,i*2,1);
			}
		}
}


int main()
{
	int k = 1;
	while(scanf("%d%d%d%d",&l,&w,&n,&d) && (l && w && n && d))
	{
		init();
		cout<<"Case "<<k<<": "<<H.Maxflow(0,2*n+2)<<endl;

	}
	return 0;
}