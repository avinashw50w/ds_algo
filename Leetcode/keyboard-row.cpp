/*Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.

 



 
Example:

Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]*/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        unordered_set<char> key[3];
        key[0] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        key[1] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        key[2] = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        
        for (string w: words) {
            char c = tolower(w[0]);
            int i, j;
            for (i = 0; i < 3; ++i) {
                if (key[i].count(c)) break;
            }
            
            for (j = 1; j < w.size(); ++j) 
                if (key[i].count(tolower(w[j])) == 0) break;
            
            if (j == w.size()) res.push_back(w);
        }
        
        return res;
    }
};