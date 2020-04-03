/*Find largest word in dictionary by deleting some characters of given string
Giving a dictionary and a string ‘str’, find the longest string in dictionary which can be formed by deleting 
some characters of the given ‘str’.

Examples:

Input : dict = {"ale", "apple", "monkey", "plea"}   
        str = "abpcplea"  
Output : apple 

Input  : dict = {"pintu", "geeksfor", "geeksgeeks", 
                                        " forgeek"} 
         str = "geeksforgeeks"
Output : geeksgeeks*/

/*for each word in the dictionary check whether the word is a subsequence of the given string */

bool isSubsequence(string a, string b) {
	int n = a.size(), m = b.size();
	int i, j;

	for (int i = 0, j = 0; i < n, j < m; ++i) {
		if (a[i] == b[j]) j++;
	}

	return j == m;
}

int solve(string s, vector<string> dict) {

	int res = 0;

	for (string word: dict) {
		if (isSubsequence(s, word)) res = max(res, word.size());
	}

	return res;
}