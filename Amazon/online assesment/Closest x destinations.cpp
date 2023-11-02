/*
Given a list of N possible delivery destinations, implement an algorithm to find the closest X destinations from origin(0, 0).
If there is one tie, use the location with the closest X coordinate.
Example
Input
allLocations = [ [1,2], [3,4], [1,-1]]
numDeliveries = 2

Output
[ [1,-1], [1,2]]

Explaination
The distance of the truck from loaction [1,2] is square root(5) = 2.236.
The distance of the truck from loaction [3,4] is square root(25) = 5.
The distance of the truck from loaction [1,-1] is square root(2) = 1.414.

numDeliveries is 2, hence the output is [1,-1] and [1,2].
*/

// one simple solution is to sort all the destination based on their distance. T: O(nlogn)

// T: O(nlogx);

int distanceFromOrigin(vector<int> a) {
	return a[0] * a[0] + a[1] * a[1];
}

auto cmp = [](auto &a, auto &b) {
	int adist = distanceFromOrigin({a[0], a[1]});
	int bdist = distanceFromOrigin({b[0], b[1]});
	if (adist == bdist) return a[0] < b[0];
	return adist < bdist;
}

vector<vector<int>> solve(vector<vector<int>> dest, int x) {
	int n = dest.size();
	set<array<int, 2>, decltype(cmp)> st(cmp);

	for (int i = 0; i < x; ++i) {
		int x = dest[i][0], y = dest[i][1];
		st.insert({x, y});
	}

	for (int i = x; i < n; ++i) {
		auto top = st.begin();
		if (distanceFromOrigin(dest[i]) < distanceFromOrigin({*top[0], *top[1]})) {
			st.erase(top);
			st.insert(dest[i]);
		}
	}

	vector<vector<int>> res;	
	for (auto e: st) {
		res.push_back(e);
	}

	return res;
}