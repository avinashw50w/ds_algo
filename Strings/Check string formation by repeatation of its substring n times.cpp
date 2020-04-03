/*Given a string ‘str’, check if it can be constructed by taking a substring of it 
and appending multiple copies of the substring together.
Examples:

Input: str = "abcabcabc"
Output: true
The given string is 3 times repetition of "abc"

Input: str = "abadabad"
Output: true
The given string is 2 times repetition of "abad"

if S = nT, where T is a substring of S, then the length of the longest proper prefix which is
also a suffix(LPS) is equal to N - len(T)
ie, len(lps) = N - len(T)
=>  len(T) = N - len(lps)
			= multiple of N, coz T is repeated n times to form S 

so we just need to check whether N % (N - len(lps)) == 0
*/


int lps(string s) {
	int n = s.size();
	int f[n];
	f[0] = 0;

	int j = 0;
	for (int i = 1; i < n; ++i) {
		while(j >= 0 and s[i] != s[j]) {
			if (j >= 1) j = f[j-1];
			else j = -1;
		}

		j++;
		f[i] = j;
	}

	return *max_element(f, f+n);
}

bool isRepeat(string S, string T) {

	int lps = lps(T);

	int N = S.size();
	int n = T.size();

	return  N % (N - lps) == 0;
}