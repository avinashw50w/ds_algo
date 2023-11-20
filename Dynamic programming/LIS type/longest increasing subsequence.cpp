/*Find the longest strictly increasing subsequence in an array of integers.*/

vector<int> lis(vector<int> a) {
    vector<int> v;
    for (int e: a) {
        int pos = lower_bound(a.begin(), a.end()) - a.begin();
        if (pos < v.size()) v[pos] = e;
        else v.push_back(e);
    }
    return v;
}

// find the longest non decreasing subsequence
// eg. 2 3 3 7 10
// same as above, just used upper bound instead of lower bound
vector<int> lis(vector<int> a) {
    vector<int> v;
    for (int e: a) {
        int pos = upper_bound(a.begin(), a.end()) - a.begin();
        if (pos < v.size()) v[pos] = e;
        else v.push_back(e);
    }
    return v;
}
