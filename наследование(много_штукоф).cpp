#include <iostream>

template <typename T>
class B1 {
private:
	T a;
public:
	B1(T _a = 0) :a(_a) {};
	void show() { std::cout << a; };
	~B1() {};
};
template <typename T>
class B2 {
private:
	T a;
public:
	B2(T _a = 0) :a(_a) {};
	void show() { std::cout << a; };
	~B2() {};
};

template <typename T>
class D1 :public B1<T>, private B2<T> {
private:
	T a;
public:
	D1(T a=0) :a(a) {};
	void show() { std::cout << a; };
	~D1() {};
};

template <typename T>
class D2 : private D1<T> {
private:
	T a;
public:
	D2(T a = 0) :a(a) {};
	void show() { std::cout << a; };
	~D2() {};
};

template <typename T>
class D3 : public D2<T> {
private:
	T a;
public:
	D3(T a = 0) :a(a) {};
	void show() { std::cout << a; };
	~D3() {};
};


int main() {
	B1<int> b1(1);
	B2<int> b2(2);
	D1<int> d(3);
	D3<int> a(10);
	a.D2<int>::show();
	std::cout << std::endl;
	a.show();
}