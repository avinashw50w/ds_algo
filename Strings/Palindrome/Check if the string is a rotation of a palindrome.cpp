/*Check if a given string is a rotation of a palindrome
Given a string, check if it is a rotation of a palindrome. 
For example your function should return true for “aab” as it is a rotation of “aba”.
Examples:

Input:  str = "aaaad"
Output: 1  
// "aaaad" is a rotation of a palindrome "aadaa"

Input:  str = "abcd"
Output: 0
// "abcd" is not a rotation of any palindrome.

Try every rotation and check if it is a palindrome */
// O(n^2)

bool solve(string s) {
	
	if (isPalindrome(s)) return true;

	int n = s.size();

	for (int i = 0; i < n; ++i) {
		string s1 = s.substr(0, i+1);
		string s2 = s.substr(i+1, n-i);

		if (solve(s2 + s1)) return true;
	}

	return false;
}

//////////////////////////////////////////////
// efficient algo : 
/* Let X = s + s, and then check whether a palindrome of size s.size() exists in Q. 
This can be done using manachers algorithm*/
string getNewString(string s) {
	string newString = "@";

	for (int i = 0; i < s.size(); ++i) newString += "#" + s.substr(i, 1);
	newString += "#$";

	return newString;
}

int manacher(string X, string s) {
	string Q = getNewString(X);
	int N = Q.size();
	int c = 0, r = 0, mirror;
	int P[N+1] = {0};

	for (int i = 1; i < N-1; ++i) {
		mirror = i;

		if (r > i) P[i] = min(r-i, P[mirror]);

		while (Q[i-1-P[i]] == Q[i+1+P[i]]) P[i]++;

		if (i+P[i] > r) {
			c = i;
			r = i+P[i];
		}

		int idx = -1;

		for (int i = 1; i < N-1; ++i) {
			if (P[i] == s.size()) idx = i;
		}

		if (idx != -1 and X.substr((idx-i-s.size())/2, s.size()) == s) return true;

		return false; 
	}
}

int solve(string s) {
	string X = s+s;

	return manacher(X, s);
}

