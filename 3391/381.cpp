#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

struct stackChar
{
	char ch[200];
	int bot;
	void push(char c)
	{
		bot++;
		ch[bot] = c;
	}
	char pop()
	{
		char c = ch[bot];
		bot--;
		return c;
	}
	bool empty() {
		if(bot == -1) return 1;
		return 0;
	}
};

struct stackInt
{
	int ch[200];
	int bot;
	void push(int c)
	{
		bot++;
		ch[bot] = c;
	}
	int pop()
	{
		int c = ch[bot];
		bot--;
		return c;
	}
	bool empty() {
		if(bot == -1) return 1;
		return 0;
	}
};

bool isnum(char c)
{
	if((c >= '0' && c <= '9') || (c>='A' && c<='F')) return 1;
	return 0;
}

int main()
{
	char input[200];

	while(cin.getline(input,200))
	{
		stackChar op;
		stackInt num;
		op.bot = -1, num.bot = -1;
		queue<char> postfix;
		int len = strlen(input);

		for(int i = 0; i < len; ++i)
		{
			if(isnum(input[i]))
				postfix.push(input[i]);
			else if(input[i] == '+')
			{
				while( (!op.empty()) && ((op.ch[op.bot] == '*') || (op.ch[op.bot] == '+')))
				{
					postfix.push(op.pop());
				}
				op.push(input[i]);
			}
			else if(input[i] == '*')
			{
				while(!op.empty() && op.ch[op.bot] == '*')
				{
					postfix.push(op.pop());
				}
				op.push(input[i]);
			}
			else if(input[i] == '(')
				op.push(input[i]);
			else
			{
				while(op.ch[op.bot]!='(')
				{
					postfix.push(op.pop());
				}
				op.bot--;
			}
		}

		while(!op.empty())
		{
			postfix.push(op.pop());
		}

		int tmp;

		while(!postfix.empty())
		{
			if(postfix.front() == '+')
			{
				tmp = num.ch[num.bot];
				num.bot--;
				tmp += num.ch[num.bot];
				num.bot--;
				num.push(tmp);
				postfix.pop();
			}
			else if(postfix.front() == '*')
			{
				tmp = num.ch[num.bot];
				num.bot--;
				tmp *= num.ch[num.bot];
				num.bot--;
				num.push(tmp);
				postfix.pop();
			}
			else if(postfix.front() >= 'A' && postfix.front() <= 'F')
			{
				tmp = postfix.front() - 'A' + 10;
				num.push(tmp);
				postfix.pop();
			}
			else
			{
				tmp = postfix.front() - '0';
				num.push(tmp);
				postfix.pop();
			}
		}

		int res = num.pop();
		cout<<hex<<uppercase<<res<<endl;
	}
	return 0;
}