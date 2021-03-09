/*You are given n activities with their start and finish times.
Select the maximum number of activities that can be performed by a single person,
assuming that a person can only work on a single activity at a time.

IDEA: to process maximum no of activities, we should sort the activities by finish times
*/

void solve(vector<pair<int, int>> activities) {
	int n = activities.size();

	sort(activities.begin(), activities.end(),
	[](auto & a, auto & b) { return a.second < b.second; });

	int ans = 1, j = 0;
	for (int i = 1; i < n; ++i) {
		if (activities[j].finish <= activities[i].start) {
			ans++;
			j = i;
		}
	}

	return ans;
}

////////////////////////////////////////////////////////////////
// to also print the activities
void solve(vector<pair<int, int>> activities) {
	int n = activities.size();
	vector<array<int, 3>> v;
	for (int i = 0; i < n; ++i)
		b.push_back({activities[i].first, activities[i].second, i});


	sort(v.begin(), v.end(),
	[](auto & a, auto & b) { return a[1] < b[1]; });

	cout << v[0][2] << " ";
	int j = 0;

	for (int i = 1; i < n; ++i) {
		if (v[j][1] <= v[i][0]) {
			cout << v[i][2] << " ";
			j = i;
		}
	}
}