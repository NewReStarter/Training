#include<cstdio>

int exgcd(int a,int b,int& x,int& y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int r = exgcd(b,a%b,x,y);
	int t = x;
	x = y;
	y = t - a/b*y;
	return r;
}

int main()
{
	int x,y;
	printf("%d\n",exgcd(47,30,x,y));
	printf("%d\n%d\n",x,y);
	return 0;
}