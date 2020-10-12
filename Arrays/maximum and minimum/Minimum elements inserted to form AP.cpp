/*given a sorted array, find minimum elements to be inserted in the array to form an Arithmetic progression
IDEA: store the consecutive element's difference in an array say diff, then find the GCD
of all the elements in diff. Now the no of elements to be inserted between a[i] and a[i+1]
will be = (a[i+1] - a[i]) / GCD - 1
*/


int solve(vector<int> a) {
    int n = a.size();
    if (n == 0 or n == 1 or n == 2) return 0;

    vector<int> diff(n - 1);
    for (int i = 0; i + 1 < n; ++i) diff[i] = a[i + 1] - a[i];

    int g = diff[0];
    for (int e : diff) g = __gcd(e, g);

    int ans = 0;
    if (g > 1) for (int e : diff) ans += e / g - 1;

    return ans;
}