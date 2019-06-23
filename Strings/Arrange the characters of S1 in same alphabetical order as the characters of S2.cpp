/*
 
 Google Telephonic Round 1
 
 Given two strings - S1 and S2. 
 Arrange the characters of S1 in same alphabetical order as the characters of S2.
 If a character of S1 is not present in S2 - such characters should come at the end of 
 the result string, but make sure to retain the order of such characters
 Case sensitivity is irrelevant
 e.g. S1 = "Google", S2 = "dog"
 Output = "ooggle"
 
 e.g. S1 = "abcdedadf", S2 = "cae"
 Output = "caaebdddf"
 */

string solve(string s1, string s2) {
	
	string res = "";
	int n = s1.size(), m = s2.size();

	// convert to lowercase
	for_each(s1.begin(), s1.end(), [](char &c) { c = ::tolower(c); });
	for_each(s2.begin(), s2.end(), [](char &c) { c = ::tolower(c); });

	int f1[255] = {0}, f2[255] = {0};

	for (int i = 0; i < n; ++i) f1[s1[i]]++;
	for (int i = 0; i < m; ++i) f2[s2[i]]++;

	for (int i = 0; i < m; ++i) {
		if (f2[s2[i]] == 0) continue;

		if (f1[s2[i]] == 0) continue;

		res += string(f1[s2[i]], s2[i]);

		f1[s2[i]] = f2[s2[i]] = 0;
	}

	for (int i = 0; i < n; ++i) {
		if (f1[s1[i]]) res += s1[i];
	}

	return res;
}