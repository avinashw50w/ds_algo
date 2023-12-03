/*You are given a 0-indexed array of positive integers nums and a positive integer limit.

In one operation, you can choose any two indices i and j and swap nums[i] and nums[j] if 
|nums[i] - nums[j]| <= limit.

Return the lexicographically smallest array that can be obtained by performing the operation any number of times.

An array a is lexicographically smaller than an array b if in the first position where a and b differ, 
array a has an element that is less than the corresponding element in b. For example, the array [2,10,3] 
is lexicographically smaller than the array [10,2,3] because they differ at index 0 and 2 < 10.

IDEA: if nums[i] - nums[j] <= limit and nums[j] - nums[k] <= limit, then (i, j, k) can be interchanged
with each other by swapping

So we need to group pairs (i, j) such that nums[i] - nums[j] <= limit, and then sort each of the groups,
then rearrange the group elements based on the original order

ind  0 1  2 3  4  5
eg.  2 12 4 15 10 1 // sort it
     1  2 4 10 12 15 // divide in groups
     1  2 4|10 12 15 // rearrange the groups in original array in the sorted order
     1 10 2 12 15 4

*/
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& a, int limit) {
        int n = a.size();
        vector<array<int,2>> v;
        for (int i=0; i<n; ++i) {
            v.push_back({a[i], i});
        }

        sort(v.begin(), v.end());

        vector<vector<array<int,2>>> groups = {{v[0]}};
        for (int i = 1; i < n; ++i) {
            if (v[i][0] - v[i-1][0] <= limit) 
                groups.back().push_back(v[i]);
            else
                groups.push_back({v[i]});
        }

        for (auto group: groups) {
            vector<int> ind;
            for (auto e: group) {
                ind.push_back(e[1]);
            }
            sort(ind.begin(), ind.end());
            for (int i = 0; i < group.size(); ++i) {
                a[ind[i]] = group[i][0];
            }
        }

        return a;
    }
};