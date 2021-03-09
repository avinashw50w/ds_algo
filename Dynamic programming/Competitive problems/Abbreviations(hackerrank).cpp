/*You can perform the following operations on the string, a:

- Capitalize zero or more of a's lowercase letters.
- Delete all of the remaining lowercase letters in a.
Given two strings, a and b, determine if it's possible to make a equal to b as described. 
If so, print YES on a new line. Otherwise, print NO.*/

#include <bits/stdc++.h>

using namespace std;

set<string> dp;
bool possible;

void solve(string a, string b) {
    if (possible or a.size() < b.size()) return;
    if (b.empty()) {
        bool all_lower = true;
        for (char c: a) if (!islower(c)) {
            all_lower = false;
            break;
        }
        if (all_lower) {
            possible = true;
            return;
        }
    }
    auto p = dp.insert(a + "#" + b);
    if (!p.second) return;
    
    char c = a[0];

    if (islower(c)) solve(a.substr(1), b);
    if (toupper(c) != b[0]) return;
    
    solve(a.substr(1), b.substr(1));
}

// Complete the abbreviation function below.
string abbreviation(string a, string b) {
    dp.clear();
    possible = false;    
    solve(a,b);    
    return possible ? "YES" : "NO";
}
