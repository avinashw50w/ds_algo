/*given an array find for each element it's next greater element on the right side of it*/

vector<int> nextGreater(vector<int> a) {
    int n = a.size();
    // res[i] stores the index of next greater element of a[i]
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() and a[st.top()] < a[i]) {
            // here we store the index of next greater element,
            // we can also store the next greater element, res[st.top()] = a[i]
            res[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    return res;
}

vector<int> nextSmaller(vector<int> a) {
    int n = a.size();
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() and a[st.top()] > a[i]) {
            res[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    return res;
}

////////////////////////////////////////////////////////////////
// another way
// next greater
vector<int> nextGreater(vector<int> a) {
    int n = a.size();
    // res[i] stores the index of next greater element of a[i]
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = n-1; i >= 0; --i) {
        while (!st.empty() and a[i] > a[st.top()]) {
            st.pop();
        }
        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return res;
}
