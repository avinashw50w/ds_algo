#include <iostream>
using namespace std;

int Count_trailing_zeroes(int n) {
	int cnt = 0, i = 5;
	
	while(n >= 1) {
		cnt += n/i;
		i *= 5;
	}

	return cnt;
}