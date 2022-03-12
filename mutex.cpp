#include <iostream>
#include <vector>
#include <mutex>
#include <random>
#include <thread>
#include <cstdlib>
#include <windows.h>
using namespace std;

int object; 
bool flag = false; 
bool work1 = true, work2 = true;
vector<int> v1, v2;
mutex m;
void factory(){
	while (work1)
		if (flag){
			Sleep(2);} 
				else {
					m.lock();
					object = rand();
					v1.push_back(object);
					flag=true;
					m.unlock();
			}
}
void consumer(){
	while(work2)
		if (!flag){
			Sleep(2);{
				else {
					m.lock();
					v2.push_back(object);
					flag=false;
					m.unlock();
				}
}

void check_all(){
	thread f1(factory);
	thread f2(factory);
	thread c1(consumer);
	thread c2(consumer);
	thread c3(consumer);
	f1.join();
	f2.join();
	c1.join();
	c2.join();
	c3.join();
	sleep(1);
	work1=false;
	work2=false;
	if (v2.size()>v1.size())
		cout<<"error";
}

int main(){
	check_all();
	return 0;
}
