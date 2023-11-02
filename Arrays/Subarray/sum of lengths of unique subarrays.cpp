/*Find the sum of the lengths of all the subarrays having all elements distinct. */
// eg. [1,2,3], then the subarrays containing distinct elements are: 1,2,3,12,23,123
// which is 1 + 2 + 3 = 6
#include <iostream>
#include <set>
using namespace std;

const int maxn = 1e5 + 5;
int t, n, a[maxn];
set<int> s;

int solve(vector<int> a) {
	int sum = 0, n = a.size();
	unordered_map<int, int> mp;
	for (int st = 0, end = 0; end < n; ++end) {
		while (end < n and mp[a[end]] == 0) {
			mp[a[end]]++;
			sum += end - st + 1;
			end++;
		}
		mp[a[st]]--;
		st++;
	}

	return sum;
}