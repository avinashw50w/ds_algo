/*/*Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.

Example:

Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Return 4.

Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the total increased height.

Limits

1 ≤ T ≤ 100.
1 ≤ H[i][j] ≤ 1000.
Small dataset

1 ≤ R ≤ 10.
1 ≤ C ≤ 10.
Large dataset

1 ≤ R ≤ 50.
1 ≤ C ≤ 50.
Sample


Input 
    
Output 
 
3
3 3
3 5 5
5 4 5
5 5 5
4 4
5 5 5 1
5 1 1 5
5 1 5 5
5 2 5 8
4 3
2 2 2
2 1 2
2 1 2
2 1 2

Case #1: 1
Case #2: 3
Case #3: 0

Case 1 is explained in the statement.

In case 2, the island looks like this after the rain:

5 5 5 1
5 2 2 5
5 2 5 5
5 2 5 8


IDEA: push all the islands at the edges into a min heap, then do bfs on each of them*/

struct Point{
    int x,y, val;

    int operator < (const Point& a) const { return val > a.val; }
};

int g[55][55];
int corner[55][55];
int cnt;
int r, c;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};


void solve(){
    priority_queue<Point> Q;
    mset(corner,0);
    int sum0 = 0, sum1 = 0;
    cin >> r >> c;
    

    rep(i,0,r){ 
        rep(j,0,c){
            cin>> g[i][j];
            if(i==0 || i==r-1 || j==0 || j==c-1){
                Q.push((Point){i,j, g[i][j]});
                corner[i][j] = 1;
            }
            sum0 += g[i][j];
        }
    }

    while(!Q.empty()) {
        int x = Q.top().x;
        int y = Q.top().y;
        Q.pop();
        rep(i,0,4){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 and nx<r and ny>=0 and ny<c and !corner[nx][ny]){
                g[nx][ny] = max(g[nx][ny], g[x][y]);
                corner[nx][ny] = 1;
                Q.push( (Point){nx,ny, g[nx][ny]} );
            }
        }
    }

    rep(i,0,r){
        rep(j,0,c)
            sum1 += g[i][j];
    }
    
    cout << sum1 - sum0 << endl;
}

int main() {
    #if 1
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    caset{
        printf("Case #%d: ", case_n++ );
        solve();
    }
    return 0;
}
