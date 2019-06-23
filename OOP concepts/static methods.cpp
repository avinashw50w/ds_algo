#include <bits/stdc++.h>
using namespace std;

// the static methods of a class can be called using :: operator without even intiantiating an object of that class
class Person {

public:
	static string name;

	Person() {
		this->name = "Noki";
	}
	
	static void introduce() {
		cout << "Name: " << name << endl;
	}
};

string Person::name = "avinash";

int main() {

	cout << Person::name << endl;

	Person::introduce();
}