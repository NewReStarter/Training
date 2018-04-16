#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

#define rep(i,k,n) for(int i = k; i<=n; ++i)

const int MOD = 1000000007;
const int MAXN =  1000100;
int n,m;

int dp[MAXN];

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		dp[1] = 1;
		rep(i,2,n)
		{
			if(i%m == 0)
				dp[i] = (dp[i-1]+dp[i/m])%MOD;
			else
				dp[i] = dp[i-1];
		}
		cout<<dp[n]<<endl;
	}
}