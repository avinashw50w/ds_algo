/*Given two arrays a1 and a2. check whether a2 is a subset of a1.
eg. a1 = 11 1 13 21 3 7
a2 = 11 3 7 1
ans = yes
*/
// brute force: check whether all the elements of a2 exists in a1
bool check(vector<int> a1, vector<int> a2) {
	for (int i = 0; i < a2.size(); ++i) {
		int j;
		for (j = 0; j < a1.size(); ++j) {
			if (a2[i] == a1[j]) break;
		}
		if (j == a1.size()) return false;
	}

	return true;
}
// using sorting
bool check(vector<int> a1, vector<int> a2) {
	sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end());
	int j = 0;

	for (int i = 0; i < a1.size(); ++i) {
		if (a1[i] == a2[j]) j++;
	}

	return j == a2.size();
}

// use hashing
bool check(vector<int> a1, vector<int> a2) {
	unordered_map<int, int> mp;
	for (int e : a1) mp[e]++;
	string ans = "YES";
	for (int e : a2) if (!mp.count(e)) { ans = "NO"; break; }
	return ans;
}