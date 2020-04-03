// convert a number n in base b to its decimal equivalent  //

#include <iostream>
using namespace std;

// by traversing from right to left
int toDecimal(string a,int b){
	int res=0, multiplier=1, n=a.size()-1;
	while(n--){
		res +=  (a[n] - '0') * multiplier;
		multiplier *= b;
	}
	return res;
}

// by traversing from left to right
int toDecimal2(string a, int b) {
	int n = a.size(), res = 0;
	for (int i = 0; i < n; ++i) {
		res += (res*b) + (a[i]-'0');
	}
	return res;
}

/*more general for base >= 10*/
int convert(string a, int b) {
	int mul = 1, res = 0;
	int n = a.length() - 1;

	while(n--) {
		if('0' <= a[n] && a[n] <= '9')
			res += (a[n] - '0') * mul;
		else if('a' <= a[n] && a[n] <= 'z')
			res += (a[n] - 'a' + 10) * mul;
		else if('A' <= a[n] && a[n] <= 'Z')
			res += (a[n] - 'A' + 10) * mul;

		mul *= b;
	}

	return res;
}



// convert a decimal number n to a number in base b where (2<=b<=20)  //

string toBase_b(int n,int b){
	string chars = "0123456789ABCDEFGHIJ";
	string res = "";
	
	while(n){
		res = chars[n%b] + res;
		n /= b;
	}
	return res;
}
