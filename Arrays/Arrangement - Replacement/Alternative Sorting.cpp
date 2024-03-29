/*Alternative Sorting

Given an array of integers, print the array in such a way that the first element is first maximum and second element is 
first minimum and so on.

Examples:

Input : arr[] = {7, 1, 2, 3, 4, 5, 6}
Output : 7 1 6 2 5 3 4
*/

void solve(int a[], int n) {
	sort(a, a+n);

	int i = 0, j = n-1;

	while(i < j) {
		cout << a[j--] << " ";
		cout << a[i++] << " ";
	}

	if(n&1) // in case of odd no of elements print the middle leftout no at the last
		cout << a[i];
}

// ---------------------------------------

void solve(vector<int> a) {
	sort(a.begin(), a.end());
	int n = a.size(), i, j;
	for (i = 0, j = n - 1, i < j; ++i, --j) {
		cout << a[i] << " ";
		cout << a[j] << " ";
	}

	if (n & 1) {
		cout << a[i];
	}
}

// ---------------------------------------
void solve(vector<int> &a) {
	sort(a.begin(), a.end());
	int n = a.size(), i, j, k = 0;
	for (i = 0, j = n - 1, i < j; ++i, --j) {
		a[k++] = a[j];
		a[k++] = a[i];
	}

	if (n & 1) {
		a[k++] = a[i];
	}
}