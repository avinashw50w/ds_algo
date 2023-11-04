/*Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2*/

int missingNumber(vector<int>& nums) {
    int x = 0;
    for (int i = 0; i <= nums.size(); ++i) x ^= i;
    for (int i : nums) x ^= i;

    return x;
}