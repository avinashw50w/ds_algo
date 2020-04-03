/**
 * a dp of the form : for all j < i, min(dp[j] + b[j]*a[i]), where b[j] >= b[j+1] and a[i] <= a[i+1]
 * convex hull trick reduces the time complexity of the above dp from O(n2) to O(n)
 */

typedef long long ll;
const ll INF = 1e18L;

struct Line {
    ll m, c;
    ll eval(ll x) { return m*x + c; }
    ll intersectX(Line l) { return (long double) (c - l.c) / (l.m - m); }
};

deque<Line> dq;

dq.push_back({0, 0});

ll ans = INF;
for (int i = 0; i < n; ++i) {
    // remove the latest lines whose y coordinates are less than their previous lines
    while (dq.size() >= 2 and dq[dq.size() - 2].eval(x_value[i]) >= dq.back().eval(x_value[i]))
        dq.pop_back();

    ll f = dq.back().eval(x_value[i]) + some_operation that u wanna perform
    ans = min(ans, f);
    // create a new line with m and c values
    Line curr = {m[i], f};

    while (dq.size() >= 2 && cur.intersectX(dq[0]) >= dq[0].intersectX(dq[1]))
        dq.pop_front();
    
    dq.push_front(cur);
}