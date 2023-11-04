/*Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"*/

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u'
               or c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U';
    }

    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (!isVowel(s[l])) l++;
            else if (!isVowel(s[r])) r--;
            else swap(s[l++], s[r--]);
        }
        return s;
    }
};