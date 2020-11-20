/*Given two arrays a1 and a2. check whether a2 is a subset of a1.
eg. a1 = 11 1 13 21 3 7
a2 = 11 3 7 1
ans = yes
*/
// using sorting
bool check(vector<int> a1, vector<int> a2) {
	sort(a1.begin(), a1.end());
	string ans = "YES";

	for (int i = 0; i < a2.size(); ++i) {
		int id = lower_bound(a1.begin(), a1.end(), a2[i]) - a1.begin();
		if (a1[id] != a2[i]) {
			ans = "NO";
			break;
		}
	}

	return ans;
}

// use hashing
bool check(vector<int> a1, vector<int> a2) {
	unordered_map<int, int> mp;
	for (int e : a1) mp[e]++;
	string ans = "YES";
	for (int e : a2) if (!mp.count(e)) { ans = "NO"; break; }
	return ans;
}