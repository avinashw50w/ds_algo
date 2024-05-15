/*You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.

Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]

Output: [0,9]

Explanation:

The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
The output order does not matter. Returning [9,0] is fine too.

Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]

Output: []

Explanation:

There is no concatenated substring.*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length(), wlen = words.back().size(), k = wlen * words.size();
        map<string,int> wmap, smap;
        vector<int> res;
        
        for (auto e: words) {
            wmap[e]++;
        }
        for (int i = 0; i + k - 1 < n; ++i) {
            smap.clear();
            bool flag = true;
            for (int j = 0; j < k; j += wlen) {
                string subs = s.substr(i + j, wlen);
                if (wmap.count(subs) == 0) {
                    flag = false;
                    break;
                }
                smap[subs]++;
            }

            if (flag and wmap == smap) {
                res.push_back(i);
            }
        }

        return res;
    }
};