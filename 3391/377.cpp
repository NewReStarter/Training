#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 30000;
const int MAXM = 100000;
const int INF = 0x3f3f3f3f;

int Head[MAXN],q[MAXN],cur[MAXN],lvl[MAXN],w[MAXN];
int n,m,tot=2;

ll ans;

struct Edge{
    int v,next,f;
}edge[MAXM*2];

void addEdge(int x, int y, int f)
{
    edge[tot] = (Edge){y,Head[x],f};
    Head[x] = tot++;
    edge[tot] = (Edge){x,Head[y],0};
    Head[y] = tot++;
}

bool bfs(int s,int t)
{
    memset(lvl,0,sizeof(lvl));
    int l,r; l = r = 0;
    q[r++] = s; lvl[s] = 1;
    while(l<r)
    {
        int u = q[l++];
        if(u==t) return 1;
        for(int i = Head[u];i;i=edge[i].next)
        {
            int v = edge[i].v, f = edge[i].f;
            if(!lvl[v] && f)
            {
                lvl[v] = lvl[u]+1;
                q[r++] = v;
            }
        }
    }
    return 0;
}

int dfs(int u, int t, int maxflow)
{
    if(u==t) return maxflow;
    int ret = 0;
    for(int i = cur[u];i;i=edge[i].next)
    {
        int v = edge[i].v;
        int f = edge[i].f;
        if(lvl[v]==lvl[u]+1 && f)
        {
            int Min = min(maxflow-ret,f);
            f = dfs(v,t,Min);
            edge[i].f -= f;
            edge[i^1].f += f;
            cur[u]=i;
            ret += f;
            if(maxflow==ret) return maxflow;
        }
    }
    return ret;
}

ll dinic(int s, int t)
{
    ll ans = 0;
    while(bfs(s,t))
    {
        for(int i = 0; i <=t; ++i)
            cur[i] = Head[i];
        ans+=(ll)dfs(s,t,INF);
    }
    return ans;
}

// if not full in res net, fire
int bfs_res(int s)
{
    int cnt = 0;
    memset(lvl,0,sizeof(lvl));
    int l,r;
    l=r=0;
    q[r++] = s;
    lvl[s] = 1;
    while(l<r)
    {
        int u = q[l++];
        for(int i = Head[u];i;i=edge[i].next)
        {
            int v= edge[i].v;
            int f = edge[i].f;
            if(!lvl[v] && f)
            {
                lvl[v] = 1;
                q[r++]=v;
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    scanf("%d%d",&n,&m);
    tot = 2;
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d",&w[i]);
        if(w[i] > 0)
        {
            addEdge(0,i,w[i]);
            ans+=w[i];
        }
        else if(w[i] < 0)
        {
            addEdge(i,n+1,-w[i]);
        }
    }
    for(int i = 1; i <= m; ++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        addEdge(x,y,INF);
    }
    ans -= dinic(0,n+1);
    cout<<bfs_res(0)<<" "<<ans<<endl;
    return 0;
}



