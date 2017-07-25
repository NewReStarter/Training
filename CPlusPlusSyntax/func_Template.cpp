template <typename T>
void swap(T &a, T &b)
{
  T tmp = b;
  b = a;
  a = tmp;
}

//template overload

template <typename T> // original template
void Swap(T &a, T &b);
template <typename T> // new template
void Swap(T *a, T *b, int n); //swap element of arrays


// non template function prototype
void Swap(job &, job &);
// template prototype
template <typename T>
void Swap(T &, T &);
// explicit specialization for the job type
template <> void Swap<job>(job &, job &);



template void Swap<int>(int, int); // explicit instantiation
template <> void Swap<int>(int &, int &); // explicit specialization
template <> void Swap(int &, int &); // explicit specialization


