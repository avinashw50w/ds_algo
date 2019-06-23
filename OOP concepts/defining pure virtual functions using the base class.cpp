#include <iostream>
using namespace std;

// we can define a pure virtual function either in the derived class or using the :: operator on the Abstract class
class Person {
public:

	// a pure virtual function
	virtual void intro() = 0;
};

void Person::intro() {
	cout << "Person" << endl;
}

class Student: public Person {
public:

	void intro() {
		cout << "Student" << endl;
		Person::intro();
	}
};

int main() {

	Student avi;
	avi.intro();
}