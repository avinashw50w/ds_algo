#include <bits/stdc++.h>
using namespace std;

class Person {

public:
	string name = "Noki";
	
	void introduce();
};

void Person::introduce() {
	cout << Person::name << endl;
}

// setting the name property using scope resolution will not work here. For that we need to set the name as a static variable
// string Person::name = "avinash" will not work
int main() {
	Person avi;
	avi.name = "avinash";
	avi.introduce();
}