#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;

int area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1;
}

bool intersection(int x1, int y1, int x2, int y2, int x3, int y3,int x4, int y4)
{
	int a1 = area(x1,y1,x3,y3,x2,y2);
	int a2 = area(x1,y1,x4,y4,x2,y2);
	int a3 = area(x3,y3,x1,y1,x4,y4);
	int a4 = area(x3,y3,x2,y2,x4,y4);

	if(a1*a2<0 && a3*a4 < 0)
		return 1;
	if(a1==0 && (x3-x1)*(x3-x2) <= 0 && (y3-y1)*(y3-y2) <= 0) return 1;
	if(a2==0 && (x4-x1)*(x4-x2) <= 0 && (y4-y1)*(y4-y2) <= 0) return 1;
	if(a3==0 && (x1-x3)*(x1-x4) <= 0 && (y1-y3)*(y1-y4) <= 0) return 1;
	if(a4==0 && (x2-x3)*(x2-x4) <= 0 && (y2-y3)*(y2-y4) <= 0) return 1;

	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int xs,ys,xe,ye,xl,yt,xr,yb;
		scanf("%d%d%d%d",&xs,&ys,&xe,&ye);
		scanf("%d%d%d%d",&xl,&yt,&xr,&yb);
		if(xl>xr) swap(xl,xr);
		if(yb>yt) swap(yb,yt);

		bool flag = (intersection(xs,ys,xe,ye,xl,yt,xr,yt) ||
			intersection(xs,ys,xe,ye,xl,yb,xr,yb) ||
			intersection(xs,ys,xe,ye,xl,yt,xl,yb) ||
			intersection(xs,ys,xe,ye,xr,yt,xl,yb) ||
			(xs>=xl && xs<=xr && xe>=xl && xe<=xr && ys>=yb && ys<=yt && ye>=yb && ye<=yt));

		if(flag) printf("T\n");
		else printf("F\n");
	}
	return 0;
}