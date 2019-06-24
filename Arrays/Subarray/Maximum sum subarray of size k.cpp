/*Given an array A of size N, find the subarray of size k which has the maximum sum. */

tuple<int,int,int> solve(vector<int> A) {
    int N = A.size();
    int i, l, r, sum = 0, max_sum = INT_MIN;

    for (i = 0; i < k; ++i) sum += A[i];

    max_sum = sum;
    l = 0; r = k-1;

    for (; i < N; ++i) {
        sum -= A[i-k];
        sum += A[i];
        if (max_sum < sum) {
            max_sum = sum;
            l = i-k+1;
            r = i;
        }
    }

    return make_tuple(max_sum, l, r);
}