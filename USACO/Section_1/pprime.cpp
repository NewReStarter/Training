/*
ID: ziliuga1
LANG: C++11
TASK: pprime
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;


bool isPrime(int);
void produce(int,int);

int main()
{
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	int a,b;
	cin>>a>>b;
	produce(a,b);
	return 0;
}

bool isPrime(int x)
{
	int i;
	for(i=2; i<=sqrt(x); i++)
		if(x%i==0)
			return false;
	
	return true;
}

void produce(int a,int b)
{
	//1 digit
	for(int d1 = 1; d1<=9; d1++)
		if(d1>=a && d1<=b && isPrime(d1)) cout<<d1<<endl;

	if(11>=a && 11<=b)
		cout<<11<<endl;
	//3 digit
	for(int d1 = 1; d1<=9; d1++)
		for(int d2=0; d2<=9; d2++)
		{
			int tmp = d1*100+d2*10+d1;
			if(tmp>=a && tmp<=b && isPrime(tmp)) cout<<tmp<<endl;
		}
	//5 digits
	for(int d1 = 1; d1<=9; d1++)
		for(int d2 = 0; d2<=9; d2++)
			for(int d3 = 0; d3<=9; d3++)
			{
				int tmp = d1*10000+d2*1000+d3*100+d2*10+d1;
				if(tmp>=a && tmp<=b && isPrime(tmp)) cout<<tmp<<endl;
			}
	//7 digits
	for(int d1 = 1; d1<=9; d1++)
		for(int d2 = 0; d2<=9; d2++)
			for(int d3 = 0; d3<=9; d3++)
				for(int d4 = 0; d4<=9; d4++)
				{
					int tmp = d1*1000000+d2*100000+d3*10000+d4*1000+d3*100+d2*10+d1;
					if(tmp>=a && tmp<=b && isPrime(tmp)) cout<<tmp<<endl;
				}
}