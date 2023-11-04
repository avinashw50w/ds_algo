/*It is a variation of find-next-greater-number-with-the-same-set-of-digits. */

class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size();
        int i = n-2;
        // find i from the end such that a[i] < a[i+1]
        while (i >= 0 and a[i] >= a[i+1]) i--;

        // if no such i is present means that the number is maximum
        // return the lowest permutation
        if (i <= -1) {
            sort(a.begin(), a.end());
            return;
        }

        // find the smallest number in the range [i+1, n-1] which is greater than a[i]
        int smallest = i+1;
        for (int j = i + 2; j < n; ++j) {
            if (a[j] > a[i] && a[j] < a[smallest]) {
                smallest = j;
            }
        }

        // swap that number with a[i]
            swap(a[i], a[smallest]);

        // sort the range [i+1, n-1]
        sort(a.begin() + i+1, a.end());

    }
};

int main() {
	int t, n; cin>>t;
	while(t--) {
	    cin>>n;
	    int a[n+1];
	    for(int i=0;i<n;++i) cin>>a[i];
	    solve(a, n);
	}
	return 0;
}