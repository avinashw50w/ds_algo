/*Count the # of subarray having sum less than k*/
// IDEA: use merge sort
// prefix[i] : prefix sum upto index i
// prefix[j] - prefix[i] <= k for any subarray [i+1, j]
// prefix[i] - prefix[j] >= k for any subarray [i+1, j]

int ans;
int k;

void merge(vector<int> &a, int l, int mid, int r) {
    int i = l, j = mid + 1, k = 0;
    vector<int> t(r-l+1);

    while (i <= mid and j <= r) {
        if (a[i] >= a[j]) {
            if (a[i] >= a[j] + k) {
                ans += mid - i + 1;
                t[k++] = a[j++];
            }
        }
        else {
            t[k++] = a[i++];
        }
    }

    while (i <= mid) t[k++] = a[i++];
    while (j <= r) t[k++] = a[j++];
    
    for (int i = 0; i < k; ++i) a[l + i] = t[i];
}

void mergeSort(vector<int> &a, int l, int r) {
    if (l < r) {
        int mid = (l+r)>>1;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

int solve(vector<int> &a, int K) {
    k = K;
    for (int i = 1; i < a.size(); ++i) a[i] += a[i-1];
    ans = 0;
    mergeSort(a, 0, a.size() - 1);
    return ans;
}

// NOTE: a[i] should be non-negative for this to work
// O(n)
int solve(vector<int> a, int k) {
    int n = a.size();
    int cnt = 0, sum = 0;
    int start = 0, end = 0;
    while (start < n and end < n) {
        if (sum < k) {
            end++;
            if (end >= start) cnt += end - start;
            if (end < n) sum += a[end];
        }
        else {
            sum -= a[start++];
        }
    }
    return cnt;
}