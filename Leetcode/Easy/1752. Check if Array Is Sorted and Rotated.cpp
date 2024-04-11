/*Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

*/
class Solution {
public:
    bool check(vector<int>& a) {
        int bad = 0, n = a.size();
        for (int i = 0; i < n-1; ++i) {
            if (a[i] > a[i+1]) bad++;
        }
        if (a[n-1] > a[0]) bad++;

        return bad <= 1;
    }
};