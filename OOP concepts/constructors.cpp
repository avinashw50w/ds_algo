#include <bits/stdc++.h>
using namespace std;

// contructors are functions which are called immediately after the object is instantiated.
// a contructor has no return type and does not return anything. It can only take parameters
// we can create as many contructors as we want with different set of parameters but
// two contructors should not have the same parameters
// THIS IS ALSO CALLED as overloading the class contructors
class Person {
private:
	string name;
	int age;

public:
	Person() {
		name = "avinash";
		age = 24;
	}

	Person(string name) {
		this->name = name;
		this->age = 24;
	}

	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}

	void introduce() {
		cout << "name: " << name << endl;
		cout << "age: " << age << endl;
	}
};


int main() {

	Person avi;
	avi.introduce();

	Person noki("NOKI");
	noki.introduce();

	Person madan("MADAN", 5);
	madan.introduce();
}