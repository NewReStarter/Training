// Vector with class
class Vector{
public:
	Vector(int s): elem{new double[s]}, sz{s} {} //construct a Vector
	double& operator[](int i) {return elem[i];} // element access: subscripting
	int size() {return sz;}
private:
	double* elem;
	int sz;
};

int main()
{
	Vector v(6);
	return 0;
}