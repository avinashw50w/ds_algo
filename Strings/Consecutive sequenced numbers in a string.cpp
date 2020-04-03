/*Consecutive sequenced numbers in a string
Given a string that contains only numeric digits, we need to check whether that strings contains numbers in consecutive sequential manner in increasing order.

Note: Negative numbers are not considered part of this problem. So we consider that input only contains positive integer.

Examples:

Input :  str = "1234"
Output : Yes 
         1
Explanation : 
There are 1, 2, 3, 4 which are 
consecutive and in increasing order.
And the starting number is 1

Input :  str = "91012"
Output : No
Explanation : 
There are no such sequence in the
string. 

Input :  str = "99100"
Output : Yes 
         99
Explanation : The consecutive sequential 
numbers are 99, 100

Input :  str = "010203"
Output : NO 
Explanation : 
Although at first glance there seems to
be 01, 02, 03. But those wouldn't be 
considered a number. 01 is not 1  it's 0, 1 */

#include <bits/stdc++.h>
using namespace std;

typedef uint64_t ll;

ll toInteger(string &s) {
    ll v;  
    stringstream str(s);
    str >> v;
    return v;
}

string toString(ll v) {
    stringstream str;
    str << v;
    return str.str();
}

ll solve(string s) {
    int n = s.size();
    
    for (int i = 0; i < n/2; ++i) {
        
        string first = s.substr(0, i+1);
        
        ll num = toInteger(first);
        ll start = num;
        
        while (first.size() < n) {
            num++;
            
            first += toString(num);
        }
        
        if (first == s) {
            return start;
        }
    }
    
    return -1;
}

int main() {
    int T; cin >> T;
    string s;
    
    while(T--) {
        cin >> s;
        ll ans = solve(s);
        if (ans != -1) {
            cout << "YES " << ans << endl;
        } else {
            cout << "NO\n";
        }
    }
}
