#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <filesystem>
#include <ctime>
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
	ofstream file("D:\\stop.txt");
	file << "text";
	file.close();
	string input = "101101";
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
	for (int i = 0; i < input.size(); i++)
	{
		wait();
		if (input[i] == '1')
		{
			ofstream secret("D:\\s.txt");
			secret << "text";
			secret.close();
			this_thread::sleep_for(1s);
			remove("D:\\s.txt");
		}
		else
			this_thread::sleep_for(1s);
	}
	remove("D:\\stop.txt");
}