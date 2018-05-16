#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-8;
typedef long long ll;

ll gcd(ll a, ll b)
{
	return b == 0 ? a: gcd(b,a%b);
}

int dcmp(double x)
{
	if(fabs(x) < eps) return 0;
	else return x>0 ? 1:-1;
}

struct point
{
	ll x,y;
	point operator+(point a){
		return (point){x+a.x,y+a.y};
	}
	point operator-(point a){
		return (point){x-a.x,y-a.y};
	}
	point operator*(double a){
		return (point){x*a,y*a};
	}
	point operator/(point a){
		return (point){x/a.x,y/a.y};
	}

	bool operator <(const point& a) const {
		return dcmp(x-a.x)<0 || ( dcmp(x-a.x) == 0 && dcmp(y-a.y)<0 );
	}

	bool operator ==(const point& a) const{
		return dcmp(x-a.x)==0 && dcmp(y-a.y)==0;
	}
};

bool cmp(const point& a, const point& b)
{
	return dcmp(a.x-b.x)<0 || ( dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y)<0 ); 
}

point rota(point p, double ang)
{
	return (point){p.x*cos(ang) - p.y*sin(ang), p.x*sin(ang)+p.y*cos(ang)};
}

double dot(point a, point b)
{
	return a.x*b.x + a.y * b.y;
}

ll cross(point a, point b)
{
	return a.x*b.y - a.y*b.x;
}

point lineintersection(point p, point v, point q, point w)
{
	point u = p - q;
	return p+v*(cross(w,u)/cross(v,w));
}

double len(point p)
{
	return sqrt(p.x*p.x+p.y*p.y);
}

double angle(point a, point b)
{
	double s = dot(a,b)/len(a)/len(b);
	s=max(-1.0,s);
	s=min(1.0,s);
	return acos(s);
}

int onsegment(point p, point a, point b)
{
	return (dcmp(cross(a-p,b-b))==0 && dot(a-p,b-p)<0);
}

int segmentintersection(point a, point b, point x, point y)
{
	double a1,a2,b1,b2;
	if(a==b && x==y) return 0;
	if(a==b)
	{
		if(onsegment(a,x,y)) return 1;
		else return 0;
	}
	if(x==y){
		if(onsegment(x,a,b)) return 1;
		else return 0;
	}
	a1 = cross(b-a,x-a);
	a2 = cross(b-a,y-a);
	b1 = cross(y-x,a-x);
	b2 = cross(y-x,b-x);
	if(dcmp(a1*a2)<0 && dcmp(b1*b2)<0) return 1;
	else return 0;
}

double distancetosegment(point p, point a, point b){
	if(a==b) return len(p-a);
	if(dot(p-a,b-a)<0) return len(p-a);
	if(dot(p-b,a-b)<0) return len(p-b);
	return fabs(cross(p-a,b-a))/len(b-a);
}

int convex(int n, point *p, point* con){
	int i,k,t;
	con[1]=p[1];
	k = 1;
	for(i=2;i<=n;i++){
		while(k>1 && dcmp(cross(con[k]-con[k-1],p[i]-con[k-1]))<=0) k--;
		con[++k] = p[i];
	}
	t = k;
	for(i=n-1;i>=1;i--){
		while(k>t && dcmp(cross(con[k]-con[k-1],p[i]-con[k-1]))<=0) k--;
		con[++k] = p[i];
	}
	if(k>1) k--;
	return k;
}

int inpoly(point p, int n, point* poly){
	int i,j,wn;
	double dy1,dy2;
	wn = 0;
	for(i = 1; i <= n; i++)
	{
		j=i+1;
		if(j>n) j = 1;
		if(onsegment(p,poly[i],poly[j])) return 1;
		dy1 = poly[j].y-p.y;
		dy2 = poly[i].y-p.y;
		if(dy2>=0 && dy1<0 && dcmp(cross(poly[j]-poly[i],p-poly[i]))<0) wn++;
		if(dy1>=0 && dy2<0 && dcmp(cross(poly[j]-poly[i],p-poly[i]))>0) wn--;
	}
	if(wn) return 1;
	else return 0;
}

double area(point a[], int n)
{
	int i;
	double s=0;
	a[n+1]=a[1];
	for(int i = 1; i<=n; i++){
		s+=cross(a[i]-a[1],a[i+1]-a[1]);
	}
	return abs(s)/2;
}

point p[1010],c[1010];

int main()
{
	int n,i,t,k;
	t=0;
	double a,b;
	while(scanf("%d",&n)!=-1)
	{
		if(n==0) break;
		for(int i=1;i<=n;i++)
			cin>>p[i].x>>p[i].y;
		a=area(p,n);
		sort(p+1,p+1+n,cmp);
		k= convex(n,p,c);
		b = area(c,k);
		cout<<"Tile #"<<++t<<endl;
		printf("Wasted Space = %.2f ",(b-a)*100/b);
		puts("%");
		printf("\n");
	}
	return 0;
}