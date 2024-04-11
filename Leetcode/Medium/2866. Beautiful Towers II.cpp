/*You are given a 0-indexed array maxHeights of n integers.

You are tasked with building n towers in the coordinate line. The ith tower is built at coordinate i and 
has a height of heights[i].

A configuration of towers is beautiful if the following conditions hold:

1 <= heights[i] <= maxHeights[i]
heights is a mountain array.
Array heights is a mountain if there exists an index i such that:

For all 0 < j <= i, heights[j - 1] <= heights[j]
For all i <= k < n - 1, heights[k + 1] <= heights[k]
Return the maximum possible sum of heights of a beautiful configuration of towers.

1 <= n == maxHeights <= 105
1 <= maxHeights[i] <= 109

IDEA: we need construct a mountain like pattern in the resulting array and return the total sum of the array.
Pick every index i from left to right and treat it as the peak of the mountain, and keep calculating
and storing the total sum in left array
Do the same from right to left and store it in right array.
Finally ans = max(left[i] + right[i] - maxHeights[i]) for all i in [0, n-1]
*/
class Solution {
    typedef long long ll;
public:
    vector<ll> leftsum(vector<int> a) {
        int n = a.size();
        vector<ll> left(n, 0);
        stack<int> st;
        ll sum = 0;
        st.push(-1);
        // 1 1 4 3 5
        for (int i = 0; i < n; ++i) {
            while (st.size() > 1 and a[st.top()] > a[i]) {
                int j = st.top(); st.pop();
                sum -= (j - st.top()) * (ll)a[j];
            }
            sum += (i - st.top()) * (ll)a[i];
            st.push(i);
            left[i] = sum;
        }
        return left;
    }

    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<ll> left = leftsum(maxHeights);
        reverse(maxHeights.begin(), maxHeights.end());
        vector<ll> right = leftsum(maxHeights);
        reverse(right.begin(), right.end());
        reverse(maxHeights.begin(), maxHeights.end());

        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, left[i] + right[i] - maxHeights[i]);
        }

        return ans;
    }
};