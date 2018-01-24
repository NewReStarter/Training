#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;

char line[101];
int len=0;
int pos=0;

double ansa[1000];
int idx = 0;

double readdouble();

int main()
{
	//freopen("222.in","r",stdin);
	while(cin.getline(line,101))
	{
		double ans = 0;
		double cur = 0;
		len = strlen(line);
		if(len == 0) break;
		while(pos < len)
		{
			cur = readdouble();
			ans += cur;
			//cout<<cur<<endl;
		}
		//printf("%.4f\n\n",ans);
		ansa[idx++]=ans;
		pos = 0;
	}
	// cin.getline(line,100);
	// len = strlen(line);
	// cout<<readdouble()<<endl;
	for(int i = 0; i<idx-1; i++)
		printf("%.4f\n\n",ansa[i]);
	printf("%.4f\n",ansa[idx-1]);
	return 0;
}

double readdouble()
{
	int sign = 1;
	bool flag = true;
	double pow = 0.1;
	double count = 0;
	while(true)
	{
		if(pos == len || line[pos]==' ' || line[pos]=='\n')
		{
			pos++;
			break;
		}
		if(line[pos]=='-') 
		{
			sign = -1;
			pos++;
			continue;
		}
		if(line[pos]=='.') 
		{
			flag = false;
			pos++;
			continue;
		}
		if(flag) 
		{
			count = count*10+double(line[pos]-48);
		}
		else
		{
			count = count+double(line[pos]-48)*pow;
			pow = pow*0.1;
		}
		pos++;
	}
	return sign*count;
}


