#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include <algorithm>
using namespace std;

inline void read(int& x)
{
    char c = getchar(); x = 0;
    while(c < '0' || c > '9') c = getchar();
    while(c <= '9' && c >= '0') x = x*10+c-48, c = getchar();
}

const int MAXN = 1000100;  
int a[MAXN],dp[MAXN];
int n;
int i,j;

int lis()

{
    memset(dp, 0, sizeof(int)*n);
    int len = 1;
    dp[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        int pos = max(lower_bound(dp, dp + len, a[i]) - dp,upper_bound(dp, dp + len, a[i]) - dp );
        dp[pos] = a[i];
        len = max(len, pos + 1);
    }
    return len;
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(i = 0; i < n; i++)
		{
			read(a[i]);
		}
		cout<<lis()<<endl;
	}
	return 0;
}