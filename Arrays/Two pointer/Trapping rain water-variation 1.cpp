/*Given an array a of n elements, where a[i] represents the height of buildings.
Choose any two buildings i and j such that after removing all the building except
i and j, the amount of water trapped btw the building i and j is maximum.
summary: need to find the maximum value of min(a[i], a[j]) * (j - i - 1)
IDEA: use two pointer approach,
set l = 0 and r = n-1
increment l if height[l] < height[r] This is because the water that can be trapped is
dependent on the height of the small building which is height[l] * (r-l-1),
so if we decrease r then (r-l-1) will decrease.
else decrement r if height[r] < height[l]
otherwise increment l and decement r
*/
// time complexity : O(N)
int solve(vector<int> height) {
	int n = height.size();
	int ans = 0, l = 0, r = n - 1;
	while (l < r) {
		if (height[l] < height[r]) {
			ans = max(ans, height[l] * (r - l - 1));
			l++;
		}
		else if (height[r] < height[l]) {
			ans = max(ans, height[r] * (r - l - 1));
			r--;
		}
		else {
			ans = max(ans, height[l] * (r - l - 1));
			l++;
			r--;
		}
	}

	return ans;
}

//////////////////////////////////////////
// sorting the array

int solve(vector<int> a) {
	int n = a.size();
	pair<int, int> p[n];
	for (int i = 0; i < n; ++i) {
		p[i].first = a[i];
		p[i].second = i;
	}

	int ans = 0;
	sort(p, p + n);

	int minIndexSofar = p[n - 1].second, maxIndexSofar = p[n - 1].second;

	for (int i = n - 2; i >= 0; --i) {
		// find a building greater in height such that its index is less than the
		// current building, ie, the building lies on the left side of current building
		int left = 0;
		if (minIndexSofar < p[i].second) {
			left = p[i].first * (p[i].second - minIndexSofar - 1);
		}

		// similarly find a building greater in height such that it's index is greater than
		// the current building, ie, lies on the right side of it
		int right = 0;
		if (maxIndexSofar > p[i].second) {
			right = p[i].first * (maxIndexSofar - p[i].second - 1);
		}

		ans  = max(ans, max(left, right));

		minIndexSofar = min(minIndexSofar, p[i].second);
		maxIndexSofar = max(maxIndexSofar, p[i].second);
	}

	return ans;
}

