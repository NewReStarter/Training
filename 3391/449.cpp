#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

bool map[60][60]; // 1 -> land  0 -> water
char line[60];    // tmp line
int row = 0;      // row number
int len;

void processmap();

int main()
{
	//freopen("449.in","r",stdin);
	while(cin.getline(line,60))
	{
		if(strlen(line)==0)
		{
			processmap();
			row = 0;
		}
		else
		{
			len = strlen(line);
			for(int i = 0; i < len; i++)
			{
				map[row][i] = line[i]=='#' ? 1 : 0;
			}
			row++;
		}
	}
	//processmap();
	return 0;
}


void processmap()
{
	int ans = 0;
	for(int i = 0; i < row; i++)
	{
		if(i % 2 == 0) //even
		{
			for(int j = 0; j < len; j++)
			{
				if(map[i][j] != map[i][j+1] && j+1<len)
					ans++;
				int left = j - 1;
				if(i+1 < row && left >= 0 && map[i][j]!=map[i+1][left]) ans++;
				int right = j;
				if(i+1 < row && map[i][j]!=map[i+1][right]) ans++;
			}
		}
		else //odd
		{
			for(int j = 0; j < len; j++)
			{
				if(map[i][j] != map[i][j+1] && j+1<len)
					ans++;
				int left = j;
				int right = j+1;
				if(i+1 < row && map[i][j]!=map[i+1][left]) ans++;
				if(i+1 < row && right < len && map[i][j]!=map[i+1][right]) ans++;
			}
		}	
	}
	cout<<ans<<endl;
}