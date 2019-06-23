/*Count All Palindrome Sub-Strings in a String | Set 2
Given a string, the task is to count all palindrome substring in a given string. 
Length of palindrome substring is greater then or equal to 2.

Examples:
Input : str = "abaab"
Output: 3
Explanation : 
All palindrome substring are :
 "aba", "aa", "baab" */

/*fix an index and expand on both the sides checking if the characters are same. and keep counting*/
// NOTE: a single character is not counted as a palindrome

void getAllPalindromes(string s, int l, int r, set<string> &st) {
	int n = s.size();
	while(l >= 0 and r < n and s[l] == s[r]) {
		st.insert(s.substr(l, r-l+1));
		l--; r++;
	}
}

int solve(string s) {

	int  n = s.size();
	unordered_set<string> st;

	for (int i = 1; i < n; ++i) {

		int l = i-1, r = i;

		getAllPalindromes(s, l, r, st);

		l = i-1, r = i+1;

		getAllPalindromes(s, l, r, st);
	}

	return st.size();
}

int main() {
	string s = "abacdcaba";
	
	cout << solve(s) << endl;
}