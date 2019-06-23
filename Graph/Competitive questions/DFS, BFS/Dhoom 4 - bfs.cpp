/**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)

const int mod = 100000;
int ans[mod+5], a[mod+5];

int main() {
    int key, lKey;
    int N; 
    
    cin >> key >> lKey;
    cin >> N;
    memset(ans, -1, sizeof(ans));
    
    rep(i,0,N) cin >> a[i];
    
    ans[key] = 0;
    queue<int> Q;
    Q.push(key);
    
    while(!Q.empty()) {
        int k = Q.front();
        Q.pop();
        int nKey;
        rep(i,0,N) {
            nKey = (k*a[i]) % mod;    
            if(ans[nKey] == -1) {
                ans[nKey] = ans[k] + 1;
                if(nKey == lKey) break;
                Q.push(nKey);
            }
        }
    }
    cout << ans[lKey] << endl;
}