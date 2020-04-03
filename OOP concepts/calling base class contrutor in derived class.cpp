#include <bits/stdc++.h>
using namespace std;

class Person {
protected:
	int age;

public:

	Person(int age) {
		this->age = age;
		cout << "Person Contructor called" << endl;
	}
};

class Student: public Person {
public:

	Student(int age = 24) : Person(age) {
		cout << "Student Contructor called" << endl;
		cout << "Age: " << age << endl;
	}
};

int main() {

	Student avi;
}