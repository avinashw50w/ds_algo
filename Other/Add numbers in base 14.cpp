#include <iostream>
using namespace std;

int getNum(char c) {
	if(c>='0' and c<='9') return (c-'0');
	if(c>='A' and c<='D') return (c-'A'+10);

	assert(0);
}

char getNumeral(int n) {
	if(n>=0 and n<=9) return (n+'0');
	if(n>=10 and n<=14) return (n-10 + 'A');
}
void Add(string n1, string n2) {
	int l1 = n1.size();
	int l2 = n2.size();

	bool carry = 0;
	string res = "";
	if(l1 != l2) { cout <<"doesn't support\n"; return; }

	for(int i=l1-1; i>=0; i--) {
		int num1 = getNum(n1[i]);
		int num2 = getNum(n2[i]);

		int x = carry + num1 + num2;
		if(x >= 14) carry = 1, x -= 14;
		else carry = 0;

		res += getNumeral(x);
	}
}