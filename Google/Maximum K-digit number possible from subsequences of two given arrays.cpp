/*Maximum K-digit number possible from subsequences of two given arrays
Difficulty Level : Hard
Last Updated : 16 Nov, 2020
Given two arrays arr1[] and arr2[] of length M and N consisting of digits [0, 9] representing two numbers and an integer K(K ≤ M + N), the task is to find the maximum K-digit number possible by selecting subsequences from the given arrays such that the relative order of the digits is the same as in the given array.

Examples:

Input: arr1[] = {3, 4, 6, 5}, arr2[] = {9, 1, 2, 5, 8, 3}, K = 5
Output: 98653
Explanation: The maximum number that can be formed out of the given arrays arr1[] and arr2[] of length K is 98653.*/

// returns a non increasing array of length "len"
vector<int> maxNumeberOfLen(int len, vector<int> a) {
    int n = a.size();
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        // while the last element in res is less than the current element
        // and there are enough elements on the right to fill the required length of "len",
        // then pop back the last element
        while (res.size() and res.back() < a[i] and n - i > len - res.size()) {
            res.pop_back();
        }
        if (res.size() < len) {
            res.push_back(a[i]);
        }
    }
    return res;
}

int solve(vector<int> a1, vector<int> a2) {
    int n = a1.size(), m = a2.size();
    int ans = 0;

    for(int i = 0; i < min(k, n); ++i) {
        vector<int> x = maxNumberOfLen(i, a1);
        vector<int> y = maxNumberOfLen(k-i, a2);

        // merge them to form a non-increasing vector (ie, the maximum # possible)
        vector<int> res;
        int l = 0, r = 0;
        while (l < x.size() and r < y.size()) {
            if (x[l] >= y[r]) res.push_back(x[l++]);
            else res.push_back(y[r++]);
        }
        int num = 0;
        for (int e: res) {
            num = num * 10 + e;
        }
        // update the answer
        ans = max(ans, num);
    }

    return ans;
}