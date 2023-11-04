/*Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) 
subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.
Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int N = arr.size();
        stack<int> st; // store index of arr
        long long ans = 0;
        for (int i = 0; i <= N; ++i) {
            while (!st.empty() && (i==N||arr[i] < arr[st.top()])){
                int tmpi = st.top();
                st.pop();
                int tmpi1 = st.empty() ? -1 : st.top();
                // all the subarrays in range [tmpi1, i] including tmpi has arr[tmpi] as minimum value. 
                // So, there are (tmpi-tmpi1)*(i-tmpi) subarrays where arr[tmpi] is minimum
                ans += arr[tmpi] * (long long)(tmpi-tmpi1)*(i-tmpi);
            }
            st.push(i);
        }
        ans = ans % (int)(1e9 + 7);
        return (int)ans;
    }
};

// similar problem: 2104

