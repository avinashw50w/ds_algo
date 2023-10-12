/*Given a string, find the longest substring with K unique characters.*/

string solve(string s, int k) {
    int n = s.length();
    unordered_map<char, int> mp;
    int len = 0;

    for (int start = 0, end = 0; start < end; ++end) {
        mp[s[end]]++;
        while (mp.size() > k) {
            mp[s[start]]--;
            if (mp[s[start]] == 0) mp.erase(s[start]);
            start++; 
        }

        if (mp.size() == k) len = max(len, end - start + 1);
    }

    return s.substr(start, len);
}
