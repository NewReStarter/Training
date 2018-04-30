#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn=1000;  
const int INF = 0x3f3f3f;
 
int l,w,n,d;

struct Edge  
{  
    int from,to,cap,flow;  
    Edge(){}  
    Edge(int f,int t,int c,int flow):from(f),to(t),cap(c),flow(flow){}  
};  

struct  Point
{
	int x,y;
};

Point po[maxn];

int dis2(const Point& a, const Point& b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
  
struct Dinic  
{  
    int n,m,s,t;  
    vector<Edge> edges;  
    vector<int> G[maxn];  
    bool vis[maxn];  
    int cur[maxn];  
    int d[maxn];  
  
    void init(int n,int s,int t)  
    {  
        this->n=n, this->s=s, this->t=t;  
        edges.clear();  
        for(int i=1;i<=n;i++) G[i].clear();  
    }  
  
    void AddEdge(int from,int to,int cap)  
    {  
        edges.push_back(Edge(from,to,cap,0));  
        edges.push_back(Edge(to,from,0,0));  
        m = edges.size();  
        G[from].push_back(m-2);  
        G[to].push_back(m-1);  
    }  
  
    bool BFS()  
    {  
        memset(vis,0,sizeof(vis));  
        queue<int> Q;  
        d[s]=0;  
        Q.push(s);  
        vis[s]=true;  
        while(!Q.empty())  
        {  
            int x=Q.front(); Q.pop();  
            for(int i=0;i<G[x].size();i++)  
            {  
                Edge& e=edges[G[x][i]];  
                if(!vis[e.to] && e.cap>e.flow)  
                {  
                    vis[e.to]=true;  
                    Q.push(e.to);  
                    d[e.to]= 1+d[x];  
                }  
            }  
        }  
        return vis[t];  
    }  
  
    int DFS(int x,int a)  
    {  
        if(x==t || a==0) return a;  
        int flow=0,f;  
        for(int& i=cur[x]; i<G[x].size(); i++)  
        {  
            Edge& e=edges[G[x][i]];  
            if(d[x]+1==d[e.to] && (f=DFS(e.to,min(a,e.cap-e.flow) ))>0 )  
            {  
                e.flow+=f;  
                edges[G[x][i]^1].flow -=f;  
                flow+=f;  
                a-=f;  
                if(a==0) break;  
            }  
        }  
        return flow;  
    }  
  
    int Maxflow()  
    {  
        int flow=0;  
        while(BFS())  
        {  
            memset(cur,0,sizeof(cur));  
            flow += DFS(s,INF);  
        }  
        return flow;  
    }  
}DC;  


void init()
{
	for(int i = 1; i <= n; ++i)
	{
		cin>>po[i].x>>po[i].y;
		DC.AddEdge(2*i,2*i+1,1);
	}

	for(int i = 1; i <= n; ++i)
	{
		if(po[i].y<=d)
			DC.AddEdge(0,2*i,1);
		if(w-po[i].y<=d)
			DC.AddEdge(2*i+1,2*n+2,1);
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; j++)
		{
			if(i!=j && dis2(po[i],po[j]) <= (4*d*d) )
			{
				DC.AddEdge(2*i+1,j*2,1);
				DC.AddEdge(2*j+1,i*2,1);
			}
		}
}


int main()
{
	int k = 1;
	while(scanf("%d%d%d%d",&l,&w,&n,&d) && (l && w && n && d))
	{
		init();
		cout<<"Case "<<k<<": "<<DC.Maxflow()<<endl;

	}
	return 0;
}