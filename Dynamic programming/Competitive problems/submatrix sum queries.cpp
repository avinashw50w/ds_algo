/*submatrix sum queries*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int r, c;
    cin >> r >> c;
    
    int a[r+1][c+1];
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j) cin >> a[i][j];
        
    int dp[r+1][c+1];
    memset(dp, 0, sizeof(dp));
    
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j) 
            dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + a[i][j];
    
    int q; cin >> q;
    int x1, y1, x2, y2;
    
    while (q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1++; y1++; x2++; y2++;
        
        cout << (dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1]) << endl;
    }
}