void solve(vector<int> a) {
    int n = a.size();
    int first = INT_MAX, second = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (a[i] < first) {
            second = first;
            first = a[i];
        }
        else if (second > a[i] and a[i] > first) {
            second = a[i];
        }
    }

    cout << first << " " << second;
}

///////////////////////////////////