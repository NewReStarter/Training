#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;

const int MAXN = 210;
double map[MAXN][MAXN];

struct node{
	int x,y;
}a[MAXN];


int main()
{
	int caseN = 0;
	int n,i,j,k,x,y;
	while(true)
	{
		scanf("%d",&n);
		if(n == 0) break;
		
		for(i = 0; i < n; i++)
			cin>>a[i].x>>a[i].y;
		
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				map[i][j] = map[j][i] = sqrt( (a[i].x-a[j].x)*(a[i].x-a[j].x) + (a[i].y-a[j].y)*(a[i].y-a[j].y) );

		for(k = 0; k < n; k++)
			for(i = 0; i < n; i++)
				for(j = 0; j < n; j++)
					map[i][j] = min(map[i][j], max(map[i][k],map[k][j]) );

		caseN++;
		printf("Scenario #%d\nFrog Distance = %.3f\n\n",caseN,map[0][1]);
	}
}