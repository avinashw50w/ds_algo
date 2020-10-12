/* N coins are tossed, and the probability of getting a head in the ith toss is pi.
Find the probability of getting more heads than tails after tossing all the N coins*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    scanf("%d", &N);
    vector<double> p(N);

    // dp[i] : probability of getting i heads so far
    vector<double> dp(N + 1);
    dp[0] = 1;
    double p_heads;

    for (int tosses = 1; tosses <= N; ++tosses) {
        scanf("%lf", &p_heads);
        for (int heads = tosses; heads >= 0; --heads) {
            /*prob of getting i heads in n tosses =
                prob of getting i-1 heads in n-1 tosses * prob of getting head in the nth toss +
                prob of getting i heads in n-1 tosses * prob of getting tail in the nth toss
             */
            dp[heads] = dp[heads - 1] * p_heads + dp[heads] * (1 - p_heads);
        }
    }

    double ans = 0;

    for (int head = 0; head <= N; ++head) {
        int tail = N - head;

        if (head > tail) ans += dp[head];
    }

    printf("%.10lf\n", ans);
}