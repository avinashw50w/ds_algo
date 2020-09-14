/*Debapratim likes Monali and asked her out on a date. She agreed but on a condition that he must reach the top of the Ultimate Stairway to Heaven.

The stairway consists of N stairs. Initially, Debapratim is standing on the 1st stair. The kth stair is associated with a number Ak such that, for 0 < i < Ak, Debapratim can jump to the (k+i)th stair from the kth stair.

Your task is to find the no. of ways in which Debapratim can reach the Nth stair, the top of the Ultimate Stairway to Heaven. Since the answer can be large, compute it modulo 1000000007.

All test cases are designed such that every stair of the Ultimate Stairway to Heaven is reachable in at least one way.

Input:

The first line contains a single integer N.

Next line contains N space separated integers Ak , 0 < k < N.

Output:

Print a single line containing one integer, the no. of ways in which Debapratim can reach the Nth stair modulo 1000000007.

Constraints:

1 < N < 10^5
0 < Ak < N   */

/*The idea is to run a O(n) time complexity solution.
First let's see the brute force solution:
Initialize the solution vector to 0, for every i = 1 to n
for (i = 1 to n)
we know that all stairs i + 1 th, i + 2 th and so on up to i + a[i] [see note 1] are reachable from stair i.
So we add the dp[i] to each of dps[i + 1] dp[i + 2] and so on.*/

typedef long long ll;
const int mod = 1e9 + 7;
// O(N^2)
int main() {
    int N; cin >> N;
    vector<int> A(N);
    vector<ll> dp(N, 0);

    for (int &e : A) cin >> e;

    dp[0] = 1LL;

    for (int i = 0; i < N; ++i) {
        for (int j = 1; j <= A[i]; ++j) {
            dp[i + j] += dp[i];
            if (dp[i + j] >= mod) dp[i + j] -= mod;
        }
    }
    cout << dp[N - 1] << "\n";
}


//////////////////////////////////////
// Optimised one O(N)
/*But we can avoid the second loop by observing that we can mark for each i
the position i + 1 with dp[i] and position i + a[i] + 1 with -dp[i]
then we keep performing dp[i] += dp[i - 1] for i from 1 to n only once, after the positions were all of them marked.*/
int main() {
    int N; cin >> N;
    vector<int> A(N);
    vector<ll> dp(N, 0), pre(N, 0);


    for (int &e : A) cin >> e;

    ll sum = 0;
    dp[0] = 1LL;

    for (int i = 0; i < N - 1; ++i) {
        pre[i + 1] = (pre[i + 1] + dp[i]) % mod;
        if (i + 1 + A[i] < N) pre[i + 1 + A[i]] = (pre[i + 1 + A[i]] - dp[i] + mod) % mod;
        sum  = (sum + pre[i + 1]) % mod;
        dp[i + 1] = sum;
    }

    cout << dp[N - 1] << "\n";
}
