template<typename Container, typename Value>
Value sum(const Container& c, Value v)
{
	for(auto x: c)
		v+=x;
	return v;
}

void user(Vector<int>& vi, std::list<double>& lst, std::vector<complex<double>>& vc)
{
	int x = sum(vi,0);
	double d = sum(vi,0);
	double dd = sum(lst,0);
	auto z = sum(vc,complex<double>{});
}