// 每个字符串至少出现两次且不重叠的最长子串
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 111111
#define INF 0x3f3f3f3f
int t1[maxn],t2[maxn],c[maxn],sa[maxn],rankk[maxn],height[maxn];
bool cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int str[],int n,int m)
{
    n++;
    int i,j,p,*x=t1,*y=t2;
    for(i=0;i<m;i++)c[i]=0;
    for(i=0;i<n;i++)c[x[i]=str[i]]++;
    for(i=1;i<m;i++)c[i]+=c[i-1];
    for(i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
    for(j=1;j<=n;j<<=1)
    {
        p=0;
        for(i=n-j;i<n;i++)y[p++]=i;
        for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
        for(i=0;i<m;i++)c[i]=0;
        for(i=0;i<n;i++)c[x[y[i]]]++;
        for(i=1;i<m;i++)c[i]+=c[i-1];
        for(i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];
        swap(x,y);
        p=1;x[sa[0]]=0;
        for(i=1;i<n;i++)
        x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        if(p>=n)break;
        m=p;
    }
    int k=0;
    n--;
    for(i=0;i<=n;i++)rankk[sa[i]]=i;
        for(i=0;i<n;i++)
        {
            if(k)k--;
            j=sa[rankk[i]-1];
            while(str[i+k]==str[j+k])k++;
            height[rankk[i]]=k;
        }
}
int n,res,a[maxn],id[maxn];
int vis[11],Max[11],Min[11];
void init()
{
    for(int i=0;i<=n;i++)
    {
        vis[i]=Max[i]=0;
        Min[i]=INF;
    }
}
char s[maxn];
int check(int k)
{
    int cnt=0;
    for(int i=1;i<=res;i++)
    {
        if(height[i]<k)
        {
            init();
            Min[id[sa[i]]]=Max[id[sa[i]]]=sa[i];
            continue;
        }
        Min[id[sa[i-1]]]=min(Min[id[sa[i-1]]],sa[i-1]);
        Max[id[sa[i-1]]]=max(Max[id[sa[i-1]]],sa[i-1]);
        Min[id[sa[i]]]=min(Min[id[sa[i]]],sa[i]);
        Max[id[sa[i]]]=max(Max[id[sa[i]]],sa[i]);
        int flag=1;
        for(int j=0;j<n;j++)
            if(Max[j]-Min[j]<k)
            {
                flag=0;
                break;
            }
        if(flag)return 1;
    }
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        res=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            int len=strlen(s);
            for(int j=0;j<len;j++)
                a[res]=s[j],id[res++]=i;
            a[res]='#'+i;
            id[res++]='#'+i;
        }
        a[res]=0;
        da(a,res,200);
        int l=1,r=res,flag=0;
        while(l<=r) 
        {
            int mid=(l+r)>>1;
            if(check(mid))l=mid+1;
            else r=mid-1;
        }
        printf("%d\n",l-1);
    }
    return 0;
}