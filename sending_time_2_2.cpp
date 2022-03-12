#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <filesystem>
#include <chrono>
#include <thread>

using namespace std;

void wait()
{
	while (true)
	{
		time_t now_t = time(nullptr);
		tm* now = localtime(&now_t);
		if (now->tm_sec % 2 == 0)
			break;
		else
			this_thread::sleep_for(10ms);
	}
}

int main()
{
	while (true)
	{
		time_t now_t = time(nullptr);
		tm* now = localtime(&now_t);
		if (now->tm_sec % 20 == 0)
			break;
		else
			this_thread::sleep_for(6ms);
	}
	cout << "START" << endl;
	while (true)
	{
		wait();
		this_thread::sleep_for(500ms);
		char result;
		filesystem::exists("D:\\secret.txt") ? result = '1' : result = '0';
		cout << result;
		this_thread::sleep_for(1s);
		if (!filesystem::exists("D:\\stop.txt"))
			break;
	}
}