#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m;
const int MAXN = 100010;

inline void read(int& x)
{
    char c = getchar(); x = 0;
    while(c < '0' || c > '9') c = getchar();
    while(c <= '9' && c >= '0') x = x*10+c-48, c = getchar();
}

struct Point
{
	int x,y;
	Point():x(0),y(0){}
	Point(int _x, int _y):x(_x),y(_y){}
	Point operator - (Point A){  
        return Point(x-A.x, y-A.y);  
    }  
};
Point a[MAXN];
Point ch[MAXN];

inline bool cmp(const Point& p1, const Point& p2) {return p1.x < p2.x || (p1.x==p2.x && p1.y < p2.y);}

inline int det(Point a, Point b) {return a.x*b.y-a.y*b.x; }

void convex_cal()
{
	m = 0;
	for(int i = 0; i < n; ++i)
	{
		while(m>1 && det(ch[m-1]-ch[m-2], a[i]-ch[m-2]) <= 0) 
			m--;  
        ch[m++] = a[i];
	}
	
	int tmp = m;
	for(int i = n - 2 ; i >=0; i--)
	{
		while(m>tmp && det(ch[m-1]-ch[m-2], a[i]-ch[m-2]) <= 0) 
			m--;  
        ch[m++] = a[i];
	}
}

int main()
{

	while(scanf("%d",&n)!=EOF)
	{
		memset(a,0,sizeof(a));
		int x,y;
		for(int i = 0; i < n; ++i)
		{
			read(x);read(y);
			a[i] = Point(x,y);
		}
		sort(a,a+n,cmp);
		convex_cal();
		read(n);
		for(int i = 0; i < n; ++i)
		{
			bool flag = 0;
			read(x);read(y);
			Point tmp = Point(x,y);
			for(int i = 0; i < m - 1; i++)// m-1 instead of m
				if(det(ch[i+1]-ch[i],tmp-ch[i]) < 0) 
				{
					flag = 1;
					break;
				}

			if(flag)
				printf("outside\n");
			else
				printf("inside\n");
		}
	}
}