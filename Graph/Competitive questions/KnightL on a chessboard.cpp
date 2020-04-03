/*is a chess piece that moves in an L shape. We define the possible moves of Knight(a,b) as any
movement from some position (x1,y1) to some (x2,y2) satisfying either of the following:
1. x2 = x1 + a or x1 - a,  and  y2 = y1 + b or y1 - b, 
or
2. x2 = x1 + b or x1 - b and y2 = y1 + a or y1 - a

Note that (a,b) and (b,a) allow for the same exact set of movements. 
Given the value of n for an nxn chessboard, answer the following question for each (a,b) pair where : 1 <= a,b < n
What is the minimum number of moves it takes for KnightL(a,b) to get from position (0,0) to position (n-1,n-1) ? 
If it's not possible for the Knight to reach that destination, the answer is -1 instead.
Then print the answer for each according to the Output Format specified below.
Input Format
A single integer denoting n.
Constraints
5 <= n <= 25
Output Format
Print exactly n-1 lines of output in which each line i contains space separated integers describing the minimum number of moves 
KnightL(i,j) must make for each respective j. If some KnightL(i,j) cannot reach position (n-1,n-1) , print -1 instead.
For example, if , we organize the answers for all the pairs in our output like this:
(1,1) (1,2)
(2,1) (2,2)
Sample Input 0
5
Sample Output 0
4 4 2 8
4 2 4 4
2 4 -1 -1
8 4 -1 1
For each KnightL(i,j) you need to run breadth-first search over the graph with nodes as places on chessboard and edges as all 
possible moves of KnightL(i,j). The desired value is the shortest path returned by BFS.
If there is no path between 0 and (n-1, -1), output -1.*/

#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int const INF = -1;

int const N = 42;

int q[N * N];
int d[N][N];

int solve(int n, int da, int db) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) d[i][j] = INF;
  int head = 0;
  int tail = 0;
  q[tail++] = 0;
  d[0][0] = 0;
  vector<pair<int, int> > moves;
  for (int i = -1; i <= 1; i += 2) {
    for (int j = -1; j <= 1; j += 2) {
      moves.push_back({da * i, db * j});
      if (da != db) {
        moves.push_back({db * i, da * j});
      }
    }
  }
  while (head < tail) {
    int v = q[head++];
    int cx = v / n;
    int cy = v % n;
    for (auto &e : moves) {
      int dx = e.first;
      int dy = e.second;
      if (abs(dx) == abs(dy) && da != db) continue;
      int nx = cx + dx;
      int ny = cy + dy;
      if (nx < 0 || ny < 0 || nx >= n || ny >= n || d[nx][ny] != INF) continue;
      d[nx][ny] = d[cx][cy] + 1;
      q[tail++] = nx * n + ny;
    }
  }
  return d[n - 1][n - 1] == INF ? -1 : d[n - 1][n - 1];
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if (j > 1) putchar(' ');
      printf("%d", solve(n, i, j));
    }
    puts("");
  }
}