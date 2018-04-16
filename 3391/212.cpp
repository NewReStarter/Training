#include<iostream>
#include<cstdio>
using namespace std;

typedef unsigned long long ull;

ull fastmod(ull a, ull n, ull m)
{
	ull ans = 1;
	a %= m;
	while(n)
	{
		if(n % 2 == 1)
			ans = (ans*a) % m;
		n = n/2;
		a = (a*a) % m;
	}
	return ans;
}

int main()
{
	ull b,p,m;
	while(scanf("%lld%lld%lld",&b,&p,&m)!=EOF)
	{
		cout<<fastmod(b,p,m)<<endl;
	}
	return 0;
}