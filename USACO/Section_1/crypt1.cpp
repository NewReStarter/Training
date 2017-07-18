/*
ID: ziliuga1
LANG: C++11
TASK: crypt1
*/
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int n;
int a[100];
bool isValid(int,int,int,int,int);
bool ok(int);
int main()
{
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");
	int count=0;
	fin>>n;
	for(int i = 0; i<n; i++)
		fin>>a[i];
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
			for(int k = 0; k<n; k++)
				for(int x = 0; x<n; x++)
					for(int y = 0; y<n; y++)
						if(isValid(i,j,k,x,y)) 
						{
							//fout<<(a[i]*100+a[j]*10+a[k])<<" "<<(a[x]*10+a[y])<<" "<<(a[i]*100+a[j]*10+a[k])*(a[x]*10+a[y])<<endl;
							count++;
						}
	fout<<count<<endl;
	return 0;
}

inline bool ok(int x)
{
	while(x>10)
	{
		bool flag=0;
		for(int i=0;i<n;i++)
			if(a[i]==(x%10))
				flag=1;
		if(!flag)return false;
		else x = x/10;
	}
	bool flag=0;
	for(int i=0;i<n;i++)
		if(a[i]==(x%10))
			flag=1;
	if(!flag)return false;
	else return true;
}

inline bool isValid(int i,int j,int k,int x,int y)
{
	int up=a[i]*100+a[j]*10+a[k];
	int down=a[x]*10+a[y];
	if(ok(up*a[y]) && ok(up*a[x]) && ok(up*down) && (up*a[y])<1000 && (up*a[x])<1000) 
		{
			return true;
		}
	else return false;
}
