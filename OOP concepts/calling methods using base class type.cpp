#include <bits/stdc++.h>
using namespace std;

class Person {

public:

	void intro() {
		cout << "Person" << endl;
	}
};

class Student: public Person {
public:

	void intro() {
		cout << "Student" << endl;
	}
};

void who(Person &p) {
	p.intro();
}

int main() {

	Person p;
	Student s;

	who(p);
	who(s);
}