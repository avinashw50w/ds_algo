/*Find the next smallest palindrome
IDEA: 
case 1: odd length palindrome
6248357 - middle ele = 8, left middle = 4, right middle = 3
6248357	- left middle > right middle
		copy the mirror image of left half to the right half, 6248426
6238457	- left middle < right middle
		increment the middle ele by 1 and copy the mirror image of left half to right half
		6239326
6299357	- if middle ele is 9 and left middle < right middle, increment it by 1 and keep adding 
		the carry to the left side.
		once done, copy the mirror image of left half to right half
		6300036

case 2: even length palindrome
*/
void solve(vector<int> &a) {
	int n = a.size();
	bool leftSmaller = false;
	int mid = n / 2;
	int i = mid - 1;
	int j = n & 1 ? mid + 1 : mid;
	while (i >= 0 and j < n and a[i] == a[j]) i--, j++;

	if (i < 0 or a[i] < a[j]) leftSmaller = true;

	while (i >= 0) {
		a[j] = a[i];
		i--;
		j++;
	}

	if (leftSmaller) {
		int carry = 1;
		i = mid - 1;
		if (n & 1) {
			j = mid + 1;
			a[mid] += carry;
			carry = a[mid] / 10;
			a[mid] %= 10;
		}
		else j = mid;

		while (i >= 0) {
			a[i] += carry;
			carry = a[i] / 10;
			a[i] %= 10;
			a[j] = a[i];
			i--;
			j++;
		}
	}
}

void nextSmallestPalin(vector<int> &a) {
	int n = a.size();
	if (allAre9(a)) {
		for (int &e : a) e = 0;
		a[n - 1] = 1;
		a.insert(a.begin(), 1);
	}

	solve(a);
}