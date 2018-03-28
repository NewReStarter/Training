#include<map>
#include<string>

//implemented as a balanced binary tree 

std::map<string, int> phone_book{
	{"David", 123},
	{"karl", 456},
	{"Bertrand",789}
};

int search(string s) {return phone_book[s];} //O(logn)

//implemented as hash

unordered_map<string, int> phone_book2{
	{"David", 123},
	{"karl", 456},
	{"Bertrand",789}
}

int search2(string s) {return phone_book2[s];} //O(1)

