#include <bits/stdc++.h>
using namespace std;

void solve(string s) {
	int n = s.size();

	bool dp[n+1][n+1];

	memset(dp, 0, sizeof(dp));

	for(int i=0; i<n; ++i) dp[i][i] = true;

	int start = 0, maxlen = 1;

	for(int i=0; i<n-1; ++i) 
		if(s[i] == s[i+1]) dp[i][i+1] = true, start = i, maxlen = 2;

	for(int L=3; L<=n; ++L) {
		for(int i=0; i<=n-L; ++i) {
			int j = i+L-1;

			if(s[i] == s[j] and dp[i+1][j-1]) {
				dp[i][j] = true;

				if(L > maxlen) start = i, maxlen = L;
			}
		}
	}

	string res;
	res.insert(0, s, start, maxlen);

	cout << maxlen << " " << res << endl;
}

/////////////////////////////////////////////////////////////////

// space optimized //
// A O(n^2) time and O(1) space program to find the longest palindromic substring
#include <stdio.h>
#include <string.h>
 
// A utility function to print a substring str[low..high]
void printSubStr(char* str, int low, int high)
{
    for( int i = low; i <= high; ++i )
        printf("%c", str[i]);
}
 
// This function prints the longest palindrome substring (LPS)
// of str[]. It also returns the length of the longest palindrome
int longestPalSubstring(char *str)
{
    int maxLength = 1;  // The result (length of LPS)
 
    int start = 0;
    int len = strlen(str);
 
    int low, high;
 
    // One by one consider every character as center point of 
    // even length palindromes
    for (int i = 1; i < len; ++i)
    {
        // Find the longest even length palindrome with center points
        // as i-1 and i.  
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
 
        // Find the longest odd length palindrome with center 
        // point as i
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
 
    cout << s.substr(start, maxLength);
 
    return maxLength;
}

int main() {
	string s = "abxabcxaxcbaacba";

	solve(s);
}
