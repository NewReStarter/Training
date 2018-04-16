//高精度乘法
#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>

using namespace std;

string result;

string mul(string a, string b) // a * b
{
	string tmp = string(150,'0');
	int carrier=0; //进位
	int ans=0;

	int i,j;

	for(i = 0; i < a.length(); i++)
	{
		carrier = 0;
		for(j = 0; j < b.length(); j++)
		{
			ans = ( (b.at(j)-'0')*(a.at(i)-'0') + (tmp.at(i+j)-'0') + carrier ) % 10;
			carrier = ( (b.at(j)-'0')*(a.at(i)-'0') + (tmp.at(i+j)-'0') + carrier ) / 10;
			tmp[i+j] = ans + '0';
		}
		if(carrier)
		{
			tmp[i+j] = carrier + '0';
		}
	}
	tmp = tmp.substr(0,i+j);
	return tmp;
}

string expo(string multier, int time)
{
	if(time==1)
		return multier;
	result = expo(multier,time-1);
	return mul(result,multier);
}

int main()
{
	string base;
	int time;
	while(cin>>base>>time)
	{
		int start = 0;
		int end = base.length()-1;
		int pos = base.find('.');

		while(start <= base.length()-1 && base.at(start)=='0'  )
		{
			start++;
		}
		if(pos!=-1)
		{
			while(end>=0 && base.at(end)=='0')
			{
				end--;
			}
		}

		base = base.substr(start,end-start+1);
		pos = base.find('.');
		if(pos!=-1)
		{
			int len = base.length();
			base.erase(pos,1);
			pos = time * (len-pos-1);
		}

		reverse(base.begin(),base.end());

		end = 0;
		result = expo(base,time);

		if(pos!=-1)
		{
			result.insert(pos,1,'.');

			while(result.at(end) == '0')
			{
				end++;
			}

			if(result.at(end) == '.')
			{
				end++;
			}
		}

		start = result.length()-1;
		while(result.at(start) == '0' && start>=0)
		{
			start--;
		}

		if(start < end)
		{
			result="0";
		}
		else
		{
			result = result.substr(end,end-start+1);
			reverse(result.begin(),result.end());
		}

		cout<<result<<endl;
	}
	return 0;
}