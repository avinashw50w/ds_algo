/*find the smallest length subarray whose sum is greater than K*/
// NOTE: only works if all elements of the array are +ve
int solve(vector<int> a, int K) {
    int n = a.size(), sum = 0, ans = n;
    for (int start = 0, end = 0, end < n; ++end) {
        sum += a[end];
        while (start < end and sum > K) {
            ans = min(ans, end - start + 1);
            sum -= a[start++];
        }
    }
    return ans;
}
/// another way of implementation
int solve(vector<int> a, int K) {
	int n = a.size();
	int sum = 0, start = 0, end = 0;
	int min_len = n;
	while (end < n) {
		while (sum <= K and end < n) sum += a[end++];
		while (sum > K and start < end) {
			min_len = min(min_len, end - start);
			sum -= a[start++];
		}
	}

	return min_len;
}

///////////////////////////
/* this will handle both +ve and -ve nos
 IDEA: use deque
 */
const int inf = 1e9;
int solve(vector<int> a, int k) {
    int n = a.size(), ans = inf;
    deque<int> d;
    for (int i = 0; i < n; ++i) {
    	if (i) a[i] += a[i-1];
    	if (a[i] > k) 
    		ans = min(ans, i + 1);
    	while (d.size() and a[i] - a[d.front()] > k) {
    		ans = min(ans, i - d.front());
    		d.pop_front();
    	}
        // sum(i) - sum(j) > k
        // we are trying to minimize sum(i) here
    	while (d.size() and a[i] <= a[d.back()]) {
    		d.pop_back();
    	}
    	d.push_back(i);
    }
    return ans;
}
int main(){ 
    vector<int> a = {1, -1, 2, 1, 1 };
    cout << solve(a, 3);
}