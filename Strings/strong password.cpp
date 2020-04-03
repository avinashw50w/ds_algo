/*Louise joined a social networking site to stay in touch with her friends. The signup page required her to input a name and a password. However, the password must be strong. The website considers a password to be strong if it satisfies the following criteria:

Its length is at least 6.
It contains at least one digit.
It contains at least one lowercase English character.
It contains at least one uppercase English character.
It contains at least one special character. The special characters are: !@#$%^&*()-+
She typed a random string of length n in the password field but wasn't sure if it was strong. Given the string she typed, can you find the minimum number of characters she must add to make her password strong?

Note: Here's the set of types of characters in a form you can paste in your solution:

numbers = "0123456789"
lower_case = "abcdefghijklmnopqrstuvwxyz"
upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
special_characters = "!@#$%^&*()-+"
Input Format

*/

#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int solve(int n, string s) {
    int ans = 0, dig = 0, low = 0, cap = 0, sym = 0, less = 0;
    if (n < 6) less += 6-n;
    
    
    for (int i = 0; i < n; ++i) {
        if ('0' <= s[i] and s[i] <= '9') dig = 1;
        else if ('a' <= s[i] and s[i] <= 'z') low = 1;
        else if ('A' <= s[i] and s[i] <= 'Z') cap = 1;
        else 
            sym = 1;
    }
    
    int cnt = 4 - (dig + low + cap + sym);
    
    return max(cnt, less);
}

int main()
{
    int n; cin >> n;
    
    string s; cin >> s;
    
    cout << solve(n, s) << endl;
}
