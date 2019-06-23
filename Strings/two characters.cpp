/*String t always consists of two distinct alternating characters. For example, if string t's two distinct characters are x and y, 
then t could be xyxyx or yxyxy but not xxyy or xyyx.

You can convert some string s to string t by deleting characters from s. When you delete a character from s, 
you must delete all occurrences of it in s. For example, if s = abaacdabd and you delete the character a, 
then the string becomes bcdbd.

Given , convert it to the longest possible string . Then print the length of string  on a new line; 
if no string  can be formed from , print  instead.

Input Format

The first line contains a single integer denoting the length of . 
The second line contains string .

Constraints

s only contains lowercase English alphabetic letters (i.e., a to z).
*/

/*choose any two distinct characters and remove the occurence of all other characters from the string and then check if the
remianing string is alternate or not. */

#include <bits/stdc++.h>
using namespace std;


int main() {
    int N; cin>>N;
    string s; cin>>s;
    
    int cnt, f, ans = 0;
    for (int i = 0; i < 26; ++i) 
    {
        for (int j = 0; j < 26; ++j) 
        {
            if (i != j) 
            {
                int c1 = i, c2 = j;
                cnt = 0, f = 1;

                for (char c : s) 
                {
                    if (c != c1+'a' and c != c2+'a') continue;
                    
                    if (c == c1+'a') { cnt++; swap(c1, c2); }
                    else f = 0;
                }

                if (f and cnt > 1) ans = max(ans, cnt);
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}
