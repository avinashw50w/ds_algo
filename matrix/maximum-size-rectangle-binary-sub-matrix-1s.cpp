/*Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s.
Example:

Input:
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
Output :
1 1 1 1
1 1 1 1
Explanation :
The largest rectangle with only 1's is from
(1, 0) to (2, 3) which is
1 1 1 1
1 1 1 1 */

int maxHist(vector<int> hist) {
    stack<int> s;
    int area, max_area = 0, i = 0, top, n = hist.size();

    while (i < n) {

        if (s.empty() or hist[s.top()] <= hist[i]) s.push(i++);

        else {
            top = s.top(); s.pop();
            area = hist[top] * (s.empty() ? i : i - 1 - s.top());
            max_area = max(max_area, area);
        }
    }
    while (!s.empty()) {
        top = s.top(); s.pop();
        area = hist[top] * (s.empty() ? i : i - 1 - s.top());
        max_area = max(max_area, area);
    }
    return max_area;
}
/*----------------------------------------------------*/
/*You are required to complete this method*/
int maxArea(vector<vector<int>> mat)
{
    int n = mat.size(), m = mat[0].size();
    int res = maxHist(M[0], m);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (M[i][j])
                M[i][j] += M[i - 1][j];

            res = max(res, maxHist(M[i], m));
        }
    }

    return res;
}
/*----------------------------------------------------*/
// if matrix is not allowed to change
int maxArea(vector<vector<int>> mat) {
    int n = mat.size(), m = mat[0].size();
    vector<int> t(m);
    int ans = -inf;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j]) t[j] += 1;
            else t[j] = 0;
        }
        ans = max(ans, maxHist(t));
    }
}