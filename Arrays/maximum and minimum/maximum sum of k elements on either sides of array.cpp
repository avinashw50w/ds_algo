/*Given an array of size N. Find the maxium sum of k elements which are chosen either from the 
left of right side of the array.

eg. 2 5 1 6 3 4 8 3 2, k = 4

ans - 17 (4 8 3 2)

idea: first take the sum of first k elements: 2 5 1 6,
then 2 5 1 and the last element 2,
then 2 5 , 3 2
then 2 , 8 3 2
then   , 4 8 3 2
in each step keep updating the ans with the max sum so far
*/

int solve(vector<int> a, int k) {
    int n = a.size();
    int sum = 0, ans = -1e9;
    for (int i = 0; i < k; ++i) sum += a[i];
    ans = max(ans, sum);

    for (int i = 0; i < k; ++i) {
        sum -= a[k - i - 1];
        sum += a[n - 1 - i];
        ans = max(ans, sum);
    }

    return ans;
}


