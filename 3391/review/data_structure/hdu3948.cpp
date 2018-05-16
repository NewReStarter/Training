//给你一个字符串，问其中不同回文子串的个数
#include<stdio.h>
#include<string.h>

#define maxn 400010
int wa[maxn],wb[maxn],wv[maxn],ws[maxn];
int cmp(int *r,int a,int b,int l)
{
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r,int *sa,int n,int m)
{
     int i,j,p,*x=wa,*y=wb,*t;
     for(i=0;i<m;i++) ws[i]=0;
     for(i=0;i<n;i++) ws[x[i]=r[i]]++;
     for(i=1;i<m;i++) ws[i]+=ws[i-1];
     for(i=n-1;i>=0;i--) sa[--ws[x[i]]]=i;
     for(j=1,p=1;p<n;j*=2,m=p)
     {
       for(p=0,i=n-j;i<n;i++) y[p++]=i;
       for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
       for(i=0;i<n;i++) wv[i]=x[y[i]];
       for(i=0;i<m;i++) ws[i]=0;
       for(i=0;i<n;i++) ws[wv[i]]++;
       for(i=1;i<m;i++) ws[i]+=ws[i-1];
       for(i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];
       for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
       x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
     }
     return;
}
int rank[maxn],height[maxn];
void calheight(int *r,int *sa,int n)
{
     int i,j,k=0;
     for(i=1;i<=n;i++) rank[sa[i]]=i;
     for(i=0;i<n;height[rank[i++]]=k)
     for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
     return;
}
int RMQ[maxn];
int mm[maxn];
int best[20][maxn];
void initRMQ(int n)
{
     int i,j,a,b;
     for(mm[0]=-1,i=1;i<=n;i++)
     mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
     for(i=1;i<=n;i++) best[0][i]=i;
     for(i=1;i<=mm[n];i++)
     for(j=1;j<=n+1-(1<<i);j++)
     {
       a=best[i-1][j];
       b=best[i-1][j+(1<<(i-1))];
       if(RMQ[a]<RMQ[b]) best[i][j]=a;
       else best[i][j]=b;
     }
     return;
}
int askRMQ(int a,int b)
{
    int t;
    t=mm[b-a+1];b-=(1<<t)-1;
    a=best[t][a];b=best[t][b];
    return RMQ[a]<RMQ[b]?a:b;
}
int lcp(int a,int b) //最长公共前缀
{
    int t;
    a=rank[a];b=rank[b];
    if(a>b) {t=a;a=b;b=t;}
    return(height[askRMQ(a+1,b)]);
}
int _min(int a, int b)
{
	return a<b?a:b;
}

int _max(int a, int b)
{
	return a>b?a:b;
}

struct node
{
	int l, r, mid, max;
}rt[maxn*4];
int mxx;
void build(int l, int r, int p)
{
	rt[p].l = l;
	rt[p].r = r;
	rt[p].mid = (l+r)>>1;
	if(l==r)
	{
		rt[p].max = l-1;
		return;
	}
	build(l, rt[p].mid, p*2);
	build(rt[p].mid+1, r, p*2+1);
	rt[p].max = -1;
}
void down(int p)
{
	if(rt[p].max==-1)
		return;
	if(rt[p*2].max<rt[p].max)
		rt[p*2].max = rt[p].max;
	if(rt[p*2+1].max<rt[p].max)
		rt[p*2+1].max = rt[p].max;
	rt[p].max = -1;
}
void update(int l, int r, int p)
{
	if(rt[p].l==l && rt[p].r==r)
	{
		if(rt[p].max<mxx)
			rt[p].max = mxx;
		return;
	}
	down(p);
	if(r<=rt[p].mid)
		update(l, r, p*2);
	else if(l>rt[p].mid)
		update(l, r, p*2+1);
	else
	{
		update(l, rt[p].mid, p*2);
		update(rt[p].mid+1, r, p*2+1);
	}
}

int query(int l, int r, int p)
{
	if(rt[p].l==l && rt[p].r==r)
		return rt[p].max;
	down(p);
	if(r<=rt[p].mid)
		return query(l, r, p*2);
	else
		return query(l, r, p*2+1);
}

int flag[maxn], ttemp, tmp, cnt;
//求两串最长公共字串示例。。。
int len1, len2, n, mx;
char s1[maxn], s2[maxn];
int sa[maxn], a[maxn];
int main()
{
	int i, j, cas,  cas1=1;
	scanf("%d", &cas);
	while(cas--)
	{
		scanf("%s", s2);
		len2 = strlen(s2);
		for(i=0; i<len2; i++) //将原串数组做一定操作避免后面的奇偶判定
		{
			s1[i*2] = 'z'+1;
			s1[i*2+1] = s2[i];
		}
		s1[i*2] = 'z'+1;
		s1[i*2+1] = 0;
		len1 = strlen(s1);
		for(i=0; i<len1; i++)
			s2[i] = s1[len1-1-i];
		len2 = len1;
		n = len1+len2+1;
		for(i=0; i<len1; i++)
			a[i] = s1[i] - 'a' + 1;
		a[len1] = 100;
		for(i=0; i<len2; i++)
			a[i+len1+1] = s2[i] - 'a' + 1;
		a[len1+len2+1] = 0;   
		
		da(a, sa, n+1, 200);  
		calheight(a, sa, n); 
		
		for(i=0; i<=n; i++)
			RMQ[i] = height[i];
		initRMQ(n);

		mx = 0;
		cnt = 0;
		for(i=1; i<=n; i++) //标记某个位置是否被访问。。
			flag[i] = 0;
		for(i=1; i<n; i++)
		{
			cnt = _min(cnt, height[i]);
			if(flag[n-1-sa[i]]) //表示该位置的对应位置已经出现了。。
			{
				j = lcp(sa[i], n-1-sa[i]);
				if(j>cnt)
				{
					mx += (j-cnt)/2;
					cnt = j;
				}
			}
			else
				flag[sa[i]] = 1;
		}
		printf("Case #%d: %d\n", cas1++,  mx);
	}
	return 0;
}