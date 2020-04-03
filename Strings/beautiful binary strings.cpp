/*Alice has a binary string. She thinks a binary string is beautiful if and only if it doesn't contain the substring 010.

In one step, Alice can change a 0 to 1  or vice versa. Count and print the minimum number of steps needed to make 
Alice see the string as beautiful.

For example, if Alice's string is b=010 she can change any one element and have a beautiful string.*/

#include <bits/stdc++.h>
using namespace std;

string s;
int n;
int ans = 0;


int main() {
    cin >> n; cin >> s;
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0' and s[i+1] == '1' and s[i+2] == '0') {
            s[i+2] = '1';
            ans++;
        }
    }
    
    cout << ans << endl;
}

