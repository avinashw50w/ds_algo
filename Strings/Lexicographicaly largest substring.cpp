/*find the lexicographicaly largest substring*/
string maxSubstring(string s) {
    set<string> st;
    int n = s.size();

    for (int l = 1; l <= n; ++l) {
        for (int i = 0; i <= n - l; ++i) {
            int j = i + l - 1;

            st.insert(s.substr(i, l));
        }
    }

    return *st.rbegin();
}

// another for loop variation
for (int i = 0; i < n; ++i)
    for (int j = i; j < n; ++j)
        st.insert(s.substr(i, j - i + 1));