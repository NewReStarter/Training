#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 6000;
const int maxm = 100000;
const int INF = 0x3f3f3f3f;
int G[maxn][maxn],f[maxn][maxn];
int Prev[maxn];
int a[maxn];
int m,n;

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
	H.init(n+2);
	for(int i = 1; i<=n; ++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		H.AddEdge(0,i,a);
		H.AddEdge(i,n+1,b);
	}
	for(int i = 1; i <= m; ++i)
	{
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		H.AddEdge(a,b,w);
		H.AddEdge(b,a,w);
	}
}

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		init();
		cout<<H.Maxflow(0,n+1)<<endl;
	}
	return 0;
}