//重复次数最多的连续重复子串
/*
 * POJ 3693 Maximum repetition substring
 * 先穷举长度L，然后求长度为L的子串最多能连续出现多少次
 * 既然长度为L的串重复出现，那么str[0],str[l],str[2*l]……中肯定有两个连续的出现在字符串中。
那么就枚举连续的两个，然后从这两个字符前后匹配，看最多能匹配多远。
即以str[i*l],str[i*l+l]前后匹配，这里是通过查询suffix(i*l),suffix(i*l+l)的最长公共前缀
通过rank值能找到i*l,与i*l+l的排名，我们要查询的是这段区间的height的最小值，通过RMQ预处理
达到查询为0(1)的复杂度，
 设LCP长度为M, 则答案显然为M / L + 1, 但这不一定是最好的, 因为答案的首尾不一定再我们枚举的位置上. 我的解决方法是, 我们考虑M % L的值的意义, 我们可以认为是后面多了M % L个字符, 但是我们更可以想成前面少了(L - M % L)个字符! 所以我们求后缀j * L - (L - M % L)与后缀(j + 1) * L - (L - M % L)的最长公共前缀。
即把之前的区间前缀L-M%L即可。
然后把可能取到最大值的长度L保存，由于 题目要求字典序最小，通过sa数组进行枚举，取到的第一组，肯定是字典序最小的。
 */

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAXN=100010;

/*
 * 倍增算法求后缀数组
 */
int sa[MAXN];
int t1[MAXN],t2[MAXN],c[MAXN];
int rank[MAXN],height[MAXN];
void build_sa(int s[],int n,int m)
{
    int i,j,p,*x=t1,*y=t2;
    for(i=0;i<m;i++)c[i]=0;
    for(i=0;i<n;i++)c[x[i]=s[i]]++;
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
            x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+j]==y[sa[i]+j]?p-1:p++;
        if(p>=n)break;
        m=p;
    }
}
void getHeight(int s[],int n)
{
    int i,j,k=0;
    for(i=0;i<=n;i++)rank[sa[i]]=i;
    for(i=0;i<n;i++)
    {
        if(k)k--;
        j=sa[rank[i]-1];
        while(s[i+k]==s[j+k])k++;
        height[rank[i]]=k;
    }
}
int mm[MAXN];
int best[20][MAXN];
void initRMQ(int n)
{
    mm[0]=-1;
    for(int i=1;i<=n;i++)
        mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
    for(int i=1;i<=n;i++)best[0][i]=i;
    for(int i=1;i<=mm[n];i++)
        for(int j=1;j+(1<<i)-1<=n;j++)
        {
            int a=best[i-1][j];
            int b=best[i-1][j+(1<<(i-1))];
            if(height[a]<height[b])best[i][j]=a;
            else best[i][j]=b;
        }
}
int askRMQ(int a,int b)
{
    int t;
    t=mm[b-a+1];
    b-=(1<<t)-1;
    a=best[t][a];b=best[t][b];
    return height[a]<height[b]?a:b;
}
int lcp(int a,int b)
{
    a=rank[a];b=rank[b];
    if(a>b)swap(a,b);
    return height[askRMQ(a+1,b)];
}
char str[MAXN];
int r[MAXN];
int a[MAXN];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int iCase=0;
    while(scanf("%s",str)==1)
    {
        if(strcmp(str,"#")==0)break;
        iCase++;
        int n=strlen(str);
        for(int i=0;i<=n;i++)r[i]=str[i];
        build_sa(r,n+1,128);
        getHeight(r,n);
        initRMQ(n);
        int cnt=0,mmax=0;
        for(int l=1;l<n;l++)
        {
            for(int i=0;i+l<n;i+=l)
            {
                int t1=lcp(i,i+l);
                int step=t1/l+1;
                int  k=i-(l-t1%l);
                if(k>=0&&t1%l)
                {
                    if(lcp(k,k+l)>=t1)step++;
                }
                if(step>mmax)
                {
                    mmax=step;
                    cnt=0;
                    a[cnt++]=l;
                }
                else if(step==mmax)
                    a[cnt++]=l;
            }
        }
        int len=-1,st;
        for(int i=1;i<=n&&len==-1;i++)
        {
            for(int j=0;j<cnt;j++)
            {
                int l=a[j];
                if(lcp(sa[i],sa[i]+l)>=(mmax-1)*l)
                {
                    len=l;
                    st=sa[i];
                    break;
                }
            }
        }
        str[st+len*mmax]=0;
        printf("Case %d: %s\n",iCase,str+st);
    }
    return 0;
}