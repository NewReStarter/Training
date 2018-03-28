#include<iostream>
enum color {red = 1, green = 2, blue =3};

int main()
{
	std::cout<<color::red<<std::endl; //output 1
	return 0;
}