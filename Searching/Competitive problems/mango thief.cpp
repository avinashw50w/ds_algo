#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 2;
typedef pair<int,int> pp;
int main() {
    int N, M;
    
    cin >> N >> M;
    
     vector<int> c(N), s(M);
    vector<pair<int,int>> m;
    
    for (int &x: c) scanf("%d", &x);
    
    for (int i = 0; i < M; ++i) {
        int height, mangoes;
        cin >> height >> mangoes;
        m.push_back({height, mangoes});
    }
    
    sort(m.begin(), m.end());
    
    int sum = 0;
    for (int i = 0; i < M; ++i) {
        sum += m[i].second;
        s[i] = sum;
    }
    
    for (int x: c) {
        int idx = upper_bound(m.begin(), m.end(), pp(x, 0), 
        [](const pp &a, const pp &b) { return a.first < b.first; }) - m.begin();
        
        if (idx != -1) cout << s[idx-1] << " ";
        else cout << -1 << " ";
    }
}