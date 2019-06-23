/*A string contains only R and K. Flip exactly one subarray such that the no of Rs is maximized

Flipping means
 if S[X]='R' :  //If character at position X is 'R' then change it to 'K'
      S[X]='K'  
 else :          //else if character at position X is 'K' then change it to 'R'
      S[X]='R'
Now your goal is that after exactly one move you have to obtain the maximum number of R's as RK loves this character very much. So help RK with maximum R's.

Input :
The first line contains the number of test cases T. Each test case contains a string S consisting of characters 'R' and 'K' only.

Output :
For each test case print the maximal number of R's that can be obtained after exactly one move.

Constraints: 
1<=T<=10 
1<=|S| <=10^6 (length of string)*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    string s;
    cin >> t;

    while (t--) {
        cin >> s;

        int r = 0, sum = 0, mx = 0;
        for (int i = 0; i < s.size(); ++i) {
            r += (s[i] == 'R');
            int x = (s[i] == 'K' ? 1 : -1);
            sum = max(sum+x, x);
            mx = max(mx, sum);
        }

        mx = max(mx, 0);
        // there has to be atleast 1 move
        // so if there are only R's in the string, then flip a single R
        cout << (r + (mx == 0 ? -1 : mx)) << endl;
    }
}