#include <iostream>

template <class T> swap1(T& a, T& b)
{
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}

int main() {
	 int a = 10;
	 int& p = a;
     int b = 20;
    swap1<int> (p, b);
    std::cout << b;
}