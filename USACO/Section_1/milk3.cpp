/*
ID: ziliuga1
LANG: C++11
TASK: milk3
*/

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int a,b,c;
bool e[21];
bool v[21][21][21];
void DFS(int,int,int);

int main()
{
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);
	cin>>a>>b>>c;
	DFS(0,0,c);
	bool ifFirst=true;
	for(int i=0;i<=20;i++)
	{
		if(!ifFirst && e[i])
		{
			cout<<" ";
		}
		if(e[i])
		{
			cout<<i;
			ifFirst=false;
		}
	}
	cout<<endl;
	return 0;
}

void DFS(int a1,int b1,int c1)
{
	if(v[a1][b1][c1])
		return;
	v[a1][b1][c1]=1;
	if(!a1)
		e[c1]=1;
	if(a>=a1+c1)
		DFS(a1+c1,b1,0);
	else
		DFS(a,b1,a1+c1-a);
	if(a>=a1+b1)
		DFS(a1+b1,0,c1);
	else
		DFS(a,a1+b1-a,c1);
 
	if(b>=b1+c1)
		DFS(a1,b1+c1,0);
	else
		DFS(a1,b,b1+c1-b);
	if(b>=a1+b1)
		DFS(0,a1+b1,c1);
	else
		DFS(a1+b1-b,b,c1);
 
	if(c>=b1+c1)
		DFS(a1,0,b1+c1);
	else
		DFS(a1,b1+c1-c,c);
	if(c>=a1+c1)
		DFS(0,b1,a1+c1);
	else
		DFS(a1+c1-c,b1,c);
	return;
}