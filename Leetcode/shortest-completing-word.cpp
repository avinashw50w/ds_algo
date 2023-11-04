/*Find the minimum length word from a given dictionary words, which has all the letters from the string licensePlate. Such a word is said to complete the given string licensePlate

Here, for letters we ignore case. For example, "P" on the licensePlate still matches "p" on the word.

It is guaranteed an answer exists. If there are multiple answers, return the one that occurs first in the array.

The license plate might have the same letter occurring multiple times. For example, given a licensePlate of "PP", the word "pair" does not complete the licensePlate, but the word "supper" does.

Example 1:
Input: licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
Output: "steps"
Explanation: The smallest length word that contains the letters "S", "P", "S", and "T".
Note that the answer is not "step", because the letter "s" must occur in the word twice.*/

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        
        unordered_map<char, int> M;
        for (char c: licensePlate) {
            c = tolower(c);
            if ('a' <= c and c <= 'z') M[c]++;
        }
        string ans; 
        int mn = INT_MAX;
        for (string word: words) {
            
            unordered_map<char, int> m;
            for (char c: word) m[c]++;
            int cnt = 0;
            for (auto i: M) {
                if(m.count(i.first) and m[i.first] >= i.second) cnt++;
            }
            
            if (cnt == M.size()) {
                if (word.size() < mn) {
                    mn = word.size();
                    ans = word;
                }
            }
        }
        
        return ans;
    }
};