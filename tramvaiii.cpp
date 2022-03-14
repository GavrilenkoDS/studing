#include <iostream>
#include <set>
#include <map>
using namespace std;

bool f(const char* s)
{
	set<int> states;

	char i = -1;

	states.insert(0);
	while (s[++i] != '\0') {
		set<int> ns;
		set<int>::iterator j;
		for (j = states.begin(); j != states.end(); j++) {
			switch (*j) {
				case 0:
					switch (s[i]) {
						case '0':
							ns.insert(0);
							ns.insert(1);
							break;
						case '1':
							ns.insert(0);
							
					}
					break;
				case 1:
					switch (s[i]) {
						case '0':
							ns.insert(5);ns.insert(2);break;
						case '1':
							ns.insert(2);
					}
					break;
				case 2:
					switch (s[i]) {
						case '0':
							ns.insert(3);break;
						case '1':
							ns.insert(3);
					}
					break;
				case 3:
					switch (s[i]) {
						case '0':
							ns.insert(4);break;
						case '1':
							ns.insert(4);
					}
					break;
				case 4:
					switch (s[i]) {
						case '0':
							ns.insert(1);break;
						case '1':
							ns.insert(1);
					}
					break;
				case 5:
					switch (s[i]) {
						case '0':
							ns.insert(5);break;
						case '1':
							ns.insert(5);
					}
					break;
				
			}
		}
		states = ns;
	}
	return states.count(5) == 1;
}

int main()
{
	cout<<f("011110");
	return 0;
}
