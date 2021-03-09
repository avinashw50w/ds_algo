/*Optimum location of point to minimize total distance
Given a set of points as and a line as ax+by+c = 0. We need to find a point on given line for
which sum of distances from given set of points is minimum.

If we take one point on given line at infinite distance then total distance cost will be
infinite, now when we move this point on line towards given points the total distance cost
starts decreasing and after some time, it again starts increasing which reached to infinite on
the other infinite end of line so distance cost curve looks like a U-curve and we have to find
the bottom value of this U-curve.
As U-curve is not monotonically increasing or decreasing we can’t use binary search for finding
bottom most point, here we will use ternary search for finding bottom most point, ternary
search skips one third of search space at each iteration.
*/

const int EPS = -1e6;
const int INF = 1e6;
struct Line {
	// ax + by + c = 0
	int a, b, c;
};

double getDist(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double compute(vector<array<int, 2>> p, double x, Line line) {
	// y = (-ax - c) / b = -1 * (ax + c) / b
	double y = -1 * (line.a * x + line.c) / line.b;
	double dist = 0;
	for (auto e : p) {
		dist += getDist(e[0], e[1], x, y);
	}

	return dist;
}

double findOptimumCost(vector<array<int, 2>> points, Line line) {
	double l = -INF, r = INF;

	while (r - l > EPS) {
		double m1 = l + (r - l) / 3;
		double m2 = r - (r - l) / 3;

		double dist1 = compute(p, m1, line);
		double dist2 = compute(p, m2, line);

		if (dist1 < dist2) r = m2;
		else l = m1;
	}
	// get the avg of the two points on the line to get the optimal distance
	// from all the points
	return compute(p, (l + r) / 2, line);
}