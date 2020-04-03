/*Find the smallest window in a string containing all characters of another string
Given two strings string1 and string2, find the smallest substring in string1 containing all characters of string2 efficiently.
For Example:

Input :  string = "this is a test string"
         pattern = "tist"
Output :  Minimum window is "t stri"
Explanation: "t stri" contains all the characters
              of pattern.

Input :  string = "geeksforgeeks"
         pattern = "ork" 
Output :  Minimum window is "ksfor" */

string solve(string str, string pat) {

	int n = str.size(), m = pat.size();

	if (n < m) return "";

	int fs[255] = {0};
	int fp[255] = {0};

	for (int i = 0; i < m; ++i) fp[pat[i]]++;

	int start = 0, minLen = INT_MAX, count = 0;

	for (int i = 0; i < n; ++i) {
		fs[str[i]]++;
		// create a window which contains all the characters of pat in the exact same number
		if (fp[str[i]] and fs[str[i]] <= fp[str[i]]) count++;

		if (count == m) {
			// remove extra characters from the window which are more in no in the window than the pattern
			while((fs[str[start]] > fp[str[start]]) or fp[str[start]] == 0) {
				if (fs[str[start]] > fp[str[start]]) 
					fs[str[start]]--;

				start++;

				minLen = min(minLen, i-start+1);
			}
		}
	}

	return str.substr(start, minLen);
}

int main() {
	string str = "this is a test string";
	string pat = "tist";
	
	cout << solve(str, pat);
}