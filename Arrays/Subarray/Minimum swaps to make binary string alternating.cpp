/*Minimum swaps required to make a binary string alternating
Last Updated: 28-12-2018
You are given a binary string of even length and equal number of 0’s and 1’s. What is the
minimum number of swaps to make the string alternating. A binary string is alternating if no two consecutive elements are equal.

Examples:

Input : 000111
Output : 1
Explanation : Swap index 2 and index 5 to get 010101

1. Count number of zeroes at odd position and even position of the string. Let their count be
odd_0 and even_0 respectively.
2. Count number of ones at odd position and even position of the string. Let their count be
odd_1 and even_1 respectively.
3. We will always swap a 1 with a 0 (never a 1 with a 1 or a 0 with a 0). So we just check if
our alternating string starts with 0 then the number of swaps is min(even_0, odd_1) and if our
alternating string starts with 1 then the number of swaps is min(even_1, odd_0). The answer is
min of these two*/

int countMinSwaps(string st)
{

	int min_swaps = 0;

	// counts number of zeroes at odd
	// and even positions
	int odd_0 = 0, even_0 = 0;

	// counts number of ones at odd
	// and even positions
	int odd_1 = 0, even_1 = 0;

	int n = st.length();
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			even_1 += st[i] == '1';
			even_0 += st[i] == '0';
		}
		else {
			odd_1 += st[i] == '1';
			odd_0 += st[i] == '0';
		}
	}

	// alternating string starts with 0
	int cnt_swaps_1 = min(even_0, odd_1);

	// alternating string starts with 1
	int cnt_swaps_2 = min(even_1, odd_0);

	// calculates the minimum number of swaps
	return min(cnt_swaps_1, cnt_swaps_2);
}