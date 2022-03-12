#include <iostream>
#include <cstdlib>
#include <random>

class getrand {
	const int N = 1000000;
	const int a = 0;
	const int b = 100;
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
			std::cout << i << " - " << q[i] / 1000000.0<<std::endl; prints(q[i] / 1000); std::cout << std::endl;
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

class rand_stars {
	bool p[100][100];
	const int a = 0;
	const int b = 100;
	std::minstd_rand g1;
	std::mt19937 g2;
	std::ranlux48 g3;
	std::knuth_b g4;
	std::random_device g5;
	std::uniform_int_distribution<int> distrib;
public:
	rand_stars() :distrib(a, b)
	{};
	void make_matrix(int type_of_rand) {
		switch(type_of_rand)
			case 1:
				for (int i = 0; i < 100; i++)
					for (int j < 100; j++)
						p[i][j] = ((int)(rand() / (1.0 + RAND_MAX) * 2));
				break;
			case 2:
				for (int i = 0; i < 100; i++)
					for (int j < 100; j++)
						p[i][j] = (rand() % 2);
				break;
			case 3:
				for (int i = 0; i < 100; i++)
					for (int j < 100; j++)
						p[i][j] = (distrib(g1));
			case 4:
				for (int i = 0; i < 100; i++)
					for (int j < 100; j++)
						p[i][j] = (distrib(g2));
			case 5:
				for (int i = 0; i < 100; i++)
					for (int j < 100; j++)
						p[i][j] = (distrib(g3));
			case 6:
				for (int i = 0; i < 100; i++)
					for (int j < 100; j++)
						p[i][j] = (distrib(g4));
			case 7:
				for (int i = 0; i < 100; i++)
					for (int j < 100; j++)
						p[i][j] = (distrib(g5));
	}
	void draw() {
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++)
				p[i][j] == 1 ? std::cout << "*" : std::cout << " ";
			std::cout << std::endl;
		}
	}
};

int test_for_task_1() {
	int type_of_gen = 1;
	std::cin >> type_of_gen;
	getrand test;
	test.make(type_of_gen);
	std::cout << std::endl;
	test.print();
	std::cout << std::endl << test.disp()<<std::endl;
	system("pause");
	return EXIT_SUCCESS;
}
int main() {
	rand_stars a;
	a.make_matrix(1);
	a.draw();
}
