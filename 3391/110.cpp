#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

bool ischar(char c){
	if( (c >= 'a' && c<='z') || (c >= 'A' && c<='Z') || c == '-')
		return true;
	else
		return false;
}
struct word{
	char str[100];
	int len;
};
int main()
{
	char ch[100]; 
	word w;
	w.len=0;
	while(true)
	{
		scanf("%s",ch);
		if(ch[0]=='E' && ch[1]=='-' && ch[2]=='N' && ch[3]=='-' && ch[4]=='D')
			break;
		int len = strlen(ch);
		int deduct =0;
		for(int i = 0; i < len; i++)
			if(!ischar(ch[i]))
				deduct++;
		len -= deduct;
		if(len>w.len)
		{
			w.len = len;
			strcpy(w.str,ch);
		}
	}
	for(int i = 0;i < strlen(w.str); i++)
	{
		if(ischar(w.str[i]))
		{
			if(w.str[i] >= 'A' && w.str[i] <= 'Z')
				printf("%c",w.str[i]+32);
			else
				printf("%c",w.str[i]);
		}
	}
	printf("\n");
	return 0;
}