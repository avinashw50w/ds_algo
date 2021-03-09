/*Two strings are anagrams of each other if the letters of one string can be rearranged to
form the other string. Given a string, find the number of pairs of substrings of the string
that are anagrams of each other.
constraints:
1 ≤ q ≤ 10
2 ≤ len of s ≤ 100
*/

int sherlockAndAnagrams(string s) {
    int n = s.length();
    map<string, int> mp;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            string s2 = s.substr(i, j - i + 1);
            sort(s2.begin(), s2.end());
            ans += mp[s2];
            mp[s2]++;
        }
    }

    return ans;
}