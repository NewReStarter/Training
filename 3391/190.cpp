#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int n;
struct expr{
	char ch[100];
	int bot;
};

int weigh(char c){
	switch(c){
		case '/':
		case '*': return 2;
		case '+':
		case '-': return 1;
		case '!': return -1;
		default : return 0;
	}
}

int main()
{
	scanf("%d",&n);
	getchar();
	getchar();
	while(n--)
	{
		char tmp[10];
		char infix[500];
		int len = 0;
		expr s;
		s.bot = 0;
		s.ch[++s.bot] = '!';
		char ans[500];
		int idx = 0;
		while(cin.getline(tmp,10))
		{
			if(strlen(tmp) == 0)
				break;
			else
				infix[len++] = tmp[0];
		}
		infix[len++] = '!';
		infix[len++] = '\0';
		for(int i = 0; i < len; i++)
		{
			if(infix[i] == '(')
			{
				s.ch[++s.bot] = infix[i];
			}
			else if(infix[i] == ')')
			{
				while(s.ch[s.bot]!='(')
				{
					ans[idx++] = s.ch[s.bot];
					s.bot--;
				}
				s.bot--;
			}
			else if(infix[i] >= '0' && infix[i]<='9')
			{
				ans[idx++] = infix[i];
			}
			else if(infix[i] == '!')
			{
				while(s.ch[s.bot] != '!')
				{
			   		ans[idx++]=s.ch[s.bot];
					s.bot--;
				}
			}
			else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
			{
				while(weigh(infix[i]) <= weigh(s.ch[s.bot]))
				{
					ans[idx++] = s.ch[s.bot];
					s.bot--;
				}
				s.ch[++s.bot] = infix[i];
			}
		}
		ans[idx++] = '\0';
		printf("%s\n",ans);
		if(n)
			printf("\n");
	}
	return 0;
}