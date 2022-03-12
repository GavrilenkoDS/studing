#include <iostream>

const int N = 5;
template<int n>
class Fib
{
	enum { value = Fib<n - 1>::value + Fib<n - 2>::value };
};
template<>
class Fib<1>
{
	enum { value = 1 };
};
template<>
class Fib<2>
{
	enum { value = 1 };
};
int A[Fib<N>::value];

int main() {
	std::cout << A;
}