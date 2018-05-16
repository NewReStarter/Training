// 不小于k 个字符串中的最长子串
// 求多个字符串的最长公共子串。
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <sstream>
#include <queue>
#include <vector>
#define MAXN 211111
#define MAXM 211111
#define INF 500000001
using namespace std;
int r[MAXN];
int wa[MAXN], wb[MAXN], wv[MAXN], tmp[MAXN];
int sa[MAXN]; //index range 1~n value range 0~n-1
int cmp(int *r, int a, int b, int l)
{
    return r[a] == r[b] && r[a + l] == r[b + l];
}
void da(int *r, int *sa, int n, int m)
{
    int i, j, p, *x = wa, *y = wb, *ws = tmp;
    for (i = 0; i < m; i++) ws[i] = 0;
    for (i = 0; i < n; i++) ws[x[i] = r[i]]++;
    for (i = 1; i < m; i++) ws[i] += ws[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--ws[x[i]]] = i;
    for (j = 1, p = 1; p < n; j *= 2, m = p)
    {
        for (p = 0, i = n - j; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++)
            if (sa[i] >= j) y[p++] = sa[i] - j;
        for (i = 0; i < n; i++) wv[i] = x[y[i]];
        for (i = 0; i < m; i++) ws[i] = 0;
        for (i = 0; i < n; i++) ws[wv[i]]++;
        for (i = 1; i < m; i++) ws[i] += ws[i - 1];
        for (i = n - 1; i >= 0; i--) sa[--ws[wv[i]]] = y[i];
        for (swap(x, y), p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
    }
}
int rank[MAXN]; //index range 0~n-1 value range 1~n
int height[MAXN]; //index from 1   (height[1] = 0)
void calheight(int *r, int *sa, int n)
{
    int i, j, k = 0;
    for (i = 1; i <= n; ++i) rank[sa[i]] = i;
    for (i = 0; i < n; height[rank[i++]] = k)
        for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; ++k);
    return;
}
int m;
char s[MAXN];
char ts[1111];
int id[MAXN], n;
int vis[1111];
bool check(int mid)
{
    int flag = 0, cnt = 0;
    memset(vis, -1, sizeof(vis));
    for(int i = 1; i <= n; i++)
    {
        if(id[sa[i]] == -1)
        {
            flag++;
            cnt = 1;
            continue;
        }
        if(height[i] < mid)
        {
            cnt = 1;
            vis[id[sa[i]]] = ++flag;
        }
        else
        {
            if(vis[id[sa[i]]] != flag) cnt++;
            vis[id[sa[i]]] = flag;
        }
        if(cnt > m / 2) return true;
    }
    return false;
}
void getans(int x)
{
    int flag = 0, cnt = 0, bg, ok = 0;
    memset(vis, -1, sizeof(vis));
    for(int i = 1; i <= n; i++)
    {
        if(id[sa[i]] == -1)
        {
            flag++;
            cnt = 1;
            continue;
        }
        if(height[i] < x)
        {
            cnt = 1;
            vis[id[sa[i]]] = ++flag;
            ok = 0;
            bg = sa[i];
        }
        else
        {
            if(vis[id[sa[i]]] != flag) cnt++;
            vis[id[sa[i]]] = flag;
        }
        if(cnt > m / 2 && !ok)
        {
            ok = 1;
            for(int j = 0; j < x; j++) putchar(s[bg + j]);
            puts("");
        }
    }
}
int main()
{
    int cas = 0;
    while(scanf("%d", &m) != EOF && m)
    {
        if(cas++) puts("");
        scanf("%s", s);
        if(m == 1)
        {
            puts(s);
            continue;
        }
        int now = 130;
        for(int i = 1; i < m; i++)
        {
            scanf("%s", ts);
            strcat(s, "$");
            strcat(s, ts);
        }
        n = strlen(s);
        int cnt = 1;
        for(int i = 0; i < n; i++)
        {
            id[i] = cnt;
            r[i] = s[i];
            if(s[i] == '$') id[i] = -1, cnt++, r[i] = 130 + cnt;
        }
        r[n] = 0;

        da(r, sa, n + 1, 250);
        calheight(r, sa, n);
        int low = 0, high = n;
        int ans = 0;
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            if(check(mid))
            {
                ans = max(ans, mid);
                low = mid + 1;
            }
            else high = mid - 1;
        }
        if(ans)
            getans(ans);
        else puts("?");
    }
    return 0;
}
