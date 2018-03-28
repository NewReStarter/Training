#include <iostream>
#include <string>
#include <list>
template<typename T>
class Vector{
private:
	T* elem;
	int sz;
public:
	Vector(int s);
	~Vector(){delete[] elem;}

	// function overload -> different parameters or const/volatile on function not just return type
	T& operator[](int i);
	const T& operator[](int i) const;
	
	int size() const {return sz;}

	T* begin() const {return &elem[0];}
	T* end() const {return begin()+size();}

};

template<typename T>
Vector<T>::Vector(int s)
{
	elem = new T[s];
	sz = s;
}

template<typename T>
const T& Vector<T>::operator[](int i) const
{
	return elem[i];
}
template<typename T>
class Less_than{
	const T val;
public:
	Less_than(const T& v): val(v){}
	bool operator()(const T& x) const {return x < val;} // last const ban method () from alter anything
};

Less_than<int> lti {42};
Less_than<std::string> lts {"Backus"};

void fct(int n, const std::string& s)
{
	bool b1 = lti(n);
	bool b2 = lts(s);
	// ...
} 

template<typename C, typename P>
int count(const C& c, P pred)
{
	int cnt = 0;
	for(const auto& x: c)
		if(pred(x))
			++cnt;
	return cnt;
}

void f1(const Vector<int>& vec, const std::list<std::string>& lst, int x, const std::string& s)
{
	std::cout<< "number of values less than " << x << ":" << count(vec,Less_than<int>{x})<<"\n";
	//std::cout<< "number of values less than " << s << ":" << count(vec,Less_than<std::string>{s})<<"\n";
}

//lambda version
void f2(const Vector<int>& vec, const std::list<std::string>& lst, int x, const std::string& s)
{
	std::cout<< "number of values less than " << x << ":" << count(vec,[&](int a){return a < x;})<<"\n";
	//std::cout<< "number of values less than " << s << ":" << count(vec,[&](std::string a){return a < s;})<<"\n";
}

int main()
{
	return 0;
}

