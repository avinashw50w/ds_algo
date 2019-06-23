/*Example: 23 (00..10111)
1) Get count of all set bits at odd positions (For 23 it’s 3).
2) Get count of all set bits at even positions (For 23 it’s 1).
3) If difference of above two counts is a multiple of 3 then number is also a multiple of 3.*/

#include <iostream>
using namespace std;

int check(int n) {
	int odd_cnt = 0;
	int even_cnt = 0;

	if(n < 0) n = -n;
	if(n == 0) return 1;
	if(n == 1) return 0;

	while(n) {
		if(n & 1) odd_cnt++;

		n >>= 1;

		if(n & 1) even_cnt++;

		n >>= 1;
	}

	return check(abs(odd_cnt - even_cnt));
}