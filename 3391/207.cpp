#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

int office,hall;
int g[200][200];
int N,P;
vector<string> place;

int getNode(string s)
{
	for(int i = 0; i < place.size(); ++i)
		if(place[i] == s)
			return i;
	return -1;
}
vector<string> path1,path2;

void printPath()
{
	for(int v = path1.size()-1; v >= 0 ; v--)
		cout<<path1[v]<<" -> ";
	for(int v = path2.size()-1; v >= 0 ; v--)
	{
		cout<<path2[v];
		if(v) cout<<" -> ";
	}
	printf("\n\n");
	path1.clear();
	path2.clear();
}

int officeToHall()
{
	bool vis[200];
	memset(vis,0,sizeof(vis));
	int dist[200];
	int pre[200];
	memset(dist,0x3f,sizeof(dist));
	memset(pre,-1,sizeof(pre));
	dist[office] = 0;
	pre[office] = -1;
	vector<int> q;
	q.push_back(office);
	while(!q.empty())
	{
		int u = q.front();
		int Min = dist[u];
		int idx = 0;
		for(int i = 0; i < q.size(); ++i)
		{
			if(dist[q[i]]<Min)
			{
				Min = dist[q[i]];
				u = q[i];
				idx = i;
			}
		}
		q.erase(q.begin()+idx);

		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 0; i < 200; ++i)
		{
			if(g[u][i]!=-1)
			{
				int v = i;
				if(dist[v] > dist[u] + g[u][v])
				{
					dist[v] = dist[u] + g[u][v];
					pre[v] = u;
					q.push_back(v);
				}
			}
		}
	}
	int v = hall;
	while(pre[v]!=-1)
	{
		path1.push_back(place[v]);
		v = pre[v];
	}
	path1.push_back("office");
	return dist[hall];
}

int hallToOffice()
{
	bool vis[200];
	memset(vis,0,sizeof(vis));
	int dist[200];
	int pre[200];
	memset(dist,0x3f,sizeof(dist));
	memset(pre,-1,sizeof(pre));
	dist[hall] = 0;
	pre[hall] = -1;
	vector<int> q;
	q.push_back(hall);
	while(!q.empty())
	{
		int u = q.front();
		int Min = dist[u];
		int idx = 0;
		for(int i = 0; i < q.size(); ++i)
		{
			if(dist[q[i]]<Min)
			{
				Min = dist[q[i]];
				u = q[i];
				idx = i;
			}
		}
		q.erase(q.begin()+idx);

		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 0; i < 200; ++i)
		{
			if(g[u][i]!=-1)
			{
				int v = i;
				if(dist[v] > dist[u] + g[u][v])
				{
					dist[v] = dist[u] + g[u][v];
					pre[v] = u;
					q.push_back(v);
				}
			}
		}
	}
	int v = office;
	while(pre[v]!=-1)
	{
		path2.push_back(place[v]);
		v = pre[v];
	}
	return dist[office];
}

int main()
{
	while(scanf("%d\n",&N)!=EOF)
	{
		place.clear();
		for(int i = 0; i < N; ++i)
		{
			string s="";
			getline(cin,s);
			//cout<<s<<endl;
			if(s == "office") office = i;
			if(s == "hall") hall = i;
			place.push_back(s);
		}
		memset(g,-1,sizeof(g));
		scanf("%d\n",&P);
		for(int i = 0; i < P; ++i)
		{
			string s="";
			getline(cin,s);
			//cout<<s<<endl;
			string u,v,num;
			string tmp;
			u = s.substr(0,s.find(":"));
			// cout<<u<<endl;
			v = s.substr(s.find(":")+1,s.length());
			// cout<<v<<endl;
			int w1,w2;
			w1 = w2 = -1;
			w2 = stoi(v.substr(v.find_last_of(" ")+1,v.length()));
			v = v.substr(0,v.find_last_of(" "));
			if(getNode(v) == -1)
			{
				w1 = stoi(v.substr(v.find_last_of(" ")+1,v.length()));
				v = v.substr(0,v.find_last_of(" "));
			}
			//cout<<u<<":"<<v<<" "<<w1<<" "<<w2<<endl;
			//cout<<w1<<" "<<w2<<endl;
			// while(1)
			// {
			// 	int i = v.find(" ");
			// 	if(v[i+1]>='0' && v[i+1]<='9') 
			// 	{
			// 		num = v.substr(i+1,v.length());
			// 		tmp += v.substr(0,i);
			// 		v = tmp;
			// 		break;
			// 	}
			// 	else
			// 	{
			// 		tmp += v.substr(0,i+1);
			// 		v = v.substr(i+1,v.length());
			// 	}
			// }
			// cout<<v<<endl;
			// cout<<num<<endl;
			int _u,_v;
			_u = getNode(u);
			_v = getNode(v);
			//cout<<_u<<" "<<_v<<endl;
			//int index = num.find(" ");
			if(w1 != -1)
			{
				//cout<<1<<endl;
				g[_u][_v]=w1;
				g[_v][_u]=w2;
				//cout<<g[_u][_v]<<" "<<g[_v][_u]<<endl;
			}
			else
			{
				g[_u][_v] = w2;
				//cout<<g[_u][_v]<<endl;
			}
		}
		int d1 = officeToHall();
		int d2 = hallToOffice();
		cout<<d1+d2<<endl;
		printPath();
	}

	// }
	// string s;
	// s = "office:hall 1 1";
	// cout<<s.substr(0,s.find(":"))<<" "<<s.substr(s.find(":")+1,s.length())<<endl;
	return 0;
}