/*Find zeroes to be flipped so that number of consecutive 1’s is maximized
Given a binary array and an integer m, find the position of zeroes flipping which creates maximum number of consecutive 1s in array.

Examples:

Input:   arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1}
         m = 2
Output:  5 7
We are allowed to flip maximum 2 zeroes. If we flip
arr[5] and arr[7], we get 8 consecutive 1's which is
maximum possible under given constraints */

/* Just find the maximum sized window with <= m zeroes. */

void solve(int a[], int n, int m) {

	int maxLen = 0;
	int zeroes = 0, l = 0, start, end;

	for(int i = 0; i < n; ++i) {

		while(zeroes > m) {
			if(a[l++] == 0) zeroes--;
		}

		if(a[i] == 0) zeroes++;

		if(i-l+1 > maxLen) {
			maxLen = i-l+1;
			start = l;
			end = i;
		}
	}

	for(int i = start; i <= end; ++i) 
		if(a[i] == 0) cout << i << " ";
}