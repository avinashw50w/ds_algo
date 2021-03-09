/*Given an array a of size n. Find the no of pair of elements to be decreased by 1 such that
n-1 elements becomes 0 and only one element is > 0.
contraints:
ai >= 0
*/

int solve(vector<int> a) {
    set<int> st;
    for (int e: a) st.insert(e);
    int cnt = 0;
    while (st.size() > 1) {
        int a = *st.begin(); 
        st.erase(st.begin());

        int b = *st.begin();
        st.erase(st.begin());

        --a; --b;
        if (a < 0 or b < 0) return -1;
        cnt++;
    }
    return cnt;
}