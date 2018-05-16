#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;

struct edge{
  int to,limit;
  double dist;
};

struct Point{
  int speed;
  int prev;
  int v;
  double cost;
  Point(){}
  Point(int speed_=0,int prev_=0,int v_=0,double cost_=0)
    :speed(speed_),prev(prev_),v(v_),cost(cost_){}
  bool operator>(const Point &r) const{
    return cost > r.cost;
  }
};

vector<edge> G[110];
double d[35][35][35];
bool vis[35][35][35];
typedef pair<int,int> pii; 
typedef pair<int,pii> PII;
typedef pair<double,PII> P;
 
double dikstra(int s,int g)
{
	int ds[3]={-1,0,1};
  	priority_queue<Point,vector<Point>,greater<Point> > q;
   
  	for(int i=0;i<35;i++)
    	for(int j=0;j<35;j++)
      		for(int k=0;k<35;k++)
    			d[i][j][k]=INF;
   
  memset(vis,0,sizeof(vis));
  
  d[0][s][0]=0;
  Point tmp(0,0,s,0);
  q.push(tmp);
   
  while(!q.empty())
  {
    Point p=q.top();
    q.pop();
    if(d[p.speed][p.v][p.prev]<p.cost) continue;
    
    if(p.speed==1 && p.v==g) return p.cost;
 
    for(auto e: G[p.v])
    {
      	for(int j=0;j<3;j++)
      	{
    		int ns=p.speed+ds[j];
    		if(1<=ns && ns<= e.limit && vis[ns][e.to][p.v]==false && e.to!=p.prev && d[ns][e.to][p.v]>p.cost+e.dist/ns)
    		{
 
      			vis[ns][e.to][p.v]=true;
      			Point tmp(ns,p.v,e.to,p.cost+e.dist/ns);
      			q.push(tmp);
      			d[ns][e.to][p.v]=p.cost+e.dist/ns;
      			//cout << ns;
    		}
      	}
    }
  }
  return -1;
}
 
int main(){
  int n,m,s,g;
  while(cin>>n>>m,n)
  {
	for(int i=0;i<100;i++)
    	G[i].clear();
    cin>>s>>g;
    for(int i=0;i<m;i++)
    {
      	int x,y,c;
      	double d;
      	cin>>x>>y>>d>>c;
      	G[x].push_back((edge){y,c,d});
      	G[y].push_back((edge){x,c,d});
    }
    double ans=dikstra(s,g);
    if(ans==-1)
    	cout << "unreachable" << endl;
    else printf("%.5lf\n",ans);
  }
  return 0;
}