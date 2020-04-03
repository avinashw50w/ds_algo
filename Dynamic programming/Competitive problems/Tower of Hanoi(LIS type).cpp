/*Bob and Alice like to play the game tower of Hanoi. One day Alice challenges Bob to build the tallest tower from a set of disks of different height and radius. The tower of Hanoi can be built by stacking disks on top of each other. In order to put disk A on top of disk B, the radius and height of A must be strictly smaller than those of B. Help Bob to win the challenge.

Input:
First line of input contains number of test cases T.
First line of each test case contains value of N, the number of disks. The next N lines contains two positive integer number Ri and Hi corresponding to the radius and height of ith Disk respectively.

Output:
For each test case print the maximum height of the tower possible.

Constraints:
1<=T<=10
1<=N<=200
1<=Ri, Hi<=10^9*/

#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,int> &a, const pair<int, int> &b) {
    if (a.first == b.first) return a.second < a.second;
    return a.first < b.first;
}

int main() {
    int t, n;
    vector<pair<int,int>> v;
    
    cin >> t;
    
    while (t--) {
        v.clear();
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int r, h;
            cin >> r >> h;
            v.push_back({r, h});
        }
        
        sort(v.begin(), v.end(), cmp);
        
        long long dp[n] = {0};
        dp[0] = v[0].second;
        
        for (int i = 1; i < n; ++i) {
            dp[i] = v[i].second;
            for (int j = 0; j < i; ++j) {
                if (v[j].first < v[i].first and v[j].second < v[i].second)
                    dp[i] = max(dp[i], v[i].second + dp[j]);
            }
        }
        
        cout << *max_element(dp, dp + n) << endl;
    }
    
}