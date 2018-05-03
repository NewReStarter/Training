#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
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
    Point operator + (Point A){
    	return Point(x+A.x, y+A.y);
    }
};
Point a[MAXN];
Point ch[MAXN];

inline bool cmp(const Point& p1, const Point& p2) {return p1.x < p2.x || (p1.x==p2.x && p1.y < p2.y);}

inline int det(Point a, Point b) {return a.x*b.y-a.y*b.x; }
inline int dot(Point a, Point b) {return a.x*b.x+a.y*b.y; }
bool onLine(Point p, Point a, Point b)
{
	return (det(a-p,b-p)==0 && dot(a-p,b-p) < 0);
}

int P,R;
vector<Point> p,convex;

vector<Point> convexHull()
{
	int n = p.size();
	vector<Point> point(n+1);

	sort(p.begin(),p.end(),cmp);
	int m = 0;
	for(int i = 0; i < n; ++i)
	{
		while(m>1 && det(point[m-1]-point[m-2],point[i]-point[m-2]) <= 0) 
			--m;
		point[m++] = p[i];  
	}
	int k = m;
	for(int i = n-2; i >= 0; --i)
	{
		while(m>k && det(point[m-1]-point[m-2],p[i]-point[m-2]) <= 0) 
			--m;
		point[m++] = p[i];
	}

	if(n > 1) --m;
	point.resize(m);
	return point;
}

bool in(Point p0)
{
	int w = 0;
	int n = convex.size();
	for(int i = 0; i < n; ++i)
	{
		if(onLine(p0,convex[i],convex[(i+1)%n]))
			return 1;
		if(p0.x == convex[i].x && p0.y == convex[i].y)
			return 1;
		int cp = det(convex[(i+1)%n]-convex[i],p0-convex[i]);

		if(cp > 0 && convex[i].y-p0.y <= 0 && convex[(i+1)%n].y-p0.y > 0) w++;
		if(cp < 0 && convex[i].y-p0.y > 0 && convex[(i+1)%n].y-p0.y <= 0) w--;
	}

	if(w!= 0) return 1;
	return 0;
}

int main()
{
	while(cin>>P)
	{
		p.clear();
		convex.clear();
		int x,y;
		for (int i = 0; i < P; ++i)
		{
			read(x);
			read(y);
			p.push_back(Point(x,y));
		}
		convex = convexHull();
		read(R);
		while(R--)
		{
			read(x);read(y);
			if( in(Point(x,y)) ) cout<<"inside"<<endl;
			else cout<<"outside"<<endl;
		}
	}
	return 0;
}