#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>

using namespace std;

const int N = 1000010;
bool isPrime[N];


void init()
{
	int t = (int)sqrt(N);  
    for (int i=2; i<=t; ++i)  
        if (!isPrime[i])  
            for (int j=i*i; j<N; j+=i)  
                isPrime[j] = true;
}

int check(int n)
{
	char ch[25];
	sprintf(ch,"%d",n);
	string str = ch;
	int len = str.length();
	for(int i = 0; i < len; ++i)
	{
		string tmp;
		tmp += str.substr(i);
		tmp += str.substr(0,i);
		int n = atoi(tmp.c_str());
		if(isPrime[n])
			return 0;
	}
	return 1;
}

int main()
{
	init();
	int l,r,i,j,cnt;
	int f[N];
	f[0] = f[1] = 0;
	for(int i = 2; i < N; i++)
		if(check(i))
			f[i] = f[i-1] + 1;
		else
			f[i] = f[i-1];
	while(1)
	{
		cin>>l;
		if(l == -1) break;
		cin>>r;
		cnt = f[r] - f[l-1];
		if(cnt == 0)
			cout<<"No Circular Primes."<<endl;
		else if(cnt == 1)
			cout<<"1 Circular Prime."<<endl;
		else
			cout<<cnt<<" Circular Primes."<<endl;
	}
	return 0;
}