/*
ID: ziliuga1
LANG: C++11
TASK: combo
*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n;
struct lock{
	int i;
	int j;
	int k;
};
lock john,master;
void unlock(int,int,int);
bool check(int,int);
int count=0;
int main()
{
	freopen("combo.in","r",stdin);
	freopen("combo.out","w",stdout);
	cin>>n;
	cin>>john.i>>john.j>>john.k;
	cin>>master.i>>master.j>>master.k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				unlock(i,j,k);
	cout<<count<<endl;
	return 0;
}

bool check(int x,int y)
{
	 if(abs(x-y)<=2)
	 	return true;
	 else if(y==n-1)
	 {
	 	if(x==1) return true;
	 }
	 else if(y==n)
	 {
	 	if(x==2) return true;
	 	if(x==1) return true;
	 }
	 else if(y==2)
	 {
	 	if(x==n) return true;
	 }
	 else if(y==1)
	 {
	 	if(x==n-1) return true;
	 	if(x==n) return true;
	 }
	 return false;
}

void unlock(int i, int j, int k)
{
	if(check(i,john.i) && check(j,john.j) && check(k,john.k)) count++;
	else if(check(i,master.i) && check(j,master.j) && check(k,master.k)) count++;
}
/*
This question also use brute-force search all the possibilities and count++ when
matched. Another idea is to use an arrayn to roll 
*/