/*given an array of intergers, find the no of pairs whose xor is K.
IDEA: a xor b = c, implies a xor c = b, also implies b xor c = a
*/

int solve(vector<int> a, int K) {
    unordered_map<int, int> mp;
    int n = a.size();
    int ans = 0;

    for (int e : a) {
        int x = e ^ K;
        ans += mp[x];
        mp[e]++;
    }

    return ans;
}