#include <bits/stdc++.h>
using namespace std;

// by using protected inheritance, all the public and protected members of the base class becomes 
// the protected members of the derived class
class Person {

protected:
	string name;

public:

	void setName(string name) {
		this->name = name;
	}
};

class Student: protected Person {
public:
	Student() {
		setName("avinash");
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