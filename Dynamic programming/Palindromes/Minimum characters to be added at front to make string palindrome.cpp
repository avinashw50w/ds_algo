/*Minimum characters to be added at front to make string palindrome
Given a string str we need to tell minimum characters to be added at front of string to make string palindrome.

Examples:

Input  : str = "ABC"
Output : 2
We can make above string palindrome as "CBABC"
by adding 'B' and 'C' at front.

Input  : str = "AACECAAAA";
Output : 2
We can make above string palindrome as AAAACECAAAA
by adding two A's at front of string.

Check fot the longest prefix which is a palindrome, lets call it p. Then our ans will be N - len(p) where N
is the len of the original string*/

int solve(string s) {

	int N = s.size();
	
	while(s.size()) {

		if (isPalindrome(s)) break;

		s.pop_back();
	}

	return N-s.size();
}