/*Given two strings where first string may contain wild card characters and second string is a normal string. Write a function that returns true if the two strings match. The following are allowed wild card characters in first string.

* --> Matches with 0 or more instances of any character or set of characters.
? --> Matches with any one character.
2
ge*ks
geeks
ge?ks*
geeksforgeeks

Output:
Yes
Yes*/

bool solve(string text, string pat, int i, int j) {
	if (i >= text.size() and j >= pat.size()) return true;
	// if * lies at the end of pattern then it can match any chars
	if (pat[j] == '*' and j + 1 == pat.size()) return true;

	if (i >= text.size() or j >= pat.size()) return false;

	if (pat[j] == '?' or (text[i] == pat[j]))
		return solve(text, pat, i + 1, j + 1);

	else if (pat[j] == '*')
		// either replace the '*' with text[i] and solve for i + 1 with the same '*'
		// or replace '*' with '' string and solve for next pat[j+1]
		return solve(text, pat, i + 1, j) or solve(text, pat, i, j + 1);

	return false;
}

bool check(string text, string pat) {
	return solve(text, pat, 0, 0);
}