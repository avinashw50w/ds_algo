/*We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Return a list of all uncommon words. 

You may return the list in any order.

 

Example 1:

Input: A = "this apple is sweet", B = "this apple is sour"
Output: ["sweet","sour"]*/

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> mp;
        vector<string> res;
        
        stringstream ss(A);
        
        while (ss) {
            string tk;
            ss >> tk;
            mp[tk]++;
        }
                
        ss.clear();
        ss.str(B);
        
        while(ss) {
            string tk;
            ss >> tk;
            mp[tk]++;
        }
        
        for (auto i: mp)
            if (i.second == 1) res.push_back(i.first);
        
        return res;
    }
};