/*Given a dictionary of words and a string s. Find the min no of character to delete from the string s so that the string exists in the dictionary*/

int solve(string s, int N, set<string> dict) {
    int n = s.size();

    if (dict.count(s)) return N-n;

    int res = INT_MAX;

    for (int i = 0; i < n; ++i) {
        string newStr = s.substr(0, i) + s.substr(i+1, n-i);
        if (newStr.size()) {
            int t = solve(newStr, N, dict);

            if (t != INT_MAX) res = min(res, t);
        }
    }

    return res;
}

// Using BFS
int BFS(string s, set<string> dict) {
    unordered_set<string> st;
    queue<string> q;
    q.push(s);
    st.insert(s);

    while(!q.empty()) {
        string top = q.front();
        int n = top.size();
        q.pop();

        string newStr;
        for (int i = 0; i < n; ++i) {
            newStr = top.substr(0, i) + top.substr(i+1, n-i);
            if (dict.count(newStr)) return (s.size() - newStr.size());
            if (st.count(newStr) or newStr.size() == 0) continue;
            q.push(newStr);
            st.push(newStr);
        }
    }

    return -1;
}

int main() {
    set<string> dict = {"a", "aa", "aaa", "ac" };
    string s = "abc";
    cout << solve(s, s.size(), dict);
}