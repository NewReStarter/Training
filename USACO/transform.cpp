/*
ID: ziliuga1
LANG: C++11
TASK: transform
*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

char g1[10][10];
char g2[10][10];
int n;
bool isSame(char [10][10], char [10][10]);
char **reflect(char [10][10]);
int trans(char [10][10], char[10][10]);

int main()
{
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	cin>>n;
	for (int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin>>g1[i][j];
	for (int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin>>g2[i][j];
	cout<<trans(g1,g2)<<endl;
	return 0;
}

bool isSame(char a[10][10], char b[10][10])
{
	for(int i=0; i < n; i++)
		for(int j=0; j < n; j++)
			if(a[i][j] != b[i][j])
				return 0;
	return 1;
}

int trans(char a[10][10], char b[10][10])
{
	char cmp[10][10];

	//no change

	//rotate 90
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cmp[j][n-1-i]=a[i][j];
	
	if(isSame(cmp,b)) return 1;

	//rotate 180
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cmp[n-1-i][n-1-j] = a[i][j];
	if(isSame(cmp,b)) return 2;

	//rotate 270
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cmp[n-1-j][i] = a[i][j];
	if(isSame(cmp,b)) return 3;

	//reflection
	char tmp[10][10];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			tmp[i][n-1-j] = a[i][j];
	if(isSame(tmp,b)) return 4;

	//combination
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cmp[j][n-1-i]=tmp[i][j];
	if(isSame(cmp,b)) return 5;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cmp[n-1-i][n-1-j] = tmp[i][j];
	if(isSame(cmp,b)) return 5;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cmp[n-1-j][i] = tmp[i][j];
	if(isSame(cmp,b)) return 5;

	if(isSame(a,b)) return 6;

	return 7;
}