/*1) Create an empty stack.

2) Start from first bar, and do following for every bar ‘hist[i]’ where ‘i’ varies from 0 to n-1.
……a) If stack is empty or hist[i] is higher than the bar at top of stack, then push ‘i’ to stack.
……b) If this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater. 
Let the removed bar be hist[tp]. Calculate area of rectangle with hist[tp] as smallest bar. For hist[tp], the ‘left index’ 
is previous (previous to tp) item in stack and ‘right index’ is ‘i’ (current index).

3) If the stack is not empty, then one by one remove all bars from stack and do step 2.b for every removed bar.*/

class Solution {
public:
    int largestRectangleArea(vector<int>& hist) {
        int n = hist.size();
        stack<int> st;
        int maxarea = 0;

        for (int i = 0; i <= n; ++i) {
            while (!st.empty() and (i == n or hist[st.top()] >= hist[i])) {
                int height = hist[st.top()]; st.pop();
                int width;
                if (st.empty()) width = i;
                else width = i-1 - st.top();

                maxarea = max(maxarea, height * width);
            }
            st.push(i);
        }

        return maxarea;
    }
};

////////////////////////////////////////////////////////////////
// another way

int getMaxArea(vector<int> hist) {
	int n = hist.size();
	stack<int> st;
	int max_area = 0, i = 0;

	while (i < n) {
		while (st.empty() or hist[st.top()] <= hist[i]) st.push(i++);

		int top = st.top();
		st.pop();
		int area = hist[top] * (st.empty() ? i : i - 1 - st.top());

		max_area = max(max_area, area);
	}

	while (!st.empty()) {
		int top = st.top();
		st.pop();
		int area = hist[top] * (st.empty() ? i : i - 1 - st.top());

		max_area = max(max_area, area);
	}

	return max_area;
}