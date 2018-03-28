#include <iostream>
#include <stdexcept>
#include <string>
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

void write(const Vector<std::string>& vs)
{
	for(int i = 0; i!=vs.size();++i)
		std::cout<<vs[i]<<'\n';
}

void f2(const Vector<std::string>& vs)
{
	for(auto& s: vs)
		std::cout<<s<<'\n';
}

int main()
{
	return 0;
}