/*merge two sorted arrays using O(1) extra space with O(n+m) time
IDEA: two numbers can be represented as a single number
choose a no N greater than both a and b, then do a = a*N + b,
to get the original value do a/N and to get the other one do a%N
*/

void merge(vector<int> &a, vector<int> &b) {
	int n = a.size(), m = b.size();
	int i = 0, j = 0, k = 0;
	int M = 0;
	for (int e : a) M = max(M, e);
	for (int e : b) M = max(M, e);
	M++;

	while (i < n and j < m and k < (n + m)) {
		// get the original number
		int x = a[i] % M;
		int y = b[j] % M;
		if (x <= y) {
			if (k < n) a[k] += x * M;
			else b[k - n] += x * M;
			i++;
			k++;
		}
		else {
			if (k < n) a[k] += y * M;
			else b[k - n] += y * M;
			j++;
			k++;
		}
	}

	while (i < n) {
		int x = a[i] % M;
		if (k < n) a[k] += x * M;
		else b[k - n] += x * M;
		i++;
		k++;
	}

	while (j < m) {
		int y = a[j] % M;
		if (k < n) a[k] += y * M;
		else b[k - n] += y * M;
		j++;
		k++;
	}

	for (int &e : a) e /= M;
	for (int &e : b) e /= M;

	return;
}

///////////////////////////////////////////
// the above solution can have overflow issue
// so below algo takes O((n+m)*log(n+m)) time with O(1) extra space
/* Merge two sorted arrays of size n and m respectively in O(n+m) without using extra space
The idea: We start comparing elements that are far from each other rather than adjacent.
For every pass, we calculate the gap and compare the elements towards the right of the gap. Every pass, the gap reduces to the ceiling value of dividing by 2.
First example:
a1[] = {3 27 38 43},
a2[] = {9 10 82}
Start with
gap =  ceiling of 7/2 = 4
[This gap is for whole merged array]
3 27 38 43   9 10 82
3 27 38 43   9 10 82
3 10 38 43   9 27 82

gap = 2:
3 10 38 43   9 27 82
3 10 38 43   9 27 82
3 10 38 43   9 27 82
3 10 9 43   38 27 82
3 10 9 27   38 43 82

gap = 1:
3 10 9 27   38 43 82
3 10 9 27   38 43 82
3 9 10 27   38 43 82
3 9 10 27   38 43 82
3 9 10 27   38 43 82
3 9 10 27   38 43 82
Output : 3 9 10 27 38 43 82
*/

void merge(vector<int> &a1, vector<int> &a2) {
	int n = a1.size(), m = a2.size();

	int gap = (n + m + 1) / 2; // ceil((n+m)/2)
	int i, j;

	for (int gap = (n + m) / 2; gap; gap /= 2) {

		for (i = 0; i + gap < n; ++i)
			if (a1[i] > a1[i + gap])
				swap(a1[i], a1[i + gap]);

		for (j = gap > n ? gap - n : 0; i < n and j < m; ++i, ++j)
			if (a1[i] > a2[j])
				swap(a1[i], a2[j]);

		for (int j = 0; j + gap < m; ++j)
			if (a2[j] > a2[j + gap])
				swap(a2[j], a2[j + gap]);
	}

	// now a1 + a2 are sorted, print them separately
	for (int e : a1) cout << e << " ";
	for (int e : a2) cout << e << " ";
}