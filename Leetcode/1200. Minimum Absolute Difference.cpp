/*Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr


Example 1:

Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.*/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& a) {
        sort(a.begin(), a.end());
        vector<vector<int>> res;
        int diff = INT_MAX;

        for (int i = 1; i < a.size(); ++i) {
            diff = min(diff, abs(a[i] - a[i - 1]));
        }

        for (int i = 1; i < a.size(); ++i) {
            if (abs(a[i] - a[i - 1]) == diff)
                res.push_back(vector<int> {a[i - 1], a[i]});
        }

        return res;
    }
};