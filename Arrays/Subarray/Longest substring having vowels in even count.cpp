/*Given a string s, find the length of the longest substring in which every vowel must appear an even
no of times. NOTE: 0 is also even

eg. eghafaty,
ans = 7, hafaty, a appears 2 times
eg 2> bcbcbc
ans = 6, vowel appears 0 times

sol: use bitmask
for every vowel, xor it's position with the mask
eg. if a appears, xor position 1 with 1
if e appears, xor position 2 with 1

so we need a substring whose mask is 0. Let mask[i] be the mask until index i
then for substring [i..j] to be 0
mask[j] xor mask[i-1] = 0
or mask[j] = mask[i-1]
*/

int solve(string s) {
    unordered_map<char,int> v;
    v['a'] = 0;
    v['e'] = 1;
    v['i'] = 2;
    v['o'] = 3;
    v['u'] = 4;

    int ans = 0;
    unordered_map<int,int> mp;
    int mask = 0;
    mp[0] = 0;
    
    for (int i = 0; i < s.size(); ++i) {
        if (v.count(s[i]))
            mask ^= 1<<v[s[i]];

        if (mp.count(mask) == 0)
            mp[mask] = i;
        else
            ans = max(ans, i - mp[mask]);
    }

    return ans;
}
