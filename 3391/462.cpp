#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN=20000;  
int prime[MAXN];//保存素数   
bool vis[MAXN];//初始化   

void Prime(int n)  
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
}  

bool isPrime(int x)
{
	if(x<4)
		return 1;
	if((x&1)==0)return 0;
	int i = 1;
	while(prime[i]*prime[i] <= x)
	{
		if(x % prime[i] == 0)
			return 0;
		i++;
	}
	return 1;
}

int getPrime(int x)
{
	int mid = x/2 - 1;
	if (!(mid&1))
		mid--;
	for (int i = mid; i > 1; i -= 2)
		if (isPrime(i) && isPrime(x-i))
			return i;
	return 0;
}

int main()
{
	Prime(12000);
	int n;
	//freopen("462.out","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		if(n <= 4 || n == 6)
			printf("%d is not the sum of two primes!\n",n);
		else if(n & 1)
			if (isPrime(n - 2))
				printf("%d is the sum of 2 and %d.\n", n,n - 2);
			else
				printf("%d is not the sum of two primes!\n", n);
		else
		{
			int res=getPrime(n);
			printf("%d is the sum of %d and %d.\n", n, res, n - res);
		}

	}
	return 0;
}
