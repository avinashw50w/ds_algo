/*Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []*/

class Solution {
    unordered_map<char, string> mp;
    vector<string> ans;
public:
    void solve(string digits, string t, int idx) {
        if (idx == digits.size()) {
            ans.push_back(t);
            return;
        }
        for (char c: mp[digits[idx]]) {
            t += c;
            solve(digits, t, idx + 1);
            t.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        solve(digits, "", 0);

        return ans;
    }
};