// convert a number n in base b to its decimal equivalent  //

#include <iostream>
using namespace std;

// by traversing from left to right
int toDecimal2(string a) {
	int n = a.size(), res = 0;
	for (int i = 0; i < n; ++i) {
		res = (res * 10) + (a[i] - '0');
	}
	return res;
}

// by traversing from right to left
int toDecimal(string a, int b) {
	int res = 0, multiplier = 1, n = a.size() - 1;
	while (n--) {
		res +=  (a[n] - '0') * multiplier;
		multiplier *= b;
	}
	return res;
}

/*more general for base >= 10*/
int convert(string a, int b) {
	int mul = 1, res = 0;
	int n = a.length() - 1;

	for (int i = 0; i < n; ++i) {
		if ('0' <= a[n] && a[n] <= '9') res = res * b + (a[i] - '0');
		else if ('a' <= a[n] && a[n] <= 'z') res = res * b + (10 + (a[i] - 'a'));
		else if ('A' <= a[n] && a[n] <= 'Z') res = res * b + (10 + (a[i] - 'A'));
	}

	return res;
}



// convert a decimal number n to a number in base b where (2<=b<=20)  //

string toBase_b(int n, int b) {
	string chars = "0123456789ABCDEFGHIJ";
	string res = "";

	while (n) {
		res = chars[n % b] + res;
		n /= b;
	}
	return res;
}
