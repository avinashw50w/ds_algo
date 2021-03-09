/*Minimum sum of squares of character counts in a given string after removing k characters
Given a string of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of ‘k’ characters. The value of a string is defined as the sum of squares of the count of each distinct character.
Example:
Input : str = abccc, K = 1
Output : 6
We remove c to get the value as 1^2 + 1^2 + 2^2
*/

int solve(string s) {
    unordered_map<char, int> f;
    for (char c : s) f[c]++;

    priority_queue<int> q;

    for (auto p : f) {
        q.push(p.second);
    }

    // remove k characters
    while (k--) {
        int top = q.top();
        q.pop();
        q.push(top - 1);
    }

    // calculate sum of squares
    int ans = 0;
    while (!q.empty()) {
        int top = q.top(); q.pop();
        ans += top * top;
    }

    return ans;
}