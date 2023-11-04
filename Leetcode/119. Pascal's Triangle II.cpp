/*Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.*/

vector<int> getRow(int n) {
    vector<int> res(n + 1);
    long curr = 1;
    for (int i = 0; i <= n / 2; ++i) {
        if (i == 0) res[i] = res[n - i] = 1;
        else {
            curr = (curr * (n - i + 1)) / i;
            res[i] = res[n - i] = curr;
        }
    }

    return res;
}