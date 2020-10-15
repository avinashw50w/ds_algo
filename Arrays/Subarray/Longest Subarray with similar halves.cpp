/*Given an array a of size n, containing only 1 and 2. Find the longest even length subarray such that
each half contains equal elements .
eg. 111222, 11112222

IDEA : keep calculating the length of the consecutive equal elements until
another element is found. Then keep updating the length by taking the minimum
of the current element length and the previous element length
*/


int solve(vector<int> arr) {
	int n = arr.size();
	int l = 0, currCnt = 0, prevCnt = 0, a = 0, b = 0;
	for (int i = 0; i < n; ++i) {
		a = arr[i];
		if (a == b) currCnt++;
		else {
			prevCnt = currCnt;
			currCnt = 1;
			b = a;
		}

		l = max(l, min(prevCnt, currCnt));
	}

	return 2 * l;
}