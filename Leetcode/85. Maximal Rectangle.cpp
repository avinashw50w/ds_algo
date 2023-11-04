/*Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle 
containing only 1's and return its area.*/
class Solution {
public:
    int maxhist(vector<int> a) {
        int i = 0, n = a.size(), ans = 0;
        stack<int> st;
        while (i < n) {
            if (st.empty() or a[st.top()] <= a[i]) st.push(i++);
            else {
                int top = st.top();
                st.pop();
                int area = a[top] * (st.empty() ? i : i - 1 - st.top());
                ans = max(ans, area);
            }
        }
        while (st.size()) {
            int top = st.top();
            st.pop();
            int area = a[top] * (st.empty() ? i : i - 1 - st.top());
            ans = max(ans, area);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& mat) {
        if (mat.empty()) return 0;
        if (mat[0].empty()) return 0;
        int n = mat.size(), m = mat[0].size();
        vector<int> t(m);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == '1') t[j] += 1;
                else t[j] = 0;
            }
            ans = max(ans, maxhist(t));
        }
        
        return ans;
    }
};