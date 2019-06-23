#include <bits/stdc++.h>
using namespace std;

class Person {

public:

	virtual void intro() {
		cout << "Person" << endl;
	}
};

class Student: public Person {
public:

	void intro() {
		cout << "Student" << endl;
	}
};

class Teacher: public Person {
public:

	void intro() {
		cout << "Teacher" << endl;
	}
};

void who(Person &p) {
	p.intro();
}

int main() {

	Person p;
	Student s;
	Teacher t;

	who(p);
	who(s);
	who(t);
}