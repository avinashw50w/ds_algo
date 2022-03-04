/*Below are steps to find the previous permutation?
1. Find largest index i such that str[i – 1] > str[i].
2. Find largest index j such that j >= i and str[j] < str[i - 1].
3. Swap str[j] and str[i - 1].
4. Reverse the sub-array starting at str[i]. */
#include <bits/stdc++.h>
using namespace std;
prevPermutation(string &str) {
	// Find index of the last element of the string
	int n = str.length() - 1;
	// Find largest index i such that str[i - 1] > str[i]
	// 64541234
	//     ^
	int i = n;
	while (i && str[i - 1] <= str[i])
		i--;

	if (i == 0) return false;
	// if string is sorted in ascending order
	// we're at the last permutation if (i <= 0) return false;
	// Note - str[i..n] is sorted in ascending order
	// Find the largest element in [i..n-1] that is less than str[i - 1]
	int j = i - 1;
	while (j + 1 < n && str[j + 1] <= str[i - 1])
		j++;
	// Swap character at i-1 with j
	swap(str[i - 1], str[j]);
	// Reverse the substring [i..n]
	reverse(str.begin() + i, str.end());

	return true;
}
// Driver code
int main() {
	string str = "4235";
	if ( prevPermutation(str) )
		cout << "Previous permutation is " << str ;
	else cout << "Previous permutation doesn't exist" ;
	return 0;
}