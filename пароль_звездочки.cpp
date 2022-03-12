#include <iostream>
#include <string>

using namespace std;

int main/*4*/(){
	string a;
	getline(cin,a);
	string p = "password:";
	int pos=0;
	while (a.find("p")!= string::npos && a.find("p")>pos){
		pos=a.find("p");
		for (int i=pos+9;i<pos+17;i++)
			a[i]='*';
		//	cout<<a;
	}
	cout<<a;
}
