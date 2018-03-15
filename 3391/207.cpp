// unsolved
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

string a[250];
int map[250][250];
int n,m;

int index(string s,int bot,int up)
{
	int mid = (up+bot)/2;
	//cout<<mid<<" "<<a[mid]<<endl;
	if(s == a[mid])
		return mid;
    if (s>a[mid])
		return index(s,bot,mid);
	else
		return index(s,mid+1,up);
}



int main()
{
	int i,j;
	char ch[300];
	while(cin>>n)
	{
		getchar();
		for(i = 0 ; i < n; i++)
			getline(cin,a[i]);
		sort(a,a+n-1);
		cin>>m;
		getchar();
		// build graph
		//cout<<index("hall",0,n-1)<<endl;

		for(i = 0 ; i < m; i++)
		{
			string tmp;
			string s,g;
			s = "";
			g = "";
			getline(cin,tmp);
			//cout<<tmp<<endl;
			int v = 0;
			bool flag1 = false;
			bool flag2 = false;
			bool flag3 = false;
			int len = tmp.length();
			cout<<tmp<<endl;
			for(int j = 0; j < len; j++)
			{
				//cout<<j<<" "<<s<<" "<<g<<" "<<endl;

				if(tmp.at(j)==':')
				{
					flag1 = true;
					continue;
				}
				else if(tmp.at(j) == ' ' && tmp.at(j+1)>='0' && tmp.at(j+1) <= '9' && !flag2)
				{
					flag2 = true;
					continue;
				}
				else if(flag1 && flag2)
				{
					if(tmp.at(j)==' ')
					{
						map[index(s,0,n-1)][index(g,0,n-1)] = v;
						v = 0;
						j++;
						while(j < len)
						{
							v = v*10+(tmp.at(j)-48);
							j++;
						}
						flag3 = 1;
						map[index(g,0,n-1)][index(s,0,n-1)] = v;
						continue;
					}
					else
					{
						v = v*10 + (tmp.at(j)-48);
						continue;
					}
				}
				else if(flag1 && !flag2)
				{
					g += tmp.at(j);
					continue;
				}
				else if(!flag1)
				{
					s += tmp.at(j);
					continue;
				}
				
			}
			cout<<s<<" "<<g<<endl;
			if(!flag3)
			{
					map[index(s,0,n-1)][index(g,0,n-1)] = v;
					//map[index(g,0,n-1)][index(s,0,n-1)] = v;
					//getchar();
			}	
		}
	}
}