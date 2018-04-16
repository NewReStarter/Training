#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void read(int& x)
{
    char c = getchar(); x = 0;
    while(c < '0' || c > '9') c = getchar();
    while(c <= '9' && c >= '0') x = x*10+c-48, c = getchar();
}

const int MAXN = 1000100;  
int a[MAXN],d[MAXN];
int n;
int i,j;

int bsearch(int a, int l, int r)
{
	int mid;
	while(l<=r)
	{
		mid = (l+r)/2;
		if(d[mid] == a)
		{
			l = mid;
			return l;
		}
		else if (d[mid] > a)
		{
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	return l;
}

int lnds()
{
	memset(d,0,sizeof(d));
	d[1] = a[0];
	int len = 1;
	for(i = 0; i < n; i++)
	{
		if(a[i] >= d[len])
		{
			d[++len] = a[i];
		}
		else
		{
			j = bsearch(a[i],1,len);
			d[j] = a[i];
		}
	}
	return j;
}



int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(i = 0; i < n; i++)
			read(a[i]);
		cout<<lnds()<<endl;
	}
	return 0;
}