#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 300;
const int INF = 0x3f3f3f3f;
int G[maxn][maxn],f[maxn][maxn];
int Prev[maxn];
int a[maxn];
int m,n;

void init()
{
	for(int i = 1; i<=n; ++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		G[0][i] = a;
		G[i][n+1] = b;
	}
	for(int i = 1; i <= m; ++i)
	{
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		G[a][b] = w;
		G[b][a] = w;
	}
}

int ek() {
    queue<int> q;
    n = n + 1;
    int ans = 0;
    memset(f, 0, sizeof(f));    
    while (1) {
        memset(Prev, 0, sizeof(Prev));
        memset(a, 0, sizeof(a));
        a[0] = INF;
        q.push(0);
        while (!q.empty()) { 
            int u = q.front(); q.pop(); 
            for (int v = 0; v <= n; v++) {
                if (!a[v] && G[u][v] > f[u][v]) { 
                    Prev[v] = u; 
                    q.push(v);  
                    a[v] = min(a[u], G[u][v] - f[u][v]); 
                }
            }
        }
        if (a[n] == 0) break; 
        ans += a[n]; 
        int u = n;
        while(u)
        { 
            f[Prev[u]][u] += a[n];   
            f[u][Prev[u]] -= a[n];
            u = Prev[u];  
        }

    }
    return ans;
}


int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		init();
		cout<<ek()<<endl;
	}
	return 0;
}