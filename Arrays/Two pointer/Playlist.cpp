
/**You are given a playlist of a radio station since its establishment. The playlist has a total of n songs.

What is the longest sequence of successive songs where each song is unique?

Input

The first input line contains an integer n: the number of songs.

The next line has n integers k1,k2,…,kn: the id number of each song.

Output

Print the length of the longest sequence of unique songs.

Constraints
1≤n≤2⋅105
1≤ki≤109
Example

Input:
8
1 2 1 3 2 7 4 2

Output:
5
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	map<int, int> mp;
	int ans = 0, cnt = 0;
	
	for (int start = 0, end = 0; start < n; ++start) {
		while (end < n and mp[a[end]] == 0) {
			mp[a[end]]++;
			end++;
		}
	
		ans = max(ans, end - start);
		mp[a[start]]--;
	}
	
	cout << ans << "\n";
}