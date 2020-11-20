/*Subarray whose sum is closest to K
Given an array of positive and negative integers and an integer K.
The task is to find the subarray which has its sum closest to k. In case of multiple answers, print any one.
Note: Closest here means abs(sum-k) should be minimal.
sum(A[0..i-1]) - sum(A[0..j]) ~ K
*/

int solve(vector<int> a, int K) {
    int n = a.size();
    set<int> st;
    int curr_sum = 0, ans, mini = INT_MAX;

    for (int i = 0; i < n; ++i) {
        curr_sum += a[i];
        // find prev_sum >= curr_sum - K
        auto it = st.lower_bound(curr_sum - K);

        if (it != st.end()) {
            int prev_sum = *it;
            if (abs(curr_sum - prev_sum - K) < mini) {
                mini = abs(curr_sum - prev_sum - K);
                ans = curr_sum - prev_sum;
            }

            // also check for the one before that
            // since the sum can be greater than
            // or less than K also
            if (it != st.begin()) {
                --it;
                prev_sum = *it;
                if (abs(curr_sum - prev_sum - K) < mini) {
                    mini = abs(curr_sum - prev_sum - K);
                    ans = curr_sum - prev_sum;
                }
            }
        }
        else {
            if (abs(curr_sum - K) < mini) {
                mini = abs(curr_sum - K);
                ans = curr_sum;
            }
        }
        st.insert(a[i]);
    }

    return ans;
}

// Driver Code
int main()
{
    int a[] = { -5, 12, -3, 4, -15, 6, 1 };
    int n = sizeof(a) / sizeof(a[0]);
    int k = 2;

    cout << solve(a, n, k);
    return 0;
}

// Time Complexity: O(N log N)
