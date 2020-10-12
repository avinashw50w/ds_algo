/*design a data structure to perform insert, delete and getRandom in O(1) time. */

class Solution {
    unordered_map<int, int> mp;
    vector<int> a;

public:
    void insert(int x) {
        if (mp.count(x)) return;
        a.push_back(x);
        mp[x] = a.size() - 1;
    }

    void delete(int x) {
        if (mp.count(x) == 0) return;
        int last = a.back();
        a.pop_back();
        a[mp[x]] = last;
        mp[last] = mp[x];
        mp.erase(x);
    }

    void update(int oldVal, int newVal) {
        if (mp.count(oldVal) == 0) return;
        int pos = mp[oldVal];
        a[pos] = newVal;
        mp.erase(oldVal);
        mp[newVal] = pos;
    }

    int getRandom() {
        return a[rand() % a.size()];
    }
};