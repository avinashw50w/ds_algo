/*find max diff bw two elements a[i] and a[j] of an array such that j > i  */
#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> a = {5,1,6,9,10,3,7};

	int ans = a[1] - a[0];
	int mini = a[0];
	for(int i = 1; i < a.size(); ++i){
		ans = max(ans, a[i]-mini);
		mini = min(mini, a[i]);
	}

	cout << ans << endl;
}