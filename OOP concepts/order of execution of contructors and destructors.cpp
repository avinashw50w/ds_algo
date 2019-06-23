#include <bits/stdc++.h>
using namespace std;

class Person {
public:

	Person() {
		cout << "Person Contructor called" << endl;
	}

	~Person() {
		cout << "Person Destructor called" << endl;
	}
};

class Student: public Person {
public:

	Student() {
		cout << "Student Contructor called" << endl;
	}

	~Student() {
		cout << "Student Destructor called" << endl;
	}
};

int main() {

	Student avi;
}