
int find(int a[], int n) {

    unordered_set<int> st;
    int ans = a[n - 1];

    for (int i = n - 1; i >= 0; --i) {
        if (st.count(a[i])) {
            ans = i;
        }
        st.insert(a[i]);
    }

    return ans;
}