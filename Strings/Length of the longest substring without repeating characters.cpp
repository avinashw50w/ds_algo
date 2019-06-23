#include <bits/stdc++.h>
using namespace std;


int findLen(string s) {

	int N = s.size();
	if(N == 0) return 0;

	int vis[256];
	memset(vis, -1, sizeof(vis));
	vis[s[0]] = 0;

	int i, len = 1, maxlen = 1, start, end, l = 0;

	for(i = 1; i < N; ++i) {
		// get the prev index of the current character
		int prevIdx = vis[s[i]];
		vis[s[i]] = i;
		// if this current character was visited before 
		// and it lies in the the current window
		if(prevIdx != -1 and l <= prevIdx) {

			if(i-l > maxlen) {
				maxlen = i-l;
				start = l;
				end = i-1;
			}

			l = prevIdx+1;
		}
	}
	if(i-l > maxlen) {
		maxlen = i-l;
		start = l;
		end = i-1;
	}

	string ans = s.substr(start, end-start+1);

	cout << ans << endl;

	return maxlen;
}


int main() {

	string s = "ABDEFGABEF";

	cout << findLen(s) << endl;
}