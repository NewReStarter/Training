#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
#include <sstream>
#include <ctype.h>
#include <utility>
using namespace std;

int main()
{
	set<string> dict;
	set<string> :: iterator itr;
	string str;
	stringstream ss;

	while(getline(cin,str))
	{
		for(int i = 0; i < str.size(); ++i)
		{
			if(isalpha(str[i]))
				str[i]=tolower(str[i]);
			else
				str[i] = ' ';
		}
		ss.clear();
		ss<<str;
		while(ss>>str)
			dict.insert(str);

	}
	for(itr = dict.begin(); itr!=dict.end(); itr++)
		cout<< *itr << endl;

	return 0;
}