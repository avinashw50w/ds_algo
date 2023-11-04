/*Given an array of integers heights representing the histogram's bar height where the width of
 each bar is 1, return the area of the largest rectangle in the histogram.

*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        if (n == 0) return 0;
        int ans = 0, i = 0;
        while (i < n) {
            if (st.empty() or heights[st.top()] <= heights[i]) st.push(i++);
            else {
                int top = st.top(); st.pop();
                int area = st.empty() ? heights[top] * i : heights[top] * (i - 1 - st.top());
                ans = max(ans, area);
            }
        }
        
        while (st.size()) {
            int top = st.top(); st.pop();
                int area = st.empty() ? heights[top] * i : heights[top] * (i - 1 - st.top());
                ans = max(ans, area);
        }
        
        return ans;
    }
};