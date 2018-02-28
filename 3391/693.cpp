#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int hanoi[] {0,2,8,26,80,242,728,2186,6560,19682,59048};

// int hanoi(int n)
// {
// 	if(n==1) return 2;
// 	else return 3*hanoi(n-1)+2;
// }

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",hanoi[n]);
	}
	return 0;
}