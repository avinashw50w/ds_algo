#include <bits/stdc++.h>
using namespace std;

// destructors are called when the object is deleted
class Person {
private:
	string name;
	int age;

public:

	Person(string name, int age) {
		this->name = name;
		this->age = age;

		cout << "contructor called" << endl;
	}

	void introduce() {
		cout << "name: " << name << endl;
		cout << "age: " << age << endl;
	}

	~Person() {
		cout << "destructor called" << endl;
	}
};


int main() {

	Person *avi = new Person("avinash", 24);
	avi->introduce();

	// after deleting the object the destructor is called
	delete avi;

	// But here the destructor is called without deleting the object 
	// because the object is not allocated memory dynamically
	Person noki("Noki", 23);
	noki.introduce();
}