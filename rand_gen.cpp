#include <iostream>
#include <cstdlib>
#include <random>


class gn {
public:
	typedef unsigned int result_type;
	explicit gn() {};
	static result_type min() { return 0; };
	static result_type max() { return 100; };
	result_type operator()() {
		return (rand() % (max() - min() + 1) + min());
	};
};


class getrand {
	const int N = 1000000;
	const int a = 0;
	const int b = 100;
	gn g0;
	std::minstd_rand g1;
	std::mt19937 g2;
	std::ranlux48 g3;
	std::knuth_b g4;
	std::random_device g5;
	std::uniform_int_distribution<int> distrib;
	//for getting 1000000 numbers from 0 to 100
	int q[101] = { 0 };
public:
	getrand() :distrib(a, b)
	{};
	void make(int type_of_rand) {
		switch (type_of_rand) {
		case 10:
			for (int i = 0; i < N; i++)
				q[distrib(g0)]++;
			break;
		case 1:
			for (int i = 0; i < N; i++)
				q[((int)(rand() / (1.0 + RAND_MAX) * (b - a + 1)) + a)]++;
			break;
		case 2:
			for (int i = 0; i < N; i++)
				q[(rand() % (b - a + 1) + a)]++;
			break;
		case 3:
			for (int i = 0; i < N; i++)
				q[distrib(g1)]++;
			break;
		case 4:
			for (int i = 0; i < N; i++)
				q[distrib(g2)]++;
			break;
		case 5:
			for (int i = 0; i < N; i++)
				q[distrib(g3)]++;
			break;
		case 6:
			for (int i = 0; i < N; i++)
				q[distrib(g4)]++;
			break;
		case 7:
			for (int i = 0; i < N; i++)
				q[distrib(g5)]++;
		}
	};

	void prints(int num_of_s) {
		for (int i = 0; i < num_of_s; i++)
			std::cout << "*";
	};
	void print() {
		for (int i = 0; i < 101; i++) {
			std::cout << i << " - " << q[i] / 1000000.0 << std::endl; prints(q[i] / 1000); std::cout << std::endl;
		}
	};
	double disp() {
		double ans = 0;
		double c_ = 0;
		for (int i = 0; i < 101; i++)
			(c_ += q[i] / 1000000.0);
		c_ /= 101;
		for (int i = 0; i < 101; i++)
			(ans += (q[i] / 1000000.0 - c_) * (q[i] / 1000000.0 - c_));
		ans /= 100;
		return ans;
	}
	~getrand() {};
};


int test_for_task_1() {
	int type_of_gen = 1;
	std::cin >> type_of_gen;
	getrand test;
	test.make(type_of_gen);
	std::cout << std::endl;
	test.print();
	std::cout << std::endl << test.disp() << std::endl;
	system("pause");
	return EXIT_SUCCESS;
}
int main() {
	test_for_task_1();
}