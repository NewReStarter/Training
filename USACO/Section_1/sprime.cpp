/*
ID: ziliuga1
LANG: C++11
TASK: sprime
*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
inline bool isPrime(int x)
{
	for(int i=2;i<=sqrt(x);i++)
		if(x!=2 && x%i==0) return false;
	return true;
}
inline int digit(int x)
{
	int d = 1;
	while(x/10>0)
	{
		x/=10;
		d++;
	}
	return d;
}
int len;
void search(int x);
int main()
{
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	cin>>len;
	search(2);
	search(3);
	search(5);
	search(7);
	return 0;
}
void search(int x)
{

	if(digit(x)==len)
		{
			if(isPrime(x))
				cout<<x<<endl;
			return ;
		}
	for(int i=1; i<=9; i=i+2)
	{
		if(isPrime(x*10+i))
			search(x*10+i);
	}
	return ;
}
/*
easy dfs.
*/
