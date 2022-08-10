
int find(int a[], int n) {

    unordered_set<int> st;
    int ans = a[n - 1];

    for (int i = 0; i < n; ++i) {
        if (st.count(a[i])) {
            return a[i];
        }
        st.insert(a[i]);
    }

    return ans;
}