/*Find the sum of the lengths of all the subarrays having all elements distinct. */

#include <iostream>
#include <set>
using namespace std;

const int maxn = 1e5 + 5;
int t, n, a[maxn];
set<int> s;

int main() {
	cin >> t; 
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; ++i) cin >> a[i];

		int i = 0, j = 0;
		s.clear();

		long long ans = 0;

		while(i < n) {
			while(j < n and s.find(a[j]) == s.end()) {
				s.insert(a[j]);
				j++;
			}

			ans += (1LL * (j-i) * (j-i+1)) >> 1;

			s.erase(a[i]);
			i++;
		}

		cout << ans << endl;
	}
}