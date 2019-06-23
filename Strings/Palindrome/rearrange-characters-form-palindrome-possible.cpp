/*Rearrange characters to form palindrome if possible
Given a string, convert the string to palindrome without any modifications like adding a character, 
removing a character, replacing a character etc.
Examples:

Input : "mdaam"
Output : "madam" or "amdma"

Input : "abb"
Output : "bab"

Input : "geeksforgeeks"
Output : "No Palindrome"*/

/* A palindrome is possible only if :
1. the count of all the characters in the string is even
2. Count of all the characters in the string is even except for one which is odd*/

string solve(string s) {

	int n = s.size();

	int f[255] = {0};

	int odds = 0;
	for (int i = 0; i < n; ++i) f[s[i]]++;

	for (int i = 0; i < 255; ++i) if (f[i] & 1) odds++;

	if (odds > 1) return "";

	string beg = "", mid = "", end = "";

	for (int i = 0; i < 255; ++i) {

		if (!f[i]) continue;

		beg += string(f[i]/2, char(i));

		if (f[i] & 1) mid = char(i);
	}

	end = beg;

	reverse(end.begin(), end.end());

	return beg + mid + end;
}

int main() {

	string s = "abcbacd";
	
	cout << solve(s) << endl;
}

///////////////////////////////////////////////////////////////
//  Similar problem
/*Largest palindromic number by permuting digits
Given N(very large), task if to print the largest palindromic number obtained by permuting the digits of N. 
If it is not possible to make a palindromic number, then print an appropriate message.

Examples :

Input : 313551
Output : 531135*/

// just iterat backwards, ie for (int i = 255-1; i >= 0; --i)