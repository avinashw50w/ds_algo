/*A N x N matrix is filled with numbers. BuggyD is analyzing the matrix, and he wants the sum of certain submatrices every now and then, 
so he wants a system where he can get his results from a query. Also, the matrix is dynamic, and the value of any cell can be changed with 
a command in such a system.

Assume that initially, all the cells of the matrix are filled with 0. Design such a system for BuggyD. Read the input format for further details.

Input

The first line of the input contains an integer t, the number of test cases. t test cases follow.

The first line of each test case contains a single integer N (1 <= N <= 1024), denoting the size of the matrix.

A list of commands follows, which will be in one of the following three formats (quotes are for clarity):

"SET x y num" - Set the value at cell (x, y) to num (0 <= x, y < N).
"SUM x1 y1 x2 y2" - Find and print the sum of the values in the rectangle from (x1, y1) to (x2, y2), inclusive. You may assume that x1 <= x2 
and y1 <= y2, and that the result will fit in a signed 32-bit integer.
"END" - Indicates the end of the test case.
Output

For each test case, output one line for the answer to each "SUM" command. Print a blank line after each test case.

Example

Input:
1
4
SET 0 0 1
SUM 0 0 3 3
SET 2 2 12
SUM 2 2 2 2
SUM 2 2 3 3
SUM 0 0 2 2
END

Output:
1
12
12
13*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1030;

int bit[MAXN][MAXN], a[MAXN][MAXN];
int R, C;

void update(int r, int c, int val) {
	for(int i=r; i<=R; i+= i&-i) {
		for(int j=c; j<=C; j+=j&-j)
			bit[i][j] += val;
	}
}

int sum(int r, int c) {
	int ret = 0;
	for(int i=r; i>0; i-=i&-i) {
		for(int j=c; j>0; j-=j&-j)
			ret += bit[i][j];
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t, N, x1, y1, x2, y2, val;
	string s;
	cin >> t;
	while(t--) {
		cin >> N;
		R = C = N;

		memset(bit, 0, sizeof(bit));
		memset(a,0,sizeof(a));

		while(cin >> s) {
			if(s.compare("SET") == 0) {
				cin >> x1 >> y1 >> val;
				x1++; y1++;
				update(x1, y1, val - a[x1][y1]);
				a[x1][y1] = val;
			}
			else if(s.compare("SUM") == 0) {
				cin >>x1 >> y1 >> x2 >> y2;
				x1++; y1++; x2++; y2++;
				int res = 0;

				res += sum(x2, y2);
				res -= sum(x1-1, y2);
				res -= sum(x2, y1-1);
				res += sum(x1-1, y1-1);

				cout << res << "\n";
			}
			else break;
		}
	}
}
