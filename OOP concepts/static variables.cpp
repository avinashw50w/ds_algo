#include <bits/stdc++.h>
using namespace std;

class Person {

public:
	static string name;

	Person() {
		this->name = "Noki";
	}
	
	void introduce();
};

string Person::name = "avinash";

void Person::introduce() {
	cout << Person::name << endl;
}

int main() {

	cout << Person::name << endl;


	// after creating an object the contructor will be called and it will set the name to noki
	Person avi;

	avi.introduce();
}