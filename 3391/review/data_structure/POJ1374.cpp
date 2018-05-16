//不可重叠最长重复子串
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

#define rep(i,n) for(int i = 0;i < n; i++)
using namespace std;
const int size  = 2000000+5,INF = 1<<30;
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
int getSuffix(int s[], int n) {
    int len = n,up = 0;
    for(int i = 0; i < len; i++) {
        w[i] = s[i];
        up = max(up,w[i]);
    }
    w[len++] = 0;
    getSa(len,up+1);
    getHeight(len);
    return len;
}const int maxa = 100000*2+1;
int str[maxa];
int a[maxa];

bool judge(int ans, int n)
{
    int Max = sa[0], Min = sa[0];
    for(int i = 0; i <= n; ++i)
    {
        if(height[i]>=ans)
        {
            Max = max(Max,sa[i]);
            Min = min(Min,sa[i]);
            if(Max - Min >= ans)
                return 1;
        }
        else
        {
            Min = Max = sa[i];
        }
    }
    return 0;
}

int main()
{
    int n;   
    while(scanf("%d",&n) && n)
    {
        for(int i = 0; i < n; ++i)
            cin>>a[i];
        for(int i = 0; i < n-1; ++i)
            str[i] = a[i+1]-a[i]+100;
        str[n-1] = 0;
        getSuffix(str,n-1);
        // for(int i = 0; i <= n-1; ++i)
        //     cout<<sa[i]<<" "<<height[i]<<endl;
        int l = 0, r = n-1;
        while(l<r)
        {
            int mid = (l+r)/2;
            if(judge(mid,n-1)) // mid 满足条件
                l = mid+1;
            else
                r = mid;
        }
        if(l < 5)
            printf("0\n");
        else
            printf("%d\n",l);

    }
    return 0;
}

