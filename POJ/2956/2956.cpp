#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const int MAXN = 1000000;
struct data{
	int v,s;
	data(){}
	data(int _v, int _s){v=_v;s=_s;}
}po[MAXN+10];



int main()
{
	int f=1,r;
	int n;
	for(r=1;r<10;r++)
		po[r] = data(r,1<<r);
	while(r<=MAXN)
	{
		int v = po[f].v,s=po[f].s;
		f++;
		for(int i = 0; i<10; i++)
			if(!(s&(1<<i)))
				po[r++] = data(v*10+i,s|(1<<i));
	}
	while(cin>>n && n)
	{
		cout<<po[n].v<<endl;
	}
	return 0;
}

