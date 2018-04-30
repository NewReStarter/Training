#include<cstdio>

int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main()
{
	int a,b;
	printf("%d\n",gcd(1071,462)); //21
	printf("%d\n",gcd(5,3)); //1
	return 0;
}