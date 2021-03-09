// length of longest increasing subsequence in O(nlogn)
// for strictly increasing subsequence
/*=========================================================*/
void LIS(int a[], int n) {
    multiset<int> st; multiset<int>::iterator it; st.clear();
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
        it = st.find(a[i]);
        it++;
        if (it != st.end()) st.erase(it);
    }
    cout << st.size();
}
/*==========================================================*/
// for strictly increasing subsequence
int LIS(vector<int> a) {
    int n = a.size();
    vector<int> v;
    v.push_back(a[0]);

    for (int i = 1; i < n; ++i) {
        if (v.back() < a[i]) v.push_back(a[i]);
        else {
            int pos = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            v[pos] = a[i];
        }
    }

    return v.size();
}

/*==========================================================*/
// the longest non-decreasing subsequence
// eg, for 1 1 1 1 => ans = 4
int LIS(vector<int> a) {
    int n = a.size();
    vector<int> v;

    for (int i = 0; i < n; ++i) {
        int pos = upper_bound(v.begin(), v.end(), a[i]) - v.begin();
        if (pos < v.size()) v[pos] = a[i];
        else v.push_back(a[i]);
    }

    return v.size();
}

int main() {
    int arr[] = {6, 5, 5, 7, 11, 8, 10, 13, 6};
    int n = sizeof arr / sizeof arr[0];
    LIS(arr, n);
}
