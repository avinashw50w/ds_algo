/*You are given an array A of size N. Your task is to find the minimum number of
operations needed to convert the given array to 'Palindromic Array'.
Palindromic Array:
[23,15,23] is a ‘Palindromic Array’ but [2,0,1] is not.
The only allowed operation is that you can merge two adjacent elements in the
array and replace them with their sum.*/

int solve(vector<int> a) {
	int n = a.size();
	int ans = 0;
	for (int i = 0, j = n - 1; i <= j; ) {
		if (a[i] == a[j]) i++, j--;
		else if (a[i] > a[j]) {
			j--;
			a[j] += a[j + 1];
			ans++;
		}
		else {
			i++;
			a[i] += a[i + 1];
			ans++;
		}
	}
	// validate if palindrome
	for (int i = 0, j = n - 1; i < j; ) {
		if (a[i++] != a[j--]) {
			ans = -1;
			break;
		}
	}

	return ans;
}