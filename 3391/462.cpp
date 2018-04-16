#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

const int N =100000010;
bool notPrime[N];

void init()
{
	int t = (int)sqrt(N);  
    for (int i=2; i<=t; ++i)  
        if (!notPrime[i])  
            for (int j=i*i; j<N; j+=i)  
                notPrime[j] = 1;
    notPrime[1] = 1;
}

int main()
{
	init();
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n < 5)
			cout<<n<<" is not the sum of two primes!"<<endl;
		else if(n%2)
		{
			if(notPrime[n-2])
				cout<<n<<" is not the sum of two primes!"<<endl;
			else
				printf("%d is the sum of 2 and %d.\n",n,n-2);
		}
		else
		{
			bool flag = 1;
			for(int i = n/2-1; i>=2;--i)
				if(!notPrime[i] && !notPrime[n-i])
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