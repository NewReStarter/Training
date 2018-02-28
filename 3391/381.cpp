#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;

char cal[200];
int len;
int pos;
struct stackchar{
	char c[500];
	int bot;
}s1,s2;   //s1 -> operator   s2 -> operand

struct stackint{
	int v[500];
	int bot;
}s3;

inline int degree(char c)
{
	if(c == 's') return 0;
	if(c == '(' || c==')') return 1;
	else if(c == '+') return 2;
	else return 3;
}

inline bool isDigit(char c)
{
	return ((c >='0' && c<='9')  || (c>='A'&&c<='F')) ? true : false;
}

int toInt(char c)
{
	if(c >='0' && c<='9')
		return c-48;
	else
		return c-55;
}

int main()
{
	while(cin.getline(cal,200))
	{
		len = strlen(cal);
		pos = 0;
		int tmp;
		s1.bot = s2.bot = s3.bot = 0;
		s1.c[0] = 's';
		while(pos<len)
		{
			//cout<<cal[pos]<<endl;
			if(cal[pos] == '+' || cal[pos] == '*' || cal[pos]=='(' || cal[pos]==')')
			{
				//cout<<cal[pos]<<endl;
				if(s1.bot==0 || s1.c[s1.bot]=='(' || cal[pos]=='(')
				{
					s1.bot++;
					s1.c[s1.bot]=cal[pos];
					pos++;
					continue;
				}
				if(cal[pos]==')')
				{
					while(s1.c[s1.bot]!='(')
					{
						s2.bot++;
						s2.c[s2.bot] = s1.c[s1.bot];
						s1.bot--;
					}
					s1.bot--;
					pos++;
					continue;
				}
				if(degree(cal[pos]) > degree(s1.c[s1.bot]))
				{
					//cout<<"f2"<<endl;
					s1.bot++;
					s1.c[s1.bot]=cal[pos];
					pos++;
					continue;
				}
				else
				{
					while(degree(cal[pos]) <= degree(s1.c[s1.bot]))
					{
						s2.bot++;
						s2.c[s2.bot] = s1.c[s1.bot];
						s1.bot--;
					}
					s1.c[++s1.bot] = cal[pos];
					pos++;
					continue;
				}
			}
			else
			{
				while(isDigit(cal[pos]))
				{
					s2.c[++s2.bot] = cal[pos];
					pos++;
				}
				s2.c[++s2.bot] = ' ';
			}
		}
		//cout<<s1.c[1]<<" "<<s1.c[2]<<" "<<s1.c[3]<<endl;

		while(s1.bot != 0)
		{
			if(s1.c[s1.bot]!='(' && s1.c[s1.bot]!=')')
				s2.c[++s2.bot] = s1.c[s1.bot--];
			else
				s1.bot--;
		}

		for(int i = 1; i<=s2.bot ; i++)
	     	cout<<s2.c[i];
		cout<<endl;
		pos = 1;
		int sum = 0;
		while(pos<=s2.bot)
		{
			if(!isDigit(s2.c[pos]))
			{
				if(s2.c[pos]==' ')
				{
					pos++;
					continue;
				}
				else if(s2.c[pos] == '+')
				{
					int a,b;
					a = s3.v[s3.bot--];
					b = s3.v[s3.bot];
					s3.v[s3.bot] = a+b;
					pos++;
					continue;
				}
				else
				{
					int a,b;
					a = s3.v[s3.bot--];
					b = s3.v[s3.bot];
					s3.v[s3.bot] = a*b;
					pos++;
					continue;
				}
			}
			else
			{
				int tmp=0,pow=1;
				while(isDigit(s2.c[pos]))
				{
					tmp = tmp*pow + toInt(s2.c[pos]);
					pow *= 16;
					pos++;
				}
				s3.v[++s3.bot] = tmp;
			}
		}
		cout<<uppercase<<hex<<s3.v[1]<<endl;

	}
	return 0;
}