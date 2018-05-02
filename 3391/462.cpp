#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<bitset>
#include<vector>
using namespace std;

const int maxn = 100000001;
int bitsieve[(maxn>>5)+3];
inline bool is_composite(int i)
{
	int x = i>>5;
	int bit = i-(x<<5);
	return (bitsieve[x] & (1<<bit));
}

void bitsieve_mark(int i)
{
	int x = i>>5;
	int bit = x-(i<<5);
	bitsieve[x] = bitsieve[x] | (1<<bit);
}

void bitsieve_call()
{
	int smaxn = sqrt(maxn)+1;
	for(int i = 4; i < maxn; i+=2)
		bitsieve_mark(i);
	for(int i = 3; i < smaxn; ++i)
	{
		if(is_composite(i)) continue;
		for(int j = i*i, k=i+i; j < maxn; j+=k)
			bitsieve_mark(j);
	}
}

bool isPrime(int x)
{
	if(x<2) return 0;
	return !is_composite(x);
}

int main()
{
	int n;
	bitsieve_call();
	while(scanf("%d",&n)!=EOF)
	{
		if(n < 5)
			cout<<n<<" is not the sum of two primes!"<<endl;
		else if(n%2)
		{
			if(!isPrime(n-2))
				cout<<n<<" is not the sum of two primes!"<<endl;
			else
				printf("%d is the sum of 2 and %d.\n",n,n-2);
		}
		else
		{
			bool flag = 1;
			for(int i = n/2-1; i>=2;--i)
				if(isPrime(i) && isPrime(n-i))
				{
					printf("%d is the sum of %d and %d.\n",n,i,n-i);
					flag = 0;
					break;
				}
			if(flag)
				cout<<n<<" is not the sum of two primes!"<<endl;
		}
	}

	return 0;
}