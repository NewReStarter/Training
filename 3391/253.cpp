#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;

const double INF = 0xffff;

int map[35][35];
int sl[35][35];
int n,m,s,g;

int main()
{
	while(true)
	{
		cin>>n>>m;
		if(n==0 && m==0)
			break;
		else if(m==0)
		{
			printf("unreachable\n");
			continue;
		}
		cin>>s>>g;
		int x,y;
		for(int i = 0; i < m ; i++)
		{
			cin>>x>>y;
			cin>>map[x][y]>>sl[x][y];
		}



	}
}

