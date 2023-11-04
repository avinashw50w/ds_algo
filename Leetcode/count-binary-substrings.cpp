/*Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

Example 1:
Input: "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".*/

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        
        if (n == 1) return 0;
        int ans = 0;
        
        for (int i = 1; i < n; ++i) {
            int l = i-1, r = i, cnt = 0;
            char c = s[r];
            while (l >= 0 and r < n) {
                if (s[r] == c and s[r] != s[l]) cnt++;
                else break;
                l--; r++;
            }
    
            ans += cnt;
        }
        
        return ans;
    }
};

///////////////////////////////////////////////////
// Time: O(N), space: O(N)
// group by character

int countBinarySubstrings(string s) {
    int n = s.size();
    int group[n] = {0};
    int t = 0;
    group[0] = 1;

    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i-1]) group[++t] = 1;
        else group[t]++;
    }

    int ans = 0;
    for (int i = 1; i < t; ++i)
        ans += min(group[i], group[i-1]);

    return ans;
}

//////////////////////////////////////////////
// Time: O(N), space: O(1)
// Linear scan

class Solution {
    public int countBinarySubstrings(String s) {
        int ans = 0, prev = 0, cur = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i-1]) {
                ans += Math.min(prev, cur);
                prev = cur;
                cur = 1;
            } else {
                cur++;
            }
        }
        return ans + min(prev, cur);
    }
}
