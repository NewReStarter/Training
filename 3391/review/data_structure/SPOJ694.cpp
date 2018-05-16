// 不相同子串数
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

#define rep(i,n) for(int i = 0;i < n; i++)
using namespace std;
const int size  = 200000+5,INF = 1<<30;
int rk[size],sa[size],height[size],w[size],wa[size],res[size];
void getSa (int len,int up) {
    int *k = rk,*id = height,*r = res, *cnt = wa;
    rep(i,up) cnt[i] = 0;
    rep(i,len) cnt[k[i] = w[i]]++;
    rep(i,up) cnt[i+1] += cnt[i];
    for(int i = len - 1; i >= 0; i--) {
        sa[--cnt[k[i]]] = i;
    }
    int d = 1,p = 0;
    while(p < len){
        for(int i = len - d; i < len; i++) id[p++] = i;
        rep(i,len)    if(sa[i] >= d) id[p++] = sa[i] - d;
        rep(i,len) r[i] = k[id[i]];
        rep(i,up) cnt[i] = 0;
        rep(i,len) cnt[r[i]]++;
        rep(i,up) cnt[i+1] += cnt[i];
        for(int i = len - 1; i >= 0; i--) {
            sa[--cnt[r[i]]] = id[i];
        }
        swap(k,r);
        p = 0;
        k[sa[0]] = p++;
        rep(i,len-1) {
            if(sa[i]+d < len && sa[i+1]+d <len &&r[sa[i]] == r[sa[i+1]]&& r[sa[i]+d] == r[sa[i+1]+d])
                k[sa[i+1]] = p - 1;
            else k[sa[i+1]] = p++;
        }
        if(p >= len) return ;
        d *= 2,up = p, p = 0;
    }
}
void getHeight(int len) {
    rep(i,len) rk[sa[i]] = i;
    height[0] =  0;
    for(int i = 0,p = 0; i < len - 1; i++) {
        int j = sa[rk[i]-1];
        while(i+p < len&& j+p < len&& w[i+p] == w[j+p]) {
            p++;
        }
        height[rk[i]] = p;
        p = max(0,p - 1);
    }
}
int getSuffix(char s[]) {
    int len = strlen(s),up = 0;
    for(int i = 0; i < len; i++) {
        w[i] = s[i];
        up = max(up,w[i]);
    }
    w[len++] = 0;
    getSa(len,up+1);
    getHeight(len);
    return len;
}const int maxa = 100000*2+1;
char str[maxa];
int n;
int main()
{
	scanf("%d",&n);
	getchar();
    while(n--)
    {
        scanf("%s",str);
        int l = strlen(str);
        str[l] = 0;
        int ans = l * (l+1) / 2;
        getSuffix(str);
        for(int i = 1; i <= l; ++i)
            ans -= height[i];
        cout<<ans<<endl;
    }
    return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=50000+100;
struct SuffixArray
{
    char s[maxn];
    int sa[maxn],rank[maxn],height[maxn];
    int t1[maxn],t2[maxn],c[maxn],n;
    void build_sa(int m)
    {
        int i,*x=t1,*y=t2;
        for(i=0;i<m;i++) c[i]=0;
        for(i=0;i<n;i++) c[x[i]=s[i]]++;
        for(i=1;i<m;i++) c[i]+=c[i-1];
        for(i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
        for(int k=1;k<=n;k<<=1)
        {
            int p=0;
            for(i=n-k;i<n;i++) y[p++]=i;
            for(i=0;i<n;i++)if(sa[i]>=k) y[p++]=sa[i]-k;
            for(i=0;i<m;i++) c[i]=0;
            for(i=0;i<n;i++) c[x[y[i]]]++;
            for(i=1;i<m;i++) c[i]+=c[i-1];
            for(i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
            swap(x,y);
            p=1;x[sa[0]]=0;
            for(i=1;i<n;i++)
                x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
            if(p>=n) break;
            m=p;
        }
    }
    void build_height()
    {
        int i,j,k=0;
        for(i=0;i<n;i++) rank[sa[i]]=i;
        for(i=0;i<n;i++)
        {
            if(k) k--;
            j=sa[rank[i]-1];
            while(s[i+k] == s[j+k])k++;
            height[rank[i]]=k;
        }
    }
}sa;
int solve()
{
    int ans=0;
    for(int i=1;i<sa.n;i++)
        ans += sa.n-1-sa.sa[i]-sa.height[i];
    return ans;
}
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        scanf("%s",sa.s);
        sa.n=strlen(sa.s)+1;
        sa.s[sa.n-1]=0;
        sa.build_sa(300);
        sa.build_height();
        printf("%d\n",solve());
    }
    return 0;
}
