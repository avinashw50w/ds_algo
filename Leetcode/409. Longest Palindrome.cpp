/*Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.



Example 1:

Input: s = "abccccdd"
Output: 7
Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.*/

int longestPalindrome(string s) {
    unordered_map<char, int> f;
    int n = s.size();
    for (char c : s) f[c]++;
    int cnt = 0;
    bool odd = false;
    for (auto e : f) {
        cnt += (e.second >> 1) * 2;
        if (e.second & 1) odd = true;
    }

    if (odd) cnt++;
    return cnt;
}