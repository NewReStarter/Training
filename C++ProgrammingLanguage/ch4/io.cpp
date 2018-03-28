#include <iostream>
#include <istream>
#include <ostream>
#include <string>
using namespace std;

struct Entry{
	string name;
	int number;
};

// write Entry using {"name",number} format

ostream& operator<<(ostream& os, const Entry& e)
{
	return os<<"{\"" << e.name << "\","<<e.number<<"}";
}

// read coressponding pairs
istream& operator>>(istream& is, Entry& e)
{
	char c,c2;
	if(is>>c && c=='{' && is>>c2 && c2=="")
	{
		string name;
		while(is>>get(c) && c!='"')
			name+=c;

		if(is>>c && c==',')
		{
			int number = 0;
			if(is>>number>>c && c=='}')
				e = {name,number};
			return is;
		}
	}
}