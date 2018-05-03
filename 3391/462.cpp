#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN=10005;  
int prime[MAXN];  
bool vis[MAXN];
int size;  

int Prime(int n)  
{  
    int cnt=0;  
    memset(vis,0,sizeof(vis));  
    for(int i=2;i<n;i++)  
    {  
        if(!vis[i])  
        prime[cnt++]=i;  
        for(int j=0;j<cnt&&i*prime[j]<n;j++)  
        {  
            vis[i*prime[j]]=1;  
            if(i%prime[j]==0)//关键   
            break;  
        }  
    }  
    return cnt;//返回小于n的素数的个数   
}  

bool isPrime(int x)
{
	if(x<=10000)
	{
		if(!vis[x])
			return 1;
		return 0;
	}
	else
	{
		for(int i = 0; i < size; ++i)
			if(x % prime[i] == 0)
				return 0;
		return 1;
	}
}

int main()
{
	size = Prime(MAXN);
	int n;
	freopen("462.out","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		if(n&1)
		{
			if(n==1)
			{
				printf("%d is not the sum of two primes!\n",n);
				continue;
			}
			if(isPrime(n-2) && n-2 != 1)
			{
				printf("%d is the sum of %d and %d.\n",n,2,n-2);
				continue;
			}
			else
			{
				printf("%d is not the sum of two primes!\n",n);
				continue;
			}
		}
		bool flag = 1;
		for(int i = n/2; i>= 2 ;--i)
		{
			if(isPrime(i) && isPrime(n-i) && i != n-i)
			{
				printf("%d is the sum of %d and %d.\n",n,i,n-i);
				flag = 0;
				break;
			}
		}
		if(flag)
			printf("%d is not the sum of two primes!\n",n);
	}
	return 0;
}