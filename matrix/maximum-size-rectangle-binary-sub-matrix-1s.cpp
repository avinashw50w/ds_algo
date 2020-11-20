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

int maxHist(int hist[], int n) {
    stack<int> s;
    int area, max_area = 0, i = 0, top;

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
int maxArea(int M[MAX][MAX], int n, int m)
{
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