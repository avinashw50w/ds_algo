#include <bits/stdc++.h>
using namespace std;

// destructors are called when the object is deleted
class Person {
private:
	string *name;
	int *age;

public:

	Person(string iname, int iage) {
		name = new string;
		age = new int;
		*name = iname;
		*age = iage;

		cout << "contructor called" << endl;
	}

	void introduce() {
		cout << "name: " << *name << endl;
		cout << "age: " << *age << endl;
	}

	// here the destructor is releasing all the allocated resources(which is a string name and an int age)
	~Person() {
		delete name;
		delete age;
		cout << "destructor called" << endl;
	}
};


int main() {

	Person *avi = new Person("avinash", 24);
	avi->introduce();

	// after deleting the object the destructor is called
	delete avi;
}