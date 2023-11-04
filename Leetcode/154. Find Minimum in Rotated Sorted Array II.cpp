/*Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

 

Example 1:

Input: nums = [3,1,1,1,1]
Output: 1*/
// worst O(n)
class Solution {
public:
    int findMin(vector<int>& a) {
        int l = 0, r = a.size() - 1;
        while (l < r) {
            int mid = l + (r-l)/2;
            if (a[mid] < a[r]) r = mid;
            else if (a[mid] > a[r]) l = mid + 1;
            else r--;
        }
        
        return a[l];
    }
};

// recursive
int solve(vector<int> a, int l, int r) {
    if (l == r) return a[l];
    if (l + 1 == r) return min(a[l], a[r]);
    if (a[l] < a[r]) return a[l];
    int mid = (l + r) >> 1;
    if (a[l] == a[mid] and a[l] == a[r]) {
        return min(solve(a, l + 1, mid), solve(a, mid + 1, r));
    }
    if (a[l] <= a[mid]) return solve(a, mid + 1, r);
    return solve(a, l + 1, mid);
}

int findMin(vector<int> &a) {
    solve(a, 0, a.size() - 1);
}