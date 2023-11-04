/*Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]*/

vector<int> intersection(vector<int>& a, vector<int>& b) {
    unordered_map<int, int> f;
    for (int e : a) f[e]++;

    vector<int> res;
    for (int e : b) if (f[e]) res.push_back(e), f[e] = 0;

    return res;
}

////////////////////////////////////////

vector<int> intersection(vector<int>& a, vector<int>& b) {
    set<int> st;
    vector<int> res;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0;
    while (i < a.size() and j < b.size()) {
        if (a[i] < b[j]) i++;
        else if (a[i] > b[j]) j++;
        else {
            st.insert(a[i]);
            i++; j++;
        }
    }

    for (int e : st) res.push_back(e);
    return res;
}