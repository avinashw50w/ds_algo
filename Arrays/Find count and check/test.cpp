#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s) {
	stringstream ss(s);
	vector<string> res;
	string t;
	while (ss) {
		ss >> t;
		res.push_back(t);
	}
	return res;
}

vector<string> solve(vector<string> logs, int t) {
	int n = logs.size();
	vector<string> ans;
	map<string, int> mp;
	for (string s : logs) {
		vector<string> parts = split(s);
		mp[parts[0]]++;
		if (parts[0] != parts[1]) mp[parts[1]]++;
	}
	for (auto e : mp) {
		if (e.second >= t) ans.push_back(e.first);
	}

	return ans;
}

int main() {
	vector<string> logs {"1 2 50", "1 7 70", "1 3 20", "2 2 17"};
	vector<string> ans = solve(logs, 2);
	for (auto s : ans) cout << s << endl;
}