//查找字典序第k小的子串
/*
 * Author: Gatevin
 * Created Time:  2015/5/4 15:22:39
 * File Name: Rin_Tohsaka.cpp
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
#include<iomanip>
using namespace std;
const double eps(1e-8);
typedef long long lint;
#define foreach(e, x) for(__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
#define SHOW_MEMORY(x) cout<<sizeof(x)/(1024*1024.)<<"MB"<<endl

#define rank rankrankrank

#define maxn 100010

int wa[maxn], wb[maxn], wv[maxn], Ws[maxn];

int cmp(int *r, int a, int b, int l)
{
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void da(int *r, int *sa, int n, int m)
{
    int *x = wa, *y = wb, *t, i, j, p;
    for(i = 0; i < m; i++) Ws[i] = 0;
    for(i = 0; i < n; i++) Ws[x[i] = r[i]]++;
    for(i = 1; i < m; i++) Ws[i] += Ws[i - 1];
    for(i = n - 1; i >= 0; i--) sa[--Ws[x[i]]] = i;
    for(j = 1, p = 1; p < n; j <<= 1, m = p)
    {
        for(p = 0, i = n - j; i < n; i++) y[p++] = i;
        for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
        for(i = 0; i < n; i++) wv[i] = x[y[i]];
        for(i = 0; i < m; i++) Ws[i] = 0;
        for(i = 0; i < n; i++) Ws[wv[i]]++;
        for(i = 1; i < m; i++) Ws[i] += Ws[i - 1];
        for(i = n - 1; i >= 0; i--) sa[--Ws[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
    }
    return;
}

int rank[maxn], height[maxn];
void calheight(int *r, int *sa, int n)
{
    int i, j, k = 0;
    for(i = 1; i <= n; i++) rank[sa[i]] = i;
    for(i = 0; i < n; height[rank[i++]] = k)
        for(k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
    return;
}

char in[maxn];
int s[maxn], sa[maxn];
lint cnt[maxn];
lint v, l, r, k;

void init(int len)
{
    cnt[0] = 0;
    for(int i = 1; i <= len; i++)
        cnt[i] = cnt[i - 1] + (len - sa[i]) - height[i];
    return;
}


void solve(int len)//找出第k大的位置
{
    if(k > cnt[len])
    {
        l = r = 0;
        return;
    }
    int L = 0, R = len, mid, res;
    while(L <= R)
    {
        mid = (L + R) >> 1;
        if(cnt[mid] < k)
        {
            res = mid;
            L = mid + 1;
        }
        else R = mid - 1;
    }
    int ad = k - cnt[res];
    int LEN = ad + height[res + 1];//这个子串的长度
    l = sa[res + 1];
    res += 2;
    while(height[res] >= LEN)//向后找使得l最小
        l = min(l, (lint)sa[res]), res++;
    r = l + LEN - 1;
    l++, r++;
}

int main()
{
    while(scanf("%s", in) != EOF)
    {
        int len = strlen(in);
        for(int i = 0; i < len; i++)
            s[i] = in[i] - 'a' + 1;
        s[len] = 0;
        da(s, sa, len + 1, 28);
        calheight(s, sa, len);
        init(len);
        int Q;
        scanf("%d", &Q);
        l = r = 0;
        while(Q--)
        {
            scanf("%I64d", &v);
            k = (l^r^v) + 1;
            solve(len);
            printf("%I64d %I64d\n", l, r);
        }
    }
    return 0;
}
