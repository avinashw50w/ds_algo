#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> a = {1,4,45,6,10,8};

	int n = 16;

	int f[100] = {0};

	for(int i=0; i<a.size(); ++i) {
		int tmp = n - a[i];
		if(tmp >= 0 and f[tmp]) cout << a[i] << " " << tmp << endl;
		f[a[i]] = 1;
	}
}

// if asked inplace then binary search the value of n - a[i], for every i
// or sort the array, then 
sort(a,a+arr_size);
int i = 0, j = arr_size-1;
while(i < j) {
	if(a[i] + a[j] == n) cout << a[i] << " " << a[j] << endl;
	else if(a[i]+a[j] < n) i++;
	else j--;
}
