/*If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.*/

class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size();
        int i = n-2;
        // find i from the end such that a[i] < a[i+1]
        while (i >= 0 and a[i] >= a[i+1]) i--;

        // if no such i is present means that the number is maximum
        // return the lowest permutation
        if (i <= -1) {
            sort(a.begin(), a.end());
            return;
        }

        // find the smallest number in the range [i+1, n-1] which is greater than a[i]
        int smallest = i+1;
        for (int j = i + 2; j < n; ++j) {
            if (a[j] > a[i] && a[j] < a[smallest]) {
                smallest = j;
            }
        }

        // swap that number with a[i]
            swap(a[i], a[smallest]);

        // sort the range [i+1, n-1]
        sort(a.begin() + i+1, a.end());

    }
};