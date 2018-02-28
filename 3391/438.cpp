#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int t;
	while(n--)
	{
		scanf("%d",&t);
		if(t<=2) printf("0\n");
		else printf("%d\n",t-2);
	}
	return 0;	
}

