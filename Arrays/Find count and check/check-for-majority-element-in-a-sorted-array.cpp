/*Check for Majority Element in a sorted array
Question: Write a C function to find if a given integer x appears more than n/2 times in a sorted array of n integers.

eg. 2, 5, 7, 7, 7, 7, 8, 9. For x = 7, find its first occurence i in the array and then check a[i+n/2] , if both are same then return true. */

bool isMajority(int a[], int n, int x) {

	int p = firstOccurence(a, n, x);

	if (p == -1) return false;

	if (p + n / 2 < n and a[p + n / 2] == x) return true;

	return false;
}

int firstOccurence(int a[], int n, int x) {
	int l = 0, r = n - 1, m;

	while (l <= r) {
		m = (l + r) >> 1;
		if (x <= a[m]) r = m;
		else l = m + 1;
	}

	return l;
}