#include <iostream>
#include <string>

using namespace std;

class building {
public:
	string name;
	double space;
	double base_cost;
	int occupant_num;

	building() {
		cout << "building without parameters was created";
	}
	
	building(string name1="", double space1=0, double base_cost1 = 0, int occupant_num1 = 0)
		:name(name1),space(space1),base_cost(base_cost1),occupant_num(occupant_num1) 
	{	
	}

	void output() {
		cout << name << endl << "space:" << space << "\nbase cost:" << base_cost << "\noccupant num:" << occupant_num;
	}

};

class house : public building {
public:
	string material;
	bool is_rent;
	double rent_cost;

	house(string name1="", double space1=0, double base_cost1=0, int occupant_num1=0,string material1="",bool is_rent1=0,double rent_cost1=0)
		:building(name1,space1,base_cost1,occupant_num1),material(material1),is_rent(is_rent1),rent_cost(rent_cost1) 
	{
	}

	double life_cost() {
		double result = 0;
		return result;
	}
};


int main() {

	h.output();
	
}
