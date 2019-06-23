#include <bits/stdc++.h>
using namespace std;

class Person {
private:
	int age;
public:
	int height;
	void setAge(int age) {
		this->age = age;
	}

	void showAge() {
		cout << "Age: " << age << endl;
	}

	void showHeight() {
		cout << "Height: " << this->height << endl;
	}
};


int main() {
	Person avi;
	avi.setAge(24);
	avi.showAge();
	// avi.age = 24 will show error because age is private

	Person *noki = new Person();
	noki->height = 6;
	noki->setAge(23);
	noki->showAge();
	noki->showHeight();
}