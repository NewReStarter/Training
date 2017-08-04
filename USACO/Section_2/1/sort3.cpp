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
