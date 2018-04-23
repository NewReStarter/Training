#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

const int MAXN = 200;
const double PI = acos(-1.0);

struct circle{
	int x,y,r;
	circle():x(0),y(0),r(0){}
	circle(int _x,int _y,int _r):x(_x),y(_y),r(_r){}
};

int n;

int main()
{
	while(1)
	{
		cin>>n;
		if(!n) break;
		circle c[MAXN];
		for (int i = 0; i < n; ++i)
		{
			int x,y,r;
			cin>>x>>y>>r;
			c[i] = circle(x,y,r);
		}

		double ans = 0.0;
		for (int t = 0; t < 24*60; t++) 
		{
    		double shade = 0.0;
    		double ang = 2*PI*t/(24*60);
   		 	double prj_x = 500.0 * sin(ang);
    		double prj_y = 500.0 * cos(ang);

    		for (int i = 0; i < n; i++) 
    		{
      			double prj = (prj_x * c[i].x + prj_y * c[i].y) / sqrt(prj_x * prj_x + prj_y * prj_y);
      			if (prj < 0) continue;
      		
      			double dist = c[i].x*c[i].x + c[i].y*c[i].y - prj*prj;
      			if (dist > c[i].r*c[i].r) continue;

      			shade += 2*sqrt(c[i].r*c[i].r - dist);
    		}
    		ans = max(ans,shade);
  		}
		printf("%.3f\n",ans);
	}
	return 0;
}