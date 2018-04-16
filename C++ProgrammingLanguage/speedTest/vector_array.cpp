#include<vector>
#include<cstdio>
#include<ctime>
using namespace std;

int main()
{
	clock_t start_t, end_t;
	vector<int> v;
	int a[1000100];
	start_t = clock();
	for (int i = 0; i < 1000000; ++i)
		v.push_back(i);
	end_t = clock();
	printf("vector:%lu\n",end_t-start_t);
	start_t = clock();
	for (int i = 0; i < 1000000; ++i)
		a[i] = i;
	end_t = clock();
	printf("array:%lu\n",end_t-start_t);
	return 0;
}
//vector:27027
//array:5891