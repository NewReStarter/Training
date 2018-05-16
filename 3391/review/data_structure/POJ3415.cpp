//长度不小于k 的公共子串的个数
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#define MAXN 200005
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
char s1[MAXN], s2[MAXN];
int k;
int st[MAXN][2];
int main()
{
    while(scanf("%d", &k) != EOF && k)
    {
        getchar();
        gets(s1);
        gets(s2);
        int len = strlen(s1);
        strcat(s1, "$");
        strcat(s1, s2);
        int n = strlen(s1), m = 0;
        for(int i = 0; i < n; i++)
        {
            m = max(m, (int)s1[i]);
            r[i] = s1[i];
        }
        r[n] = 0;
        da(r, sa, n + 1, m + 1);
        calheight(r, sa, n);
        int top = 0;
        long long tot = 0;
        long long sum = 0;
        for(int i = 2; i <= n; i++)
        {
            if(height[i] < k) top = tot = 0;
            else
            {
                int cnt = 0;
                if(sa[i - 1] < len) cnt++, tot += height[i] - k + 1;
                while(top && height[i] <= st[top][0])
                {
                    tot -= st[top][1] * (st[top][0] - height[i]);
                    cnt += st[top][1];
                    top--;
                }
                st[++top][0] = height[i];
                st[top][1] = cnt;
                if(sa[i] > len) sum += tot;
            }
        }
        top = tot = 0;
        for(int i = 2; i <= n; i++)
        {
            if(height[i] < k) top = tot = 0;
            else
            {
                int cnt = 0;
                if(sa[i - 1] > len) cnt++, tot += height[i] - k + 1;
                while(top && height[i] <= st[top][0])
                {
                    tot -= st[top][1] * (st[top][0] - height[i]);
                    cnt += st[top][1];
                    top--;
                }
                st[++top][0] = height[i];
                st[top][1] = cnt;
                if(sa[i] < len) sum += tot;
            }
        }
        printf("%I64d\n", sum);
    }
    return 0;
}