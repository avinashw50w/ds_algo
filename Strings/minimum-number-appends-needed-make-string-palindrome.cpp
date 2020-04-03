/*Minimum number of Appends needed to make a string palindrome
Given a string s we need to tell minimum characters to be appended (insertion at end) to make a string palindrome.

Examples:

Input : s = "abede"
Output : 2
We can make string palindrome as "abedeba"
by adding ba at the end of the string.

Input : s = "aabb"
Output : 2
We can make string palindrome as"aabbaa"
by adding aa at the end of the string.

The solution can be achieved by removing characters from the beginning of the string one by one 
and checking if the string is palindrome or not.

For Example, consider the above string, s = “abede”.

We check if the string is palindrome or not.

The result is false, then we remove the character from the beginning of string and now string becomes “bede”.

We check if the string is palindrome or not. The result is again false, then we remove the character 
from the beginning of string and now string becomes “ede” */

bool isPalindrome(char *s) {
	int l = 0, r = strlen(s)-1;
	while(l < r) {
		if (s[l++] != s[r--]) return false;
	}

	return true;
}

int solve(char *s) {
	
	if (isPalindrome(s)) return 0;
	s++;
	return 1 + solve(s);
}