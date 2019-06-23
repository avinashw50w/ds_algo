/*Write a function to find the longest common prefix string amongst an array of strings.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.

As an example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".

Given the array of strings, you need to find the longest S which is the prefix of ALL the strings in the array.

Example:

Given the array as:

[

  "abcdefgh",

  "aefghijk",

  "abcefgh"
]
The answer would be “a”.  */

#define min(a, b) a<b?a:b

string Solution::longestCommonPrefix(vector<string> &A) {
    int n = A.size();
    int minlen = INT_MAX;

    for(int i = 0; i < n; ++i) minlen = min(minlen, A[i].length());
    
    string res = "";
    char c;

    for(int j = 0; j < minlen; ++j) {
        c = A[0][j];
        
        for(int i = 1; i < n; ++i) {
            if(A[i][j] != c) return res;
        }
        res += c;
    }
    return res;
}
