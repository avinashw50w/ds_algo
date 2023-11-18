/*Given an array a. Find the maximum number of non-overlapping subarrays such that the sum of the subarray equals to K. */

int solve(vector<int> a, int target) {
    int n = a.size(), ans = 0;
    unordered_set<int> st;
    int sum = 0;
    st.insert(0); // when sum = target

    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (st.count(sum - target)) {
            ans++;
            st.clear();
        }
        st.insert(sum);
    }

    return ans;
}