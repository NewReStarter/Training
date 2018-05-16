//翻转
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N=800010;
int n,rank[N],sa[N],h[N],tmp[N],cnt[N],ans; int s[N]; 
void suffixarray(int n,int m){
    int i,j,k;n++;
    for(i=0;i<2*n+5;i++)rank[i]=sa[i]=h[i]=tmp[i]=0;
    for(i=0;i<m;i++)cnt[i]=0;
    for(i=0;i<n;i++)cnt[rank[i]=s[i]]++;
    for(i=1;i<m;i++)cnt[i]+=cnt[i-1];
    for(i=0;i<n;i++)sa[--cnt[rank[i]]]=i;
    for(k=1;k<=n;k<<=1){
        for(i=0;i<n;i++){
            j=sa[i]-k;
            if(j<0)j+=n;
            tmp[cnt[rank[j]]++]=j;
        }sa[tmp[cnt[0]=0]]=j=0;
        for(i=1;i<n;i++){
            if(rank[tmp[i]]!=rank[tmp[i-1]]||rank[tmp[i]+k]!=rank[tmp[i-1]+k])cnt[++j]=i;
            sa[tmp[i]]=j;
        }memcpy(rank,sa,n*sizeof(int));
        memcpy(sa,tmp,n*sizeof(int));
        if(j>=n-1)break;
    }for(j=rank[h[i=k=0]=0];i<n-1;i++,k++)
    while(~k&&s[i]!=s[sa[j-1]+k])h[j]=k--,j=rank[sa[j]+1];
}
int disc[N];
int remark(int x){
      int l=1,r=n;
      while(l<=r){
            int mid=(l+r)>>1;
            if(disc[mid]<x)l=mid+1;
            else if(disc[mid]==x)return mid;
            else r=mid-1;
      }
}
int a[N],p1,p2;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",a+i),disc[i+1]=a[i];
    sort(disc+1,disc+n+1);
    for(int i=0;i<n;i++)a[i]=remark(a[i]);
    reverse_copy(a,a+n,s);
    suffixarray(n,n+1);
    for(int i=0;i<=n;i++){p1=n-sa[i];if(p1>=1&&n-p1>=2)break;}
    int m=n-p1;
    reverse_copy(a+p1,a+n,s);
    reverse_copy(a+p1,a+n,s+m);
    suffixarray(m<<1,n+1);
    for(int i=0;i<=2*m;i++){p2=p1+m-sa[i];if(p2>p1&&n>p2)break;}
    reverse(a,a+p1);reverse(a+p1,a+p2);reverse(a+p2,a+n);
    for(int i=0;i<n;i++)printf("%d\n",disc[a[i]]);
    return 0;
}