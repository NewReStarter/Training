#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int k,a,b,v; 
// k -> max section a -> nuts b -> divisor v-> max nuts in each division

int main()
{
	int ans;
	while(scanf("%d%d%d%d",&k,&a,&b,&v)!=EOF)
	{
		//cout<<k<<" "<<a<<" "<<b<<" "<<v<<endl;
		ans=0;
		while(a > 0)
		{
			int div = 0;
			if(b >= k)
			{
				b -= (k-1);
				div = k;
			}
			else
			{
				div = b+1;
				b = 0;
			}
			a -= div*v;
			ans++;
			//cout<<div<<" "<<a<<endl;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}