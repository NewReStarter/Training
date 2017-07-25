int x;
decltype(x) y; // make y the same type as x

decltype(x + y) xpy; // make xpy the same type as x + y
xpy = x + y;

//auto deduction of return type
template<class T1, class T2>
auto gt(T1 x, T2 y) -> decltype(x + y)
{
...
return x + y;
}
