#include<cstdio>
#include<cstring>
using namespace std;

inline void getInt(int& x)
{
    char c = getchar(); x = 0;
    while(c < '0' || c > '9') c = getchar();
    while(c <= '9' && c >= '0') x = x*10+c-48, c = getchar();
}

int weight(bool& flag)
{
	int wl,dl,wr,dr;
	getInt(wl);getInt(dl);getInt(wr);getInt(dr);

	if(!wl)	wl = weight(flag);
	if(!wr)	wr = weight(flag);
	if(wl*dl == wr * dr) return wl + wr;
	else { flag = 0; return 0;}
}

int main()
{
	int n;
	getInt(n);
	while(n--)
	{
		bool flag = 1;
		weight(flag);
		if(flag) printf("YES\n");
		else printf("NO\n");
		if(n) printf("\n");
	}
	return 0;
}