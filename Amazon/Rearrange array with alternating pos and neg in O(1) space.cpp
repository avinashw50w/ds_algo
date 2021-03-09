/*Rearrange array in alternating positive & negative items with O(1) extra space | Set 1
Given an array of positive and negative numbers, arrange them in an alternate fashion such that
every positive number is followed by negative and vice-versa maintaining the order of appearance.
Number of positive and negative numbers need not be equal. If there are more positive numbers
they appear at the end of the array. If there are more negative numbers, they too appear in the
end of the array.

Examples :
Input:  arr[] = {1, 2, 3, -4, -1, 4}
Output: arr[] = {-4, 1, -1, 2, 3, 4}*/

void rotateRight(vector<int> &a, int curr, int incorrectPos) {
	int t = a[curr];
	for (int i = curr; i > incorrectPos; --i) {
		a[i] = a[i - 1];
	}
	a[incorrectPos] = t;
}

void rearrange(vector<int> &a) {
	int n = a.size();

	int incorrectPos = -1;
	for (int i = 0; i < n; ++i) {

		if (incorrectPos >= 0) {
			if ((a[i] >= 0 and a[incorrectPos] < 0) or (a[i] < 0 and a[incorrectPos] >= 0)) {
				rotateRight(a, i, incorrectPos);
			}

			if (i - incorrectPos >= 2)
				incorrectPos += 2;
			else
				incorrectPos = -1;
		}

		if (incorrectPos == -1) {
			if ((a[i] >= 0 and !(i & 1)) or (a[i] < 0 and (i & 1)))
				incorrectPos = i;
		}
	}
}