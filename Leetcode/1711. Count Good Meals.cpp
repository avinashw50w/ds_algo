/*A good meal is a meal that contains exactly two different food items with a sum of 
deliciousness equal to a power of two.

You can pick any two different foods to make a good meal.

Given an array of integers deliciousness where deliciousness[i] is the deliciousness of the i​​​​​​th​​​​​​​​ 
item of food, return the number of different good meals you can make from this list modulo 109 + 7.

Note that items with different indices are considered different even if they have the same deliciousness value.
Constraints:

1 <= deliciousness.length <= 10^5
0 <= deliciousness[i] <= 2^20*/
class Solution {
    typedef long long ll;
    const int mod = 1e9 + 7;
public:
    
    int countPairs(vector<int>& a) {
        vector<int> twos;

        for (int i = 0; i < 22; ++i) {
            twos.push_back(1 << i);
        }
        
        map<int, int> mp;
        int ans = 0;
        
        for(int i = 0; i < a.size(); ++i) {
            for (ll e: twos) {
                if (mp.count(e - a[i])) 
                    ans += mp[e-a[i]], ans %= mod;
            }  
            mp[a[i]]++;
        }
        
        return ans;
    }
};