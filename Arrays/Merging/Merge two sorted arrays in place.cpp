/*merge two sorted arrays using O(1) extra space
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