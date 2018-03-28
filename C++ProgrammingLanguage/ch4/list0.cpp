#include<list>
#include<string>

struct Entry{
	string name;
	int number;
};

list<Entry> phone_book = {
	{"David", 123},
	{"karl", 456},
	{"Bertrand",789}
};

int search(const string& s)
{
	for(const auto& x: phone_book)
		if(x.name == s)
			return x.number;

	return 0;
}

int search_p(const string& s)
{
	for(auto p = phone_book.begin(); p!=phone_book.end();++p)
		if(p->name==s)
			return p->number;

	return 0;
}

void f(const Entry& ee, list<Entry>::iterator p, list<Entry>::iterator q)
{
	phone_book.insert(p,ee); 	// add ee before the element referred to by p
	phone_book.erase(q); 		// remove the element referred to by q }
}