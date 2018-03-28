#include<iostream>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
int map[4][4],ans,cnt;

bool check()
{
	rep(i,4)
		rep(j,4)
			if(map[i][j]!=map[0][0])
				return false;
	return true;
}

void flip(int x, int y)
{
	map[x][y] = !map[x][y];
	//flip adjacent
	if(x > 0) map[x - 1][y] = !map[x - 1][y];
    if(x < 3) map[x + 1][y] = !map[x + 1][y];
    if(y > 0) map[x][y - 1] = !map[x][y - 1];
    if(y < 3) map[x][y + 1] = !map[x][y + 1];
}

void dfs(int x, int y)
{
	if(check()) ans = min(ans,cnt);
	if(x == 4)
	{
		x = 0;
		++y;
	}
	if(y == 4)
		return;
	//flip this one
	flip(x,y);
	cnt++;
	if(check()) ans = min(ans,cnt);
	dfs(x+1,y);
	//not flip this one
	cnt--;
	flip(x,y);
	dfs(x+1,y);
}

int main()
{
	char c;
	ans = 17;
	cnt = 0;
	rep(i,4)
		rep(j,4)
		{
			cin>>c;
			map[i][j] = (c == 'b' ? 1 : 0 );
		}
	dfs(0,0);
	if(ans > 16)
		cout<<"Impossible"<<endl;
	else
		cout<<ans<<endl;
	return 0;

}