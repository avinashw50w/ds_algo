/*Lexicographically largest string possible for a given cost of appending characters
Given an integer W and an array a[] of size 26 where ai denotes the cost of using the ith 
alphabet, the task is to find lexicographically the largest string that can be generated for a 
cost W.

Examples:

Input: W = 236, a[] = {1, 1, 2, 33, 4, 6, 9, 7, 36, 32, 58, 32, 28, 904, 22, 255, 47, 69, 558, 544, 21, 36, 48, 85, 48, 58}
Output: zzzze 
Explanation: 
4 * (cost of z) + cost of e = 4 * 58 + 4 = 232 + 4 = 236

IDEA: use backtracking
*/

int solve(int sum, vector<int> &cost, int i, vector<int> &res) {
    if (i < 0 or sum < 0) return false;
    if (sum == 0) return true;

    // take the ith char
    res.push_back(i);
    if (solve(sum - cost[i], cost, i - 1, res)) return true;
    res.pop_back();
    // don't take the i'th char
    return solve(sum, cost, i - 1, res);
}

string largestString(vector<int> cost, int W) {
    vector<int> res;
    solve(s, W, cost, 25, res);

    string ans;
    for (int e: v) ans += (e + 'a');
    return ans;
}