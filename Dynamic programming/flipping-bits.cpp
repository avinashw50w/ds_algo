/* Flip a subarray to obtain the largest number of 1s in the whole array. You can flip only once. */
/* Sol: Simply find the subarray with the maximum value of (no of zeroes - no of ones). For doing that replace
   all 0s with 1 and all 1s with -1, and find the maximum sum subarray. */
#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[] = {1,0,1,0,0,1,0,1};

	int n = sizeof(a)/sizeof(a[0]);

	int idx, start = 0, end = 0, sum = 0;

	for (int i = 0; i < n; ++i) {
		sum += a[i];
		a[i] = a[i] == 0 ? 1 : -1;
	}

	int prefix = 0, maxx = 0;

	for (int i = 0; i < n; ++i) {
		prefix += a[i];
		if(prefix < 0) {
			prefix = 0;
			idx = i+1;
		}
		if(maxx < prefix) {
			maxx = prefix;
			start = idx;
			end = i;
		}
	}

	cout << (sum + maxx) << " from " << start << " to " << end << endl;

}
