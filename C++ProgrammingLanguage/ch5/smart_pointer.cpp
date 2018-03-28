#include<iostream>
#include<memory>
using namespace std::unique_ptr;

void f(int i, int j)
{
	X* p = new X;					// allocate a new X	
	unique_ptr<X> sp {new X;}		// allocate a new X and give it pointer to unique_ptr
	// ...
	if(i<99) throw Z{};				// may throw an exception
	if(j<77) return;				// may return early

	p->do_something();
	sp->do_something();
	// ...
	delete p;
}
// this can solved by not using 'new'
void f2()
{
	X x;
	// ...
}

// shared_ptr is pretty the same except it is copied instead of moved

unique_ptr<X> make_X(int i)
	// make an X and immediately give it to a unique_ptr
{
	// checking
	return unique_ptr<X>{new X{i};}
}