/*Given a string, find the longest substring with K unique characters.*/

string solve(string s, int k) {
    int n = s.length();
    unordered_map<char, int> mp;

    int start = 0, len = 0;

    for (int i = 0; i < n; ++i) {
        mp[s[i]]++;
        while (mp.size() > k) {
            mp[s[start]]--;
            if (mp[s[start]] == 0) mp.erase(s[start]);
            start++;
        }

        if (mp.size() == k) len = max(len, i - start + 1);
    }
    return s.substr(start, len);
}

