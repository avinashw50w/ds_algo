/*given an array of points, count all possible rectangles that can be formed from them.
eg.  1	 2	 3
	 4   5   6

ans = 3
*/

struct Point {
	int x, y;
};

int solve(vector<Point> points) {
	unordered_map<pair<int, int>, int> cnt;
	int ans = 0;

	for (Point p : points) {
		for (Point p_above : points) {
			// for all the points above p in the same vertical line
			if (p.x == p_above.x and p.y < p_above.y) {
				pair<int, int> pair_y = { p.y, p_above.y };
				ans += m[pair_y];
				m[pair_y]++;
			}
		}
	}

	return ans;
}