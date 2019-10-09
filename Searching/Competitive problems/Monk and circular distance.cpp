
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    long long x, y, r;
    cin >> N;
    vector<double> dist(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        dist[i] = sqrt((double)x*x + y*y);
    }
    
    sort(dist.begin(), dist.end());
    
    int Q;
    cin >> Q;
    while (Q--) {
        cin >> r;
        
        int idx = upper_bound(dist.begin(), dist.end(), r) - dist.begin();
        cout << idx << endl;
    }
}