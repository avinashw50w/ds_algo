/*Check if all subarrays contains at least one unique element
Given an array arr[] consisting of N integers, the task is to check if all subarrays of the array have at least one unique element in it or not. If found to be true, then print “Yes”. Otherwise, print “No”.

Examples:

Input: arr[] = {1, 2, 1}
Output: Yes
Explanation:
For Subarrays of size 1: {1}, {2}, {1}, the condition will always be true.
For Subarrays of size 2: {1, 2}, {2, 1}, each subarray has at least one unique element.
For Subarrays of size 3 = {1, 2, 1}, in this subarray we have 2 as the only unique element.
Since each subarray has at least one unique element, print “Yes”.

Input: arr[] = {1, 2, 3, 1, 2, 3}
Output: No
Explanation:
Subarrays of size 6: {1, 2, 3, 1, 2, 3} contains no unique element. Therefore, print “No”.
*/

bool solve(vector<int> a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        unordered_map<int,int> mp;
        int count = 0;
        for (int j = i; j < n; ++j) {
            mp[a[j]]++;
            if (mp[a[j]] == 1) count++;
            else if (mp[a[j]] == 2) count--;

            if (count == 0) return false;
        }
    }
    return true;
}