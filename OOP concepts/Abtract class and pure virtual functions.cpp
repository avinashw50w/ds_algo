#include <iostream>
using namespace std;

// An abtract class has atleast one pure virtual function
// a pure virtual function has no definition in the abstract class
// but its derived class must have an implementation of that pure virtual function
// NOTE: we cannot instantiate an object of the Abstract class
class Person {
public:

	// a pure virtual function
	virtual void intro() = 0;
};

class Student: public Person {
public:

	void intro() {
		cout << "Student" << endl;
	}
};

int main() {

	Student avi;
	avi.intro();
}