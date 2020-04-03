/*HackerMan loves playing Age of Empire. A few days ago, he discovered a variant of that game which is equally adventurous. 
Here, he has to capture a castle before his enemy.

The map consists of several interconnected paths in a grid pattern. He starts at top left intersection (1,1), and then proceeds 
towards the castle. But every intersection has some dark magical power which stops him from escaping that intersection for some 
time. Also, the enemy is moving towards the castle. So he has to reach the castle before his enemy. Given the time t at which 
the enemy captures the castle, you have to determine if it is possible for HackerMan to capture the castle himself.

The first line contains the number of test cases T (1 <= T <= 100). In each test case, the first line contains two integers 
M and N indicating the number of rows and columns in the grid of paths. Then follows M lines, each line contains N positive 
integers. The integer at (i,j) in the grid denotes the time taken to escape that intersection. Then follows another line which 
contains 3 positive integers - x, y, and t, where (x,y) is the position of castle and t is time at which enemy captures the castle.

You have to print NO if it is not possible to capture the castle before time t. If it is possible, print YES followed by a 
newline and then print the time left before which the enemy reaches the castle. You need to prepare for the war then :)

Input constraints

1 <= T <= 100

1 <= M <= 1000

1 <= N <= 1000

Notes

Diagonal moves are not allowed.
The time left before which the enemy reaches the castle can be zero.
The time corresponding to the intersection at which castle is present 
is also added in the total time required to reach the castle.
UPDATE A strong input in test case 4 is removed and all submissions have been rejudged.

SAMPLE INPUT 
2
2 6
5 6 1 3 10 2
2 2 8 7 2 3
1 3 76
5 3
5 4 10
2 3 6
5 5 8
3 9 1
5 8 3
5 2 25
SAMPLE OUTPUT 
YES
64
NO*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)

typedef long long ll;

const int oo = 1e7;
const int maxn = 1000+2;

int N, M;
int mat[maxn][maxn];
ll dist[maxn][maxn];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

struct Node {
	int x, y;
	ll dist;	
};

bool safe(int x, int y) {
	return (x >= 0 and x < N and y >= 0 and y < M);
}

class Comp {
	public: bool operator()(const Node& a, const Node& b) {return a.dist > b.dist;}
};

int solve(int x, int y) {
	priority_queue<Node, vector<Node>, Comp> pq;

	dist[0][0] = mat[0][0];
	pq.push({0, 0, dist[0][0]});

	while(!pq.empty()) {
		Node top = pq.top(); 
		pq.pop();
		int cx = top.x;
		int cy = top.y;

		rep(i, 0, 4) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if(!safe(nx, ny)) continue;
			
			if(dist[nx][ny] > dist[cx][cy] + mat[nx][ny]) {
				dist[nx][ny] = dist[cx][cy] + mat[nx][ny];
				pq.push({nx, ny, dist[nx][ny]});
			}
		}
	}
	
	return dist[x][y];
}

int main() {
	int t; cin >> t;

	while(t--) {
		cin >> N >> M;

		rep(i, 0, N) 
		rep(j, 0, M) {
			cin >> mat[i][j];
			dist[i][j] = oo;
		}

		int x, y, t;

		cin >> x >> y >> t;
		--x; --y;

		int time_taken = solve(x, y);

		if(t- time_taken >= 0) {
			cout << "YES" << endl << t - time_taken << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}