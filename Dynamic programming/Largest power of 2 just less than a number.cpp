#include <bits/stdc++.h>
using namespace::std;

int func(int n) {
	int x = 0;
	
	while(n) {
		n >>= 1;
		x++;
	}
	return x;
}

int main() {
	int m, x;

	cout << func(9) << endl;
}