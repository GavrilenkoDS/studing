#include <iostream>
#include <cmath>
#include <vector>
#include <list>

using namespace std;

class line {
	line(double k, double c);//y=kx+c
	double k;
	double c;
	line(pair<double, double>, pair<double, double>);//dot plus vector
	pair<double, double> dot;
	pair<double, double> vect;
};

class solution {
	//data inputed
	int M;
	double* stream1;
	double* stream2;
	double epsilon;
	//data calculated
	list<double> Ind;//list for output
	double q;//data compression coefficient
	

	//constructor
	solution(int M_, double* stream1_, double* stream2_, double epsilon_) :
		M(M_), stream1(stream1_), stream2(stream2_), epsilon(epsilon_) {};//TODO try throw on epsilon
	//func
	void output();
	double R0(int, int);
	double R1(int, int);
	double max_from_a_to_b(int a, int b, double function(double* x,double* y));//to do max abs function 
};