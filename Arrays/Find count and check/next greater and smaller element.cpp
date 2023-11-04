/*given an array find for each element it's next greater element on the right side of it*/

// res[i] stores the index of the next greater element of a[i]
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

// another way to find nextGreater
vector<int> nextGreater(vector<int> a) {
    int n = a.size();
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() and a[st.top()] <= a[i]) {
            res[st.top()] = i;
            st.pop();
        }
        res[i] = -1;
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

////////////////////////////////////////////////////////////////
// find the subrray size where a[i] is maximum. Find such subarray size of all elements of arr.
// for an element a[i], count the # of ele <= a[i] on each side until a greater element is 
// found. Let l be the # of such elements on the left side and r to be on its right side.
// then subarray size = (l + r + 1);

void countLeftAndRightSmaller(vector<int> a) {
    int n = a.size();
    stack<int> st;
    vector<int> cntLeftSmaller(n, 0), countRightSmaller(n, 0);

    for (int i = 0; i < n; ++i) {
        while (!st.empty() and a[i] > a[st.top()]) {
            int idx = st.top(); st.pop();
            countRightGreater[idx] = i - idx;
        }
        countLeftGreater[i] = st.size();
        st.push(i);
    }
}

void solve(vector<int> a) {
    int n = a.size();

    findLeftAndRightGreater(a);
    findLeftAndRightSmaller(a);
}