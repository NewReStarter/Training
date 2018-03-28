#include<thread>

void f() {}
struct F{
	void operator()(){}
};

void user()
{
	std::thread t1 {f};
	std::thread t2 {F()};

	t1.join();			// wait for t1
	t2.join();			// wait for t2
}
// join()s wait for thread before exiting user()

int main()
{
	user();
	return 0;
}
