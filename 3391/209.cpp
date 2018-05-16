#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

inline int Set(int N, int p) {return N|(1<<p);}
inline int Reset(int N, int p) {return N&=~(1<<p);}
inline bool check(int N, int p) {return N&(1<<p);}

const int dr[] {0,-1,0,1,-1,-1,1,1};
const int dc[] {1,0,-1,0,1,-1,-1,1};
const int maxx = 0;

struct Point{
 	int x,y;
}; 

bool ccw(Point a, Point b, Point c)
{
	return(b.y-a.y)*(c.x-b.x) < (c.y-b.y)*(b.x-a.x);
}

bool onseg(Point a, Point b, Point p)
{
	bool ret = (p.y-a.y)*(b.x-p.x) == (b.y-p.y)*(p.x-a.x);
	ret &= (p.x <= max(a.x,b.x) && p.x >= min(a.x,b.x));
	ret &= (p.y <= max(a.y,b.y) && p.y >= min(a.y,b.y));
	return ret;
}

bool segintersection(Point a, Point b, Point c, Point d)
{
	if( ccw(a,b,c)!=ccw(a,b,d) && ccw(c,d,a)!=ccw(c,d,b) ) return 1;
	else if(onseg(a,b,c) || onseg(a,b,d) || onseg(c,d,a) || onseg(c,d,b))
		return 1;
	else 
		return 0;
}

vector<pair<Point,Point> > v;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		v.clear();
		int n;
		cin>>n;
		for(int i = 0; i<n; ++i)
		{
			Point s,e;
			cin>>s.x>>s.y;
			cin>>e.x>>e.y;
			v.push_back(make_pair(s,e));
		}
		int ans = 0;
		for(int i = 0; i < v.size(); ++i)
		{
			bool flag = 0;
			for(int j = 0; j < v.size(); ++j)
			{
				if(i!=j)
					if(segintersection(v[i].first,v[i].second,v[j].first,v[j].second))
						flag = 1;
			}
			if(!flag) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}



