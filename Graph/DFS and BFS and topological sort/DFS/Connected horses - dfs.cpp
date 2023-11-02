/*You all must be familiar with the chess-board having 8x8 squares of alternate black and white cells. 
Well, here we have for you a similar NxM size board with similar arrangement of black and white cells.

A few of these cells have Horses placed over them. Each horse is unique. Now these horses are not the usual horses which could 
jump to any of the 8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions 
that it can go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.

A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state 
of the board, calculate answer. Since this answer may be quite large, calculate in modulo 10^9+7

Input:
First line contains T which is the number of test cases.T test cases follow first line of each containing three integers N, M and 
Q where N,M is the size of the board and Q is the number of horses on it. Q lines follow each containing the 2 integers 
X and Y which are the coordinates of the Horses.

Output:
For each test case, output the number of photographs taken by photographer.

Constraints:
1
1 ≤ T ≤ 10
1 ≤ N,M ≤ 10^3
1 ≤ Q ≤ NxM
SAMPLE INPUT 
2
4 4 4
1 1
1 2
3 1
3 2
4 4 4
1 1
1 2
3 1
4 4

SAMPLE OUTPUT 
4
2*/

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)

const int mod = 1e9+7;
const int maxn = 1000+2;
typedef long long ll;

int dx[] = {1, -1, 1, -1, 2, -2, 2, -2};
int dy[] = {2, 2, -2, -2, 1, 1, -1, -1};
int mat[maxn][maxn];
ll fact[maxn*maxn], ans, horseCnt;
int N, M, Q;

void init() {
    fact[0] = fact[1] = 1;
    
    rep(i,2,maxn*maxn) fact[i] = (i * fact[i-1]) % mod;
}

inline bool safe(int x, int y) {
    return (x >= 0 and x < N and y >= 0 and y < M);
}

void dfs(int x, int y) {
    mat[x][y] = 0;
    horseCnt++;
    
    rep(i,0,8) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(!safe(nx, ny)) continue;
        if(mat[nx][ny] == 1) dfs(nx, ny);
    }
}

int main() {
    init();
    int T; cin >> T;
    int X, Y;
    
    while(T--) {
        memset(mat, 0, sizeof(mat));
        cin >> N >> M >> Q;
        
        while(Q--) {
            cin >> X >> Y;
            X--; Y--;
            mat[X][Y] = 1;
        }
        
        ans = 1;
        
        rep(i,0,N)
            rep(j,0,M)
                if(mat[i][j] == 1) {
                    horseCnt = 0;
                    dfs(i, j);
                    
                    horseCnt = fact[horseCnt];
                    ans = (ans * horseCnt) % mod;
                }
                
        cout << ans << endl;
    }
}