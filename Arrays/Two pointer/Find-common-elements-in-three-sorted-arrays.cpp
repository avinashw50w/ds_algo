/*Given three arrays sorted in non-decreasing order, print all common elements in these arrays.

Examples:

ar1[] = {1, 5, 10, 20, 40, 80}
ar2[] = {6, 7, 20, 80, 100}
ar3[] = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20, 80

ar1[] = {1, 5, 5}
ar2[] = {3, 4, 5, 5, 10}
ar3[] = {5, 5, 10, 20}
Output: 5, 5  */
// This function prints common elements in ar1

vector<int> findCommon(vector<int> a, vector<int> b, vector<int> c) {
    int n1 = a.size(), n2 = b.size(), n3 = c.size();
    int i = 0, j = 0, k = 0;
    // duplicates may come, so store the common elements in set
    set<int> st;
    vector<int> res;
    while (i < n1 and j < n2 and c < n3) {
        if (a[i] == b[j] and b[j] == c[k]) {
            st.insert(a[i]);
            i++; j++; k++;
        }
        else if (a[i] < b[j]) i++;
        else if (b[j] < c[k]) j++;
        else k++;
    }

    for (int e : st) res.push_back(e);
    return res;
}
/*Time complexity of the above solution is O(n1 + n2 + n3). In worst case, the largest sized
array may have all small elements and middle sized array has all middle elements.*/
