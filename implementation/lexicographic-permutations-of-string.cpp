/*Print all permutations in sorted (lexicographic) order
Given a string, print all permutations of it in sorted order. For example, if the input string is “ABC”, 
then output should be “ABC, ACB, BAC, BCA, CAB, CBA”.

Following are the steps to print the permutations lexicographic-ally

1. Sort the given string in non-decreasing order and print it. The first permutation is always the string sorted in non-decreasing order.

2. Start generating next higher permutation. Do it until next higher permutation is not possible. If we reach a permutation 
where all characters are sorted in non-increasing order, then that permutation is the last permutation.

Steps to generate the next higher permutation:
1. Take the previously printed permutation and find the rightmost character in it, which is smaller than its next character. 
Let us call this character as ‘first character’.

2. Now find the ceiling of the ‘first character’. Ceiling is the smallest character on right of ‘first character’, 
which is greater than ‘first character’. Let us call the ceil character as ‘second character’.

3. Swap the two characters found in above 2 steps.

4. Sort the substring (in non-decreasing order) after the original index of ‘first character’.

Let us consider the string “ABCDEF”. Let previously printed permutation be “DCFEBA”. The next permutation in sorted order should be “DEABCF”. 
Let us understand above steps to find next permutation. The ‘first character’ will be ‘C’. The ‘second character’ will be ‘E’. 
After swapping these two, we get “DEFCBA”. The final step is to sort the substring after the character original index of ‘first character’. 
Finally, we get “DEABCF”.*/

int findCeil(string s, char c, int l, int n) {

	int ceil = l;

	for(int i = l+1; i < n; ++i)
		if(c < s[i] and s[i] < s[ceil])
			ceil = i;

	return ceil;
}

void sortedPermutations(string s) {
	int n = s.size();

	sort(s, s+n);

	bool finished = false;

	while(!finished) {

		cout << s << endl;

		for(int i = n-2; i >= 0; --i)
			if(s[i] < s[i+1])
				break;

		if(i == -1) finished = true;

		int ceilIndex = findCeil(str, str[i], i+1, n-1);

		swap(s[i], s[ceilIndex]);

		sort(s+i+1, s+n);
	}
}

int main()
{
    string str = "ABCD";
    sortedPermutations( str );
    return 0;
}