/*Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

 

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]*/

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int N = A.size();
        unordered_map<char,int> m[N];
        vector<string> res;
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < A[i].size(); ++j)
                m[i][A[i][j]]++;
        }
        
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        
        for (int i = 0; i < A[0].size(); ++i) {
            char c = A[0][i];
            cnt[c-'a'] = m[0][c];
            for (int j = 1; j < N; ++j) {
                cnt[c-'a'] = min(cnt[c-'a'], m[j][c]);
            }
        }
        
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < cnt[i]; ++j)
                res.push_back(string(1, i+'a'));
        
        return res;
    }
};