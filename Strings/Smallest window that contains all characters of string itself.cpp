/*Smallest window that contains all characters of string itself
Given a string, find the smallest window length with all distinct characters of the given string. 
For eg. str = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca” .

Examples:

Input  : aabcbcdbca
Output : dcba
Explanation : 
dbca of length 4 is the smallest 
window with highest number of distinct
characters.         
*/


string solve(string s) {

	int n = s.size();

	int f[255] = {0};

	int unique = 0;
	for (int i = 0; i < n; ++i)  {
		if (f[s[i]] == 0) unique++;
		f[s[i]]++;
	}

	memset(f, 0, sizeof(f));
	int count = 0, minLen = INT_MAX, start = 0;

	for (int i = 0; i < n; ++i) {
		f[s[i]]++;

		if (f[s[i]] == 1) count++;

		if (count == unique) {
			while (f[s[start]] > 1) {
				f[s[start]]--;
				start++;
			}

			minLen = min(minLen, i-start+1);
		}
	}

	return s.substr(start, minLen);

}