#include<vector>

std::vector<int> v1 = {1,2,3,4};		// size is 4
std::vector<string> v2;					// size is 0
std::vector<Shape*> v3(23);				// size is 23, initial element value is nullptr
std::vector<double> v4(23,9.9);			// size is 23, initial element value is 9.9

// for vector does not have range checking
// an adaptation can be done

void silly(vector<int>& book)
{
	int i = book[book.size()]. //out of range but not report
	// likely to place some random value in i 
}

template<typename T>
class Vec::public std::vector<T>{
public:
	using vector<T>::vector;  //using vector's constructor

	T& operator[](int i)
	{
		return vector<T>::at(i);
	}

	const T& operator[](int i) const
	{
		return vector<T>::at(i);
	}
}

// at(i) will throw out_of_range exception

