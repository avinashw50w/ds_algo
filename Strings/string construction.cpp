/*Amanda has a string of lowercase letters that she wants to copy to a new string. She can perform the following
 operations with the given costs. She can perform them any number of times to construct a new string p:

Append a character to the end of string p at a cost of 1 dollar.
Choose any substring of p and append it to the end of p at no charge.
Given n strings s[i], find and print the minimum cost of copying each s[i] to p[i] on a new line.

For example, given a string s=abcabc, it can be copied for 3 dollars. Start by copying a, b and c 
individually at a cost of dollar per character. String p=abc at this time. 

Explanation: we basically need only unique characters for cost of 1 and then we can use those characters 
to construct the remaining string*/

#include <bits/stdc++.h>
using namespace std;

int stringConstruction(string s) {
    int n = s.size();
    int f[26] = {}, ans = 0;
    
    for (int i = 0; i < n; ++i) {
        f[s[i]-'a']++;
    }
    
    for (int i = 0; i < 26; ++i) 
        if (f[i]) ans++;
    
    return ans;

}