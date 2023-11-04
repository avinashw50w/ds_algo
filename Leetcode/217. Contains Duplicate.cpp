/*Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true*/

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, bool> mp;
    for (int e : nums) {
        if (mp.count(e)) return true;
        mp[e] = true;
    }

    return false;
}