/*There are two different parallel lines L1 and L2 and there are N segments connecting them. 
Each segment connects two points (xi,yi) and (xj, yj) from these lines. You can assume that all 
the points (xi,yi) belong to L1 and all the points (xj,yj) belong to L2.
Your task is to find a subset of these segments such that there won’t be any two segments 
crossing each other. It is guaranteed that all the given points have distinct coordinates.

IDEA: sort the line L1 and L2 based on x coord and then find the LIS on y coord
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

struct Point {
    int x, y;
};

Point f[maxn], s[maxn];

int main() {
    int n; cin >> n;
    vector<pair<int,int>> F, S;
    for (int i = 0; i < n; ++i) {
        cin >> f[i].x >> f[i].y >> s[i].x >> s[i].y;
        F.push_back({f[i].x, f[i].y});
        S.push_back({s[i].x, s[i].y});
    }

    sort(F.begin(), F.end());
    sort(S.begin(), S.end());

    int a[n];

    for (int i = 0; i < n; ++i) {
        // in case of searching non primitive data types, explicitly define the type
        // here we have used make_pair, we can also use pair<int,int>(a, b) 
        int x = lower_bound(F.begin(), F.end(), make_pair(f[i].x, f[i].y)) - F.begin();
        int y = lower_bound(S.begin(), S.end(), make_pair(s[i].x, s[i].y)) - S.begin();
        a[x] = y;
    }

    // now find the longest increasing subsequence on x coord of the second line
    set<int> st;
    for (int i = 0; i < n; ++i) {
        auto it = st.lower_bound(a[i]);
        if (it != st.end()) 
            st.erase(it);
        st.insert(a[i]);
    }

    cout << st.size() << "\n";
}