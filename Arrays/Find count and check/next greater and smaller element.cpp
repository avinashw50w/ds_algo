/*given an array find for each element it's next greater element on the right side of it*/

vector<int> nextGreater(vector<int> a) {
    int n = a.size();
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = n-1; i >= 0; --i) {
        while (!st.empty() and a[st.top()] <= a[i]) st.pop();
        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return res;
}

vector<int> nextSmaller(vector<int> a) {
    int n = a.size();
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = n-1; i >= 0; --i) {
        while (!st.empty() and a[st.top()] >= a[i]) st.pop();
        
        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return res;
}

vector<int> prevGreater(vector<int> a) {
    int n = a.size();
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() and a[st.top()] <= a[i]) st.pop();
        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return res;
}

vector<int> prevSmaller(vector<int> a) {
    int n = a.size();
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() and a[st.top()] >= a[i]) st.pop();

        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return res;
}