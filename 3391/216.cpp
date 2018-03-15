#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;

const int MAXN = 1010;

int main()
{
	char ch1[MAXN],ch2[MAXN];
	int lcs[MAXN][MAXN];

	while(cin.getline(ch1,MAXN)&&cin.getline(ch2,MAXN))
	{
		//memset(lcs,0,sizeof(lcs));
		int len1 = strlen(ch1);
		int len2 = strlen(ch2);
		 for(int i = 0; i < len1; i++)
			lcs[i][0] = 0;
		for(int i = 0; i < len2; i++)
		 	lcs[0][i] = 0;
		for(int i = 1; i <= len1; i++)
			for(int j = 1; j <= len2; j++)
			{
				if(ch1[i-1] == ch2[j-1])
					lcs[i][j] = lcs[i-1][j-1]+1;
				else
					lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
			}
		cout<<lcs[len1][len2]<<endl;
	}
	return 0;
}