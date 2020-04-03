/*Recursively remove all adjacent duplicates
Given a string, recursively remove adjacent duplicate characters from string. 
The output string should not have any adjacent duplicates. See following examples.
Input:  azxxzy
Output: ay
First "azxxzy" is reduced to "azzy". 
The string "azzy" contains duplicates, 
so it is further reduced to "ay".

Input: geeksforgeeg
Output: gksfor
First "geeksforgeeg" is reduced to 
"gksforgg". The string "gksforgg" 
contains duplicates, so it is further 
reduced to "gksfor".

Input: caaabbbaacdddd
Output: Empty String

Input: acaaabbbacdddd
Output: acac*/

string solve(string s) {
	int n = s.size();

	if (n == 0 or n == 1) return  s;

	int i = 0, j;

	while (i < n-1) {

		if (s[i] == s[i+1]) {
			j = i+1;
			while (j < n and s[j] == s[i]) j++;

			return solve(s.substr(0, i) + s.substr(j, n-j+1));
		}

		i++;
	}

	return s;
}