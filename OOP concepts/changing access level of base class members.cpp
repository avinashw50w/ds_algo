#include <bits/stdc++.h>
using namespace std;

class Person {

protected:
	string name;

public:

	void setName(string name) {
		this->name = name;
	}
};

class Student: private Person {
public:
	// due ot private inheritance all the protected and public members of the class Person 
	// has become the private members of the Student class
	// but here the name property which was private has become a public member of this class, 
	// since it is defined under public access specifier
	using Person::name;

	Student() {
		name = "Avinash";
	}

	void introduce(){
		cout << "Name: " << name << endl;
	}
};

int main() {

	Student avi;
	// we cannot write avi.setName() because the setName has become a protected method of the class Student
 	avi.introduce();
}