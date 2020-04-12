/*Little monk loves good string. Good String is a string that only contains vowels (a,e,i,o,u). Now, his teacher gave him a string S. Little monk is wondering what is the length of the longest good string which is a substring of S.

Note: Strings contains only lower case English Alphabets.

Input:
First line contains a string S, 1 <= |S| <= 10^5, where S denotes the length of the string.

Output:
Print an integer denoting the length of the longest good substring, that is substring consists of only vowels.

SAMPLE INPUT 
abcaac
SAMPLE OUTPUT 
2
Explanation
Longest Good String which is a substring of S is  so the answer is 2.*/

#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char c) {
    char v[] = {'a', 'e', 'i', 'o', 'u'};

    for (int i = 0; i < 5; ++i) if (c == v[i]) return true;

    return false;
}

int main() {
    string s; 
    cin >> s;

    int n = s.size();

    int ans = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (is_vowel(s[i])) {
            cnt++;
        }
        else {
            ans = max(ans, cnt);
            cnt = 0;
        }
    }

    ans = max(ans, cnt);

    cout << ans << "\n";
}