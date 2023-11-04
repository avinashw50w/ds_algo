/*Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

 

Example 1:

Input: "ab-cd"
Output: "dc-ba"
Example 2:

Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"*/

class Solution {
    bool isAlpha(char c) {
        c = tolower(c);
        return ('a' <= c and c <= 'z');
    }
public:
    string reverseOnlyLetters(string S) {
        int l = 0, r = S.size();
        
        while (l < r) {
            if (!isAlpha(S[l])) l++;
            else if (!isAlpha(S[r])) r--;
            else {
                swap(S[l++], S[r--]);
            }
        }
        
        return S;
    }
};