#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 500;
const int bound = 100;
const int INF = 0x3f3f3f3f;
int G[maxn][maxn],f[maxn][maxn];
int Prev[maxn];
int a[maxn];
int m,n;

void init()
{
	memset(G, 0, sizeof(G));
    memset(f, 0, sizeof(f));
    int cap;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &cap);  
        G[i][i+bound] = cap;
    }
    scanf("%d", &m);
    int a,b,c;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        G[a+bound][b] = c; // only one link?
    }
    int B,D;
    scanf("%d%d", &B, &D); 
    for (int i = 0; i < B; i++) { 
        scanf("%d", &a);    
        G[0][a] = INF;
    }
    for (int i = 0; i < D; i++) { 
        scanf("%d", &a);
        G[a+bound][n+bound+1] = INF;
    }
}

int ek() {
    queue<int> q;
    n = n + bound + 1;
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
	while(scanf("%d", &n) != EOF)
	{
		init();
		cout<<ek()<<endl;
	}
	return 0;
}