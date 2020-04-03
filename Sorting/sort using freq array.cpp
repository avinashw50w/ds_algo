/*this works if array elements are < 1e6 
works in O(max{a[i]}) */

int f[MAXN];
int maxx = INT_MIN;

// calculate the freq of each of the array elements
// also find the maximum no in the array
for(int i = 0; i < N; ++i) {
	f[a[i]]++;
	maxx = max(maxx, a[i]);
}

// now sort 
for(int i = 0; i < maxx; ++i) {
	int cnt = f[i];

	for(int j = 0; j < cnt; ++j)
		cout << i << " ";
}

