/*Minimize cost to convert given string into concatenation of equal substrings of length K
Difficulty Level : Hard
Last Updated : 04 Nov, 2020
Given a string S of length N consisting of lowercase letters and an integer K, where N % K = 0, 
the task is to find the minimum cost to convert the given string into a concatenated string of 
any K-length string by performing the following operations:
NOTE: the K-length string need not be a substring of S
A character can be replaced with another character.
Cost of each operation is the absolute difference between the replacced and the replacing character. For example, if ‘a’ is replaced with ‘z’, then cost of the operation is |”a”-“z”| = 25.
Examples:

Input: S = “abcdef”, K = 2
Output: 8
Explanation:
One possible answer is “cdcdcd” and the repeatingK length substring is “cd”. The minimum cost to required to convert the string is calcualted by the following steps:
Step 1: Replace S[0] with “c”. Therefore, cost = |”a”-“c”| = 2.
Step 2: Replace S[1] with “d”. Therefore, cost = |”b”-“d”| = 2.
Step 3: Replace S[2] with “c”. Therefore, cost = |”c”-“c”| = 0.
Step 4: Replace S[3] with “d”. Therefore, cost = |”d”-“d”| = 0.
Step 5: Replace S[4] with “c”. Therefore, cost = |”e”-“c”| = 2.
Step 6: Replace S[5] with “d”. Therefore, cost = |”f”-“d”| = 2.
Therefore, the minimum cost required = 2 + 2 + 0 + 0 + 2 + 2 = 8.

IDEA: for any string s[0...k-1], if it is concatenated to form the string S, then any 
character at index i (0<=i<=k-1) will be repeated at index i + k, i + 2k, i + 3k, .... of
the string S.
*/

const int inf = 1e9 + 7;

int solve(string s, int k) {
    int n = s.length();
    int ans = 0;

    for (int i = 0; i < k; ++i) {
        vector<int> f(26);
        for (int j = i; j < n; j += k) {
            f[s[j]-'a']++;
        }

        int minCost = inf;
        // replace each of i+k, i+2k,... positions with the new character nc
        // and take the min cost so far
        for (int nc = 0; nc < 26; ++nc) {
            cost = 0;
            for (int cc = 0; cc < 26; ++cc) {
                cost += (nc - cc) * f[cc];
            }
            mincost = min(mincost, cost);
        }

        ans += minCost;
    }

    return ans;
}
