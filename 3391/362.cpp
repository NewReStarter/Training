#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn=300;

int n,L,W,d;
int x[110], y[110];
int cap[maxn][maxn];
int f[maxn][maxn];
int q[maxn],qf,qb;
int pre[maxn];

int maxflow(int n, int s, int t)
{
    memset(f,0,sizeof(f));
    int flow = 0;
    while(1)
    {
        memset(pre,-1,sizeof(pre));
        qf = qb = 0;
        pre[q[qb++] = s] = -2;
        while(qb > qf && pre[t] == -1)
            for(int u = q[qf++], v = 0; v < n; v++)
                if(pre[v] == -1 && f[u][v] - f[v][u] < cap[u][v])
                    pre[q[qb++] = v] = u;
        if( pre[t] == -1 )
            break;
        int bot = 1<<30;
        for(int v = t, u = pre[v]; u >= 0; v = u, u = pre[v])
            bot = min(bot, cap[u][v] - f[u][v] + f[v][u]);
        for(int v = t, u = pre[v]; u >= 0; v = u, u = pre[v])
            f[u][v] += bot;
        flow += bot;
    }
    return flow;
}

bool near(int a, int b){
    int dx = x[a] - x[b];
    int dy = y[a] - y[b];
    return dx * dx + dy * dy <= 4 * d * d;
}

int main()
{
    int test = 0;
    while(cin>>L>>W>>n>>d && n)
    {
        memset(cap,0,sizeof(cap));
        for(int i = 0; i < n; ++i)
            cin>>x[i]>>y[i];

        int cnt =2*n+2;
        int src = 2*n;
        int sink = 2*n+1;
        for(int i = 0; i < n; ++i)
        {
            if(y[i]<= d) cap[src][2*i] = 1;
            if(y[i] >= W-d) cap[2*i+1][sink] = 1;
            cap[2*i][2*i+1] = 1;

            for(int j = 0; j < n; ++j)
                if(i != j && near(i,j))
                    cap[2*i+1][2*j] = 1;
        }
        cout<<"Case "<<++test<<": "<<maxflow(cnt,src,sink)<<endl;
    }
}


 
