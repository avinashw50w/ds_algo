/*A string contains only A and G. Flip exactly one segment such that the no of A's is maximized */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    string s;
    
    while (t--) {
        cin >> s;
        
        int a = 0, val, curr_sum = 0, max_sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'A') a++;
            val = s[i] == 'G' ? 1 : -1;
            
            curr_sum = max(curr_sum + val, val);
            max_sum = max(max_sum, curr_sum);
        }
        
        max_sum = max(max_sum, 0);
        
        if (max_sum == 0) cout << (a-1) << endl;
        else cout << (a + max_sum) << endl;
    }
}