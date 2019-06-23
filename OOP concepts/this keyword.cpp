#include <bits/stdc++.h>
using namespace std;

// this is a pointer which contains the address of the object
class Person {
private:
	int age;
public:
	void setAge(int age) {
		this->age = age; // if the name of the parameter is the same as the name of the property, then we have to use this keyword
	}

	void showAge() {
		cout << age << endl;
	}
};


int main() {
	Person avi;
	avi.setAge(24);
	avi.showAge();
}