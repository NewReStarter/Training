//所有字符串的最长公共子串。

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
#define MAXN 888888
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
char s[2222];
int m, n;
int id[MAXN];
int vis[4005];
char res[2222];
bool check(int mid)
{
    int flag = 0, tot = 1, bg;
    memset(vis, -1, sizeof(vis));
    for(int i = 1; i <= n; i++)
    {
        int t = id[sa[i]];
        if(t == 0)
        {
            flag++;
            tot = 1;
            continue;
        }
        if(height[i] < mid)
        {
            vis[t] = ++flag;
            tot = 1;
            bg = sa[i];
        }
        else
        {
            if(vis[t] != flag) tot++;
            vis[t] = flag;
        }
        if(tot >= m)
        {
            //printf("%d\n", tot);
            for(int j = 0; j < mid; j++) res[j] = (char)r[bg + j];
            res[mid] = '\0';
            return 1;
        }
    }
    return 0;
}
int main()
{
    while(scanf("%d", &m) != EOF && m)
    {
        int op = 130;
        n = 0;
        memset(id, 0, sizeof(id));
        for(int i = 1; i <= m; i++)
        {
            scanf("%s", s);
            int len = strlen(s);
            for(int j = 0; j < len; j++)
            {
                r[n] = s[j];
                id[n++] = i;
            }
            r[n++] = op++;
        }
        n--;
        r[n] = 0;
        da(r, sa, n + 1, op + 1);
        calheight(r, sa, n);
        int low = 0, high = n, ans = 0;
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
        if(ans) printf("%s\n", res);
        else puts("IDENTITY LOST");
    }
    return 0;
}