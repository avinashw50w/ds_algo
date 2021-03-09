/*There is an infinite two-dimensional grid, and we have a piece called Super Ryuma at square
(r1, c1). (Ryu means dragon and Ma means horse.) In one move, the piece can go to one of the
squares shown below:
-------------------------------------
|	  -					  -			|
|		-				-			|
|		  -		-	  -				|
|		    - - - - -  				|
|		    - - - - -  				|
|		  - - - - - - -  			|
|		    - - - - -  				|
|		    - - - - -  				|
|		  -		-	  -				|
|		-				-			|
|	  -					  -			|
|	-						-		|
-------------------------------------
More formally, when Super Ryuma is at square (a,b),it can go to square (c,d)
such that at least one of the following holds:
a - b = c - d 	  // means on forward diagonal
a + b = c + d     // on backward diagonal
|a - c| + |b - d| <= 3   // within manhattan distance of 3
*/

/*
IDEA:
Case 1: if the dest is the same as the start then no of moves m = 0
Case 2: if the dest is within manhattan distance of 3 or on the same diagonal then m = 1
Case 3: if the dest can be reached by two diagonal moves, or manhattan distance from start
		is <= 6, or one diagonal move and one move over the manhattan distance of 3
		then no of moves m = 2
Case 4: the maximum no of moves required is 3 to reach the dest
 */

int solve(int x1, int y1, int x2, int y2) {
	if (x1 == x2 and y1 == y2) return 0;
	if (x1 - y1 == x2 - y2 or x1 + y1 == x2 + y2 or abs(x1 - x2) + abs(y1 - y2) <= 3)
		return 1;

	if (abs(x1 - x2) + abs(y1 - y2) <= 6) return 2;

	// to reach from src to dest using two diagonal moves, requires
	// that the two diagonals intersect at some point, so if src is (x1, y1) and dest is (x2,y2)
	// the eq is : x - y = x1 - y1
	//             x + y = x2 + y2
	// adding both the equations: 2x = x1 + x2 - y1 + y2
	// it means that for x to be an integer x1 + x2 - y1 + y2 should be even
	if ((x1 + x2 - y1 + y2) % 2 == 0) return 2;

	// iterate over all the points within the manhattan distance of 3 and
	// for each point check if any diagonal move can lead to dest
	for (int d = 1; d <= 3; ++d) {
		for (int x = x1 - d; x <= x1 + d; ++x) {
			int k = abs(x - x1);
			int y = y1 + k;

			if (x - y == x2 - y2 or x + y == x2 + y2) return 2;

			y = y1 - k;

			if (x - y == x2 - y2 or x + y == x2 + y2) return 2;
		}
	}

	return 3;
}

///////////////////////////////////////
// another recursive approach

int solve(int x1, int y1, int x2, int y2) {
	int x = abs(x1 - x2), y = abs(y1 - y2);
	int p = (x1 + x2), q = (y1 + y2);
	if (x == 0 and y == 0) return 0;
	if (x == y or p == q) return 1;
	return 2;
}

/*
dx, dy is the first movement over the manhatten distance
px, py is the second movement over the manhatten distance
if either of dx or dy has non zero value then it means we moved over the manhattan distance of 3, then we need to add 1, similarly for px and py
After movement over the manhatten distance we need to check whether the src and dest lies on
the same diagonal, if yes then return 1, otherwise return 2(because we need two diagonal
movements)
 */
int calc() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int ans = INF;
	for (dx = -3; dx <= 3; ++dx) {
		for (int dy = -3; dy <= 3; ++dy) {
			if (abs(dx) + abs(dy) > 3) continue;
			for (int px = -3; px <= 3; ++py) {
				for (int py = -3; py <= 3; ++py) {
					if (abs(px) + abs(py) > 3) continue;
					int ret = solve(a + dx, b + dy, c + px, d + py) + (dx or dy) + (px or py);
					ans = min(ans, ret);
				}
			}
		}
	}
	return ret;
}