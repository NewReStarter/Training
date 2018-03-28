class Vector{
private:
	double* elem;
	int sz;
public:
	Vector(int s);   				//constructor: establish invariant, acquire resources
	~Vector() {delete[] elem;}		//destructor: release resources

	Vector(const Vector& a);		//copy constructor
	Vector& operator=(const Vector& a) //copy assignment

	Vector(Vector&& a);				// move constructor
	Vector& operator=(Vector&& a)	// move assignment

	double& operator[](int i);
	const double& operator[](int i) const;

	int size() const;
};

Vector::Vector(const Vector& a)
	:elem{new double[sz]},sz{a.sz}
{
	for (int i=0;i!=sz;++i)
		elem[i] = a.elem[i];
}

Vector& Vector::operator=(const Vector& a)
{
	double* p = new double[a.sz];
	for (int i = 0; i!=a.sz;++i)
		p[i] = a.elem[i];
	delete[] elem;
	elem = p;
	sz = a.sz;
	return *this;
}

Vector::Vector(const Vector&& a)
	:elem{a.elem},sz{a.sz}
{
	a.elem = nullptr;
	a.sz = 0;
}