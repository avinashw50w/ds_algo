#include <bits/stdc++.h>
using namespace std;

class Person {
public:
	void introduce() {
		cout << "I am Person." << endl;
	}
};

class Student: public Person {
public:
	void introduce() {
		cout << "I am Student." << endl;
	}
};

int main() {
	Student avi;
	avi.introduce();
	avi.Person::introduce();
}