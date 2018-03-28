// easy passing argument and returning result
#include<thread>
#include<vector>
#include<iostream>
void f(const std::vector<double>& v, double* res)	//take input and pass to res
{
	double* p = new double[v.size()];
	int len = 0;
	for(const auto& x: v)
		p[len++] = x;
	res = p;
}

int main()
{
	std::vector<double> vec1 {1,2,3};
	//std::vector<double> vec2 {4,5,6};

	double res1,res2;

	std::thread t1 {f,vec1,&res1};
	//std::thread t2 {F{vec2,&res2}};

	t1.join();
	//t2.join();

	std::cout<<res1<<'\n';
}

