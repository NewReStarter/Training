//最长回文串
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>
using namespace std;
typedef long long ll;
typedef long double ld;
#define lson (i<<1)
#define rson ((i<<1)|1)
const int maxn = 5005;

int t1[maxn],t2[maxn],c[maxn];
bool cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b] &&r[l+a] == r[l+b];
}

void get_sa(int str[],int sa[],int Rank[],int height[],int n,int m)
{
    n++;
    int p,*x=t1,*y=t2;
    for(int i = 0; i < m; i++) c[i] = 0;
    for(int i = 0; i < n; i++) c[x[i] = str[i]]++;
    for(int i = 1; i < m; i++) c[i] += c[i-1];
    for(int i = n-1; i>=0; i--) sa[--c[x[i]]] = i;
    for(int j = 1; j <= n; j <<= 1)
    {
        p = 0;
        for(int i = n-j; i < n; i++) y[p++] = i;
        for(int i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i]-j;
        for(int i = 0; i < m; i++) c[i] = 0;
        for(int i = 0; i < n; i++) c[x[y[i]]]++ ;
        for(int i = 1; i < m; i++) c[i] += c[i-1];
        for(int i = n-1; i >= 0; i--)  sa[--c[x[y[i]]]] = y[i];

        swap(x,y);
        p = 1;
        x[sa[0]] = 0;
        for(int i = 1; i < n; i++)
            x[sa[i]] = cmp(y,sa[i-1],sa[i],j)? p-1:p++;
        if(p >= n) break;
        m = p;
    }
    int k = 0;
    n--;
    for(int i = 0; i <= n; i++)
        Rank[sa[i]] = i;
    for(int i = 0; i < n; i++)
    {
        if(k) k--;
        int j = sa[Rank[i]-1];
        while(str[i+k] == str[j+k]) k++;
        height[Rank[i]] = k;
    }
}


int mm[maxn];
int dp[20][maxn];
int Rank[maxn],height[maxn];
int sa[maxn],str[maxn];
char ts[maxn];

void ini_RMQ(int n)
{
    mm[0] = -1;
    for(int i = 1;i <= n;i++)
        mm[i] = (((i & (i-1)) == 0) ? mm[i-1]+1:mm[i-1]);

    for(int i =1;i <= n;i++)
        dp[0][i] = height[i];
    for(int i = 1;i <= mm[n];i++)
    {
        for(int j = 1;j+(1<<i)-1 <= n;j++)
        {
            int a = dp[i-1][j];
            int b = dp[i-1][j+(1<<(i-1))];
            dp[i][j] = min(a,b);
        }
    }
}

int askRMQ(int a,int b)
{
    int t = mm[b-a+1];
    b -= (1<<t)-1;
    return min(dp[t][a],dp[t][b]);
}


int fin(int a,int b)
{
    a = Rank[a],b = Rank[b];
    if(a > b) swap(a,b);
    return askRMQ(a+1,b);
}

int main()
{
    while(scanf("%s",ts) != EOF)
    {
        int len = strlen(ts);
        for(int i = 0;i < len;i++)
            str[i] = ts[i];
        str[len] = 1;
        for(int i = 0;i < len;i++)
            str[i+len+1] = ts[len-i-1];
        str[len*2+1] = 0;

        get_sa(str,sa,Rank,height,2*len+1,128);
        ini_RMQ(2*len+1);

        int ans = 0,pos;
        int tp;
        for(int i = 0;i < len;i++)
        {
            tp = fin(i,len*2+1-i);
            if(tp*2 > ans)
            {
                ans = tp*2;
                pos = i-tp;
            }
            tp = fin(i,len*2-i);
            if(tp*2-1 > ans)
            {
                ans = tp*2-1;
                pos = i-tp+1;
            }
        }
        ts[pos+ans] = 0;
        printf("%s\n",ts+pos);
    }
    return 0;
}
