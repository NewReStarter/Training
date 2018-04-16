#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; ++i)

int m,n;
int main()
{
	while(scanf("%d%d",&m,&n) && m && n)
	{
		bool flag = 0;
		rep(i,m)
		{
			rep(j,n)
			{
				int tmp;
				scanf("%d",&tmp);
				if(tmp)
				{
					if(i==0||j==0||i==m-1||j==n-1)
						flag = 1;
				}
			}
		}
		if(flag) printf("2\n");
		else
			printf("4\n");
	}
}