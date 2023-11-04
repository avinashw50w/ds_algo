/*Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if (n == 1) return true;
        
        int up = 0, lw = 0;
        
        for (int i = 0; i < n; ++i) {
            char c = word[i];
            if (islower(c)) lw++;
            else up++;
        }
    
        if (islower(word[0]) and lw == n) return true;
        if (isupper(word[0]) and up == n) return true;
        if (isupper(word[0]) and lw == n-1) return true;
        
        return false;
    }
};