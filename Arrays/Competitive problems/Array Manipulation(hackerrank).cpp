/*Starting with a 1-indexed array of zeros and a list of operations,
for each operation add a value to each of the array element between two given
indices, inclusive. Once all operations have been performed,
return the maximum value in the array.
each operation is of the form l r v: add v to every element in the range l to r inclusive
*/

long arrayManipulation(int n, vector<vector<int>> queries) {

    vector<long> a(n + 1, 0);

    for (auto q : queries) {
        int l = q[0], r = q[1];
        long v = q[2];
        l--; r--;
        a[l] += v;
        a[r + 1] -= v;
    }

    long ans = a[0];

    for (int i = 1; i <= n; ++i) a[i] += a[i - 1], ans = max(ans, a[i]);

    return ans;
}