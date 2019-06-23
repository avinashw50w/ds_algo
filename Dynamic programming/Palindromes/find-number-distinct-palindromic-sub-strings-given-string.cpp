/*Find all distinct palindromic sub-strings of a given string
Given a string of lowercase ASCII characters, find all distinct continuous palindromic sub-strings of it. 

Examples:

Input: str = "abaaa"
Output:  Below are 5 palindrome sub-strings
a
aa
aaa
aba
b    */

set<string> findPalindromes(string s) {

	int N = s.length();

	bool dp[N][N];
	memset(dp, false, sizeof(dp));

	REP(i, 0, N) dp[i][i] = true;

	REP(i, 0, N-1) 
		if(s[i] == s[i+1]) dp[i][i+1] = true;

	REP(L, 3, N+1)
		REP(i, 0, N-L+1) {
			int j = i+L-1;

			if(s[i] == s[j] and dp[i+1][j-1]) 
				dp[i][j] = true;
		}

	set<string> P;

	REP(i, 0, N)
	REP(j, 0, N) {
		if(dp[i][j])
			P.insert(s.substr(i, j-i+1));
	}

	return P;
}
/////////////////////////////////////////////////////////////////////////////

void getPalind(int s, int e, string str, set<string>& S) {  
    while(s >= 0 && e < str.size() && str[s] == str[e]) {
    	S.insert(str.substr(s, e-s+1));
        s--;
        e++;
    }
}
 
void printSet(set<string> S) {
    set<string>::iterator it;
    for(it = S.begin(); it != S.end(); it++) cout << *it <<endl;
}
 
void printPalind(string str) {
    set<string> S;
    int n = str.size();
    for(int i = 0; i < n; i++) {
        getPalind(i, i, str, S);
 
        if(i+1 < n && str[i] == str[i+1])
            getPalind(i, i+1, str, S);
    }
    printSet(S);
}
 
int main()
{
    string s;
    int t;
    cin >> t;
    while(t--) {
        cin >> s;
        printPalind(s);
        cout << endl;
    }
}
 
