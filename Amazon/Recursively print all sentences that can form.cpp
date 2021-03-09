/*Recursively print all sentences that can be formed from list of word lists
Last Updated: 26-09-2020
Given a list of word lists How to print all sentences possible taking one word from a list at a time via recursion?
Example:

Input: {{"you", "we"},
        {"have", "are"},
        {"sleep", "eat", "drink"}}

Output:
  you have sleep
  you have eat
  you have drink
  you are sleep
  you are eat
  you are drink
  we have sleep
  we have eat
  we have drink
  we are sleep
  we are eat
  we are drink
*/


void solve(vector<vector<string>> list, vector<string> &res, int i, int j) {
    int n = list.size(), m = list[0].size();
    res[i] = list[i][j];
    if (i == n - 1) {
        for (int i = 0; i < n; ++i)
            cout << res[i] << " ";
        cout << endl;
        return;
    }
    for (int k = 0; k < m; ++k) {
        if (list[i + 1][k] != "")
            solve(list, res, i + 1, k);
    }
}

vector<string> print(vector<vector<string>> list) {
    int n = list.size(), m = list[0].size();
    vector<string> res(n);

    for (int j = 0; j < m; ++j) {
        if (list[0][j] != "")
            solve(list, res, 0, j);
    }

    return res;
}