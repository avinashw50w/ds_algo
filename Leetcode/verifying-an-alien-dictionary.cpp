/**In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

 

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted./

class Solution {
    unordered_map<char,int> mp;
    
    bool cmp(string a, string b) {
        int i;
        for (i = 0; i < min(a.size(), b.size()); ++i) {
            if (mp[a[i]] < mp[b[i]]) return 0;
            else if (mp[a[i]] > mp[b[i]]) return 1;
        }
        
        return a.size() > b.size();
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int cnt = 1, n = words.size();
        for (char c: order) mp[c] = cnt++;
        
        for (int i = 0; i < n-1; ++i) {
            if (cmp(words[i], words[i+1]) == 1) return false;
        }
        
        return true;
    }
};