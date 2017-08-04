/*
ID: ziliuga1
LANG: C++11
TASK: sort3
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int ans=0;
int a[1000];
int b[1000];
bool cmp(const int& a, const int& b){return a<b;}
int main()
{
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		{
			cin>>a[i];
			b[i]=a[i];
		}
	sort(b,b+n);
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[i])
			for(int j=i;j<n;j++)
			{
				if(a[i]==b[j] && a[j]==b[i]) 
				{
					swap(a[i],a[j]);
					ans++;
					break;
				}
			}
	}
	for(int i=0;i<n;i++)
	{
		if(b[i]!=1)
			break;
		if(a[i]!=b[i])
			ans+=2;

	}
	cout<<ans<<endl;
	return 0;


}
/*
如果两数位置都错了，并且交换后都在正确的位置，这一次交换肯定是必然的 跑一遍 把所有的符合上述条件的数交换回来 每次交换ANS++；
剩下的就是3个数的位置都是错的，也可以通过两次交换达到正确位置 每次交换ans+=2； （其实可以不用交换，就检查一下在1的位置上有多少个不是1的，乘2即可）
*/
