/*
ID: ziliuga1
LANG: C++11
TASK: ariprog
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

bool bisquare[250000] {0};
int num[250000];
int n,m;
int len=0;
bool none = false;
struct ariprog{
	int first;
	int sub;
}ans[10000];
int ansCount=0;

void init()
{
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);
	cin>>n>>m;
	for(int i = 0; i <= m; ++i)
		for(int j = 0; j <= m; ++j)
		{
			if(!bisquare[i*i+j*j])
				{
					num[len++] = i*i+j*j;
					bisquare[i*i+j*j] = 1;
				}
		}
}
void search(int x, int y)
{
	int count = 2;
	int sub = y - x;
	while(bisquare[y+sub])
	{
		y+=sub;
		++count;
	}
	if(count >= n)
	{
		ans[ansCount].first=x;
		ans[ansCount].sub=sub;
		ansCount++;
		none=1;
	}
}
bool cmp(ariprog &a, ariprog &b)
{
	if(a.sub == b.sub)
		return a.first < b.first;
	else
		return a.sub<b.sub;
}

int main()
{
	init();
	sort(num,num+len);
	for (int i = 0; i < len; ++i)
		for(int j = i+1 ; j < len; ++j)
			search(num[i],num[j]);
	if(!none) cout<<"NONE"<<endl;
	sort(ans,ans+ansCount,cmp);

	for(int i=0;i<ansCount;i++)
		cout<<ans[i].first<<" "<<ans[i].sub<<endl;

	return 0;
}

/*
A few things to remember. First, compile with c++11 using -std=c++11, this command is extremely useful when using some c++11 feature.
This solution also reviews how to do mutilple keyword sorting. In addition, it is a good solution to show how pre-calculation works in
brute-forece. The major problem I encounbter with when dealing with this problem is that memory indexing problem, it violates 
unaccessible memory with index(although I still do not know how.) The idea is that when doing competing, it is better to open a bigger array
*/
