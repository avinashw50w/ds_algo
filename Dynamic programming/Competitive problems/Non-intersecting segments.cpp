#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

struct Point {
    int x, y;
};

Point f[maxn], s[maxn];

bool cmp(const pair<int,int>& a, const pair<int,int> &b) {
    return a.first < b.first;
}

int main() {
    int n; cin >> n;
    vector<pair<int,int>> F, S;
    for (int i = 0; i < n; ++i) {
        cin >> f[i].x >> f[i].y >> s[i].x >> s[i].y;
        F.push_back({ f[i].x, f[i].y });
        S.push_back({ s[i].x, s[i].y });
    }

    sort(F.begin(), F.end(), cmp);
    sort(S.begin(), S.end(), cmp);

    int a[n];

    for (int i = 0; i < n; ++i) {
        int x = lower_bound(F.begin(), F.end(), make_pair(f[i].x, f[i].y)) - F.begin();
        int y = lower_bound(S.begin(), S.end(), make_pair(s[i].x, s[i].y)) - S.begin();
        a[x] = y;
    }

    // now find the longest increasing subsequence on x coord of the second line
    set<int> s;
    for (int i = 0; i < n; ++i) {
        auto it = s.lower_bound(a[i]);
        if (it != s.end()) 
            s.erase(it);
        s.insert(a[i]);
    }

    cout << s.size() << "\n";
}