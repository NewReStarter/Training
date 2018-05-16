//给出一个字符串，要求在其后面添加最少的字符数，使得其成为一个回文串。并输出这个回文串。
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=4000010;
int n,m,Rank[N],sa[N],h[N],tmp[N],cnt[N],ans;char s[N],t[N];
void suffixarray(int n,int m){
    int i,j,k;n++;
    for(i=0;i<2*n+5;i++)Rank[i]=sa[i]=h[i]=tmp[i]=0;
    for(i=0;i<m;i++)cnt[i]=0;
    for(i=0;i<n;i++)cnt[Rank[i]=s[i]]++;
    for(i=1;i<m;i++)cnt[i]+=cnt[i-1];
    for(i=0;i<n;i++)sa[--cnt[Rank[i]]]=i;
    for(k=1;k<=n;k<<=1){
        for(i=0;i<n;i++){
            j=sa[i]-k;
            if(j<0)j+=n;
            tmp[cnt[Rank[j]]++]=j;
        }sa[tmp[cnt[0]=0]]=j=0;
        for(i=1;i<n;i++){
            if(Rank[tmp[i]]!=Rank[tmp[i-1]]||Rank[tmp[i]+k]!=Rank[tmp[i-1]+k])cnt[++j]=i;
            sa[tmp[i]]=j;
        }memcpy(Rank,sa,n*sizeof(int));
        memcpy(sa,tmp,n*sizeof(int));
        if(j>=n-1)break;
    }for(j=Rank[h[i=k=0]=0];i<n-1;i++,k++)
    while(~k&&s[i]!=s[sa[j-1]+k])h[j]=k--,j=Rank[sa[j]+1];
}
int f[N][30],lg2[N];
void rmq_init(int n){  
    for(int i=2;i<=n;i++)lg2[i]=lg2[i/2]+1;
    for(int i=1;i<=n;i++)f[i][0]=h[i];
    for(int j=1;(1<<j)<=n;j++)  
    for(int i=1;i+(1<<j)-1<=n;i++)
        f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
} 
int rmq_min(int l,int r){
    if(l>r)swap(l,r);l++;
      int k=lg2[r-l+1];
      return min(f[l][k],f[r-(1<<k)+1][k]);
}
void init(){
    int i,j;
    for(i=0;t[i];i++)s[i]=t[i];s[n=i]='#';
    for(j=i-1,++i;j>=0;i++,j--)s[i]=t[j];
    s[m=i]=0;
}
int main(){
    while(~scanf("%s",t)){
        init();
        suffixarray(m,128);
        rmq_init(m);
        int ans=0,pos=m+1;
        for(int i=0;i<n;i++){
            int k=rmq_min(Rank[i],Rank[m-1-i]);
            if(2*k-1>ans&&i+k==n)ans=2*k-1,pos=i-k+1;
            k=rmq_min(Rank[i],Rank[m-i]);
            if(2*k>ans&&i+k==n)ans=2*k,pos=i-k;
        }for(int i=0;i<n;i++)printf("%c",s[i]);
        for(int i=pos-1;i>=0;i--)printf("%c",s[i]);
        puts("");
    }return 0;
}