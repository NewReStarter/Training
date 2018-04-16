#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int main()
{
	int t,len;
	cin>>t;
	while(t--)
	{
		int ans = 0;
		char c[1010];
		scanf("%s",c);
		len = strlen(c);
		for(int i = 0; i < len; ++i)
		{
			ans += min(c[i]-'A','A'+26-c[i]);
		}
		//deduct
		int dec = 0;
		for(int i = 1; i < len; ++i)
		{
			// c[0] might be 0 so init to -1
			int pos=-1;
			int end=-1;
			if(c[i] == 'A')
			{
				pos = i;
				for(int j = i+1; j<len;++j)
				{
					++i;
					if(c[j]!='A')
					{
						end=j-1;
						break;
					}
				}
			
				if(end == -1) // all A
				{
					end = len-1;
				}
				dec = max(dec,(end+1-pos-min(pos-1,len-1-end)));
			}
		}
		ans += len-1-dec;
		cout<<ans<<endl;
	}
	return 0;
}