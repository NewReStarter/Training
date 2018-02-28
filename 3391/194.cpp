#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int n;
const int MAX_NUM = 9;
int x1,y1;
bool map[MAX_NUM][MAX_NUM];
int ans_row;

void dfs(int idx)
{
	bool vflag;
	if(idx == y1)
	{
		//cout<<"t"<<endl;
		dfs(idx+1);
		return;
	}
	if(idx == MAX_NUM)
	{
		ans_row++;
		printf("%2d      ",ans_row);
		for(int i = 1; i<MAX_NUM; i++)
			for(int j =1; j<MAX_NUM; j++)
				if(map[j][i]==1)
				{
					if(i!=1)
						printf("% d",j);
					else
						printf("%d",j);
				}
		printf("\n");
		return;
	}
	else
	{
		//cout<<"n"<<endl;
		int k = 0;
		for(int i = 1; i<MAX_NUM; i++) //i -> row
		{
			if(!map[idx][i])  //no queen in this idx
			{
				vflag = 1;
				for(int j = idx-1,k = 1; j>=1;j--,k++) //pre check
				{
					if( (map[i-k][j]==1 && i-k>=0) || (map[i+k][j]==1 && i+k < MAX_NUM) || map[i][j])
					{
						vflag = 0;
						//cout<<"flag1"<<endl;
						break;
					}
				}
				if(vflag)
				{
					for(int j = idx+1, k = 1; j<MAX_NUM;j++,k++)
					{
						
						if( (map[i-k][j]==1 && i-k>=0) || (map[i+k][j]==1 && i+k < MAX_NUM) || map[i][j])
						{
							vflag = 0;
							//cout<<"flag2"<<endl;
							break;
						}
					}
				}
				if(vflag)
				{
					map[i][idx] = 1;
					dfs(idx+1);
					map[i][idx] = 0;
				}
			}
		}
		return;
	}
	

}

int main()
{
	scanf("%d",&n);
	bool endCase = 0;
	while(n--)
	{
		scanf("%d%d",&x1,&y1);
		if(endCase)
			printf("\n");
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		memset(map,0,sizeof(map));
		ans_row = 0;
		map[x1][y1] = 1;
		dfs(1);
		endCase = 1;
		ans_row = 0;
	}
	return 0;
}

