#include<iostream>
#include<string>
#include<initializer_list>
class Container{
public:
	virtual double& operator[](int) = 0;
	virtual int size() const = 0;
	virtual ~Container(){}
};

void use(Container& c)
{
	const int sz = c.size();

	for(int i=0;i!=sz;++i)
		std::cout<<c[i]<<'\n';
}

class Vector{
private:
	double* elem;
	int sz;
public:
	Vector(int s):elem{new double[s]},sz{s}
	{
		for(int i = 0; i != s; ++i) elem[i] = 0;
	}
	Vector(std::initializer_list<double>);
	~Vector() {delete[] elem;}

	double& operator[](int i) {return elem[i];}
	int size() const {return sz;}

};

Vector::Vector(std::initializer_list<double> lst)
	:elem{new double[lst.size()]},sz{static_cast<int>(lst.size())}
{
	std::copy(lst.begin(),lst.end(),elem); //<string>
}

class Vector_container : public Container{
	Vector v;
public:
	Vector_container(int s): v(s) {}
	Vector_container(std::initializer_list<double> il): v(il) {}
	~Vector_container() {}

	double& operator[](int i){return v[i];}
	int size() const {return v.size();}
};

void g()
{
	Vector_container vc {10,9,8,7,6,5,4,3,2,1};
	use(vc);
}

int main()
{
	g();
	return 0;
}

