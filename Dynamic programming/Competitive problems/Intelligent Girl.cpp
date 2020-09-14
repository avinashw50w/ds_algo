/*Soumika has a string S and its starting index is 1. The string S consists of characters from .
As she is very intelligent, she wants to test his brother Vinay Tendulkar. She asked her brother
Vinay Tendulkar to count the number of even numbered characters ( i.e  ) for every index i .
For an index i, the result should be calculated from i to the end of the string.
As Vinay doesn't know about programming, he wants you to help him find the solution.

Input:
First line contains a string S.

Output:
Print |S| space-separated integers,the result of every index.

Constraints:
1 ≤ |S| ≤ 4

SAMPLE INPUT
574674546476
SAMPLE OUTPUT
7 7 7 6 5 5 4 4 3 2 1 1
Explanation
Given string S is 574674546476.
for index 1
Number of even numbers from 5 to end of the string is 7 so the result of index 1 is 7.
for index 2
Number of even numbers from 7 to end of the string is 7 so the result of index 2 is 7.*/


int main() {
    string s; cin >> s;

    int n = s.size();

    int dp[n] = {0};
    dp[n - 1] = (s[n - 1] - '0') % 2 == 0 ? 1 : 0;

    for (int i = n - 2; i >= 0; --i) {
        dp[i] = ((s[i] - '0') % 2 == 0) + dp[i + 1];
    }

    for (int i = 0; i < n; ++i) cout << dp[i] << " ";
}

