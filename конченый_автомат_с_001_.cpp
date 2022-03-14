#include <iostream>
#include <set>
#include <map>
using namespace std;

bool f(const char* s)
{
	set<int> states; 

	char i = -1;
	
	states.insert(0); 
	while (s[++i] != '\0')
	{
		set<int> ns;
		set<int>::iterator j;
		for (j = states.begin(); j != states.end(); j++) {
			switch (*j) {
			case 0: switch (s[i]) {
			case '0': ns.insert(0); ns.insert(1); 
			case '1': ns.insert(0);
			}
				break;
			case 1: switch (s[i]) {
			case '0':break;
			case '1':ns.insert(2);
			}
				break;
			case 2: switch (s[i]) {
			case '0':break;
			case '1':ns.insert(3);
			}
				break;
			case 3: switch (s[i]) {
			case '0':ns.insert(3);
			case '1':ns.insert(3);
			}
		}
			
	
		}
			cout<<states.count(0)<<states.count(1)<<states.count(2)<<states.count(3)<<'\n';
		states = ns;
	}
	return states.count(3) ;
}

int main() {
	cout<<f("011");//01010101001100101010
	return 0;
}
