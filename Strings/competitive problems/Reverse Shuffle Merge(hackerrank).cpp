/*Given a string, A, we define some operations on the string as follows:
a. reverse(A) denotes the string obtained by reversing string A. Example: reverse('abc') = cba
b. shuffle(A) denotes any string that's a permutation of string A. Example:
suffle('god') = ['god', 'odg', 'gdo', ...]

c. merge(A1, A2) denotes any string that's obtained by interspersing the two strings A1 & A2,
maintaining the order of characters in both. For example, A1 = 'abc' & A2 = 'def',
one possible result of merge(A1, A2) could be 'abcdef', another could be 'abdecf', another
could be 'adbecf' and so on.

Given a string s such that s belongs to merge(reverse(A), shuffle(A)) for some string A,
find the lexicographically smallest A.

IDEA: some string A is reversed and merged with a shuffled version of itself.
So we can infer that the size of A is half the size of s and since the relative order is
maintained in merge operation, so the reverse of A is a subsequence of s.
check out this link for detailed explanation: https://www.youtube.com/watch?v=_QQe2TQ2o_4

*/

string reverseShuffleMerge(string s) {
    int n = s.length();
    vector<int> used(26), req(26);
    for (char c : s) req[c - 'a']++;
    vector<int> rem = req;
    for (int &e : req) e /= 2;

    string ans = string(n, ' ');
    int j = 0;

    for (int i = n - 1; i >= 0; --i) {
        char c = s[i];
        int idx = s[i] - 'a';
        if (i == n - 1) {
            ans[j++] = c;
            used[idx]++;
            rem[idx]--;
            continue;
        }
        if (used[idx] < req[idx]) {
            if (c >= ans[j - 1]) {
                ans[j++] = c;
                used[idx]++;
                rem[idx]--;
            }
            else {
                while (j > 0 and c < ans[j - 1] and
                        rem[ans[j - 1] - 'a'] + used[ans[j - 1] - 'a'] - 1 >= req[ans[j - 1] - 'a']) {
                    used[ans[j - 1] - 'a']--;
                    j--;
                }

                ans[j++] = c;
                used[idx]++;
                rem[idx]--;
            }
        }
        else {
            rem[idx]--;
        }
    }

    return ans.substr(0, j);
}
