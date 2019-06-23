/* Check whether a string s contains "hackerrank" as its subsequence. */

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int n = s.length();
        
        string hack = "hackerrank";
        int pt = 0;
        
        for(int i = 0; i < n; ++i) {
            if(s[i] == hack[pt]) pt++;
        }
        
        puts(pt == 10 ? "YES" : "NO");
    }
    return 0;
}
