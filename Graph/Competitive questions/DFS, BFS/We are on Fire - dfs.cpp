/*An intergallactic war is on. Aliens are throwing fire-balls at our planet and this fire is so deadly that whichever nation it hits, it will wipe out not only that nation, but also spreads to any other nation which lies adjacent to it.

Given an NxM map which has N x M cells. Each cell may have a country or else it may be the ocean. Fire cannot penetrate the ocean or go beyond the edges of the map (a wise man managed to bound the corners preventing fire from wrapping around the corners).

You will be given a initial state of the planet represented by an N x M grid consists of 0 or 1 representing ocean and nation respectively. Also there will be Q attacks of the fire-ball. After each query, you are to tell the number of nations still left unburnt.

Input:
First line of input contains 3 space separated integers N,M,Q where N x M is the size of the planet. Q is the number of fire-ball attacks.
N lines follow each with M values of either 0 or 1, denoting whether that particular coordinate is a nation(1) or ocean(0). 
Q lines follow. Each line has a coordinate X,Y where the next fire-ball attack takes place.

Output:
For each Q, output the number of nations still existing on a single line.

Note:
Two countries are said to be adjacent if they share an edge.
Aliens can shoot the fireball at any place on the planet within its domain any number of times.
Once a nation is destroyed, it will continue to remain destroyed over all the forthcoming queries.
Large IO. Prefer scanf/printf(in C/C++).
Constraints:
1 ≤ N,M ≤ 103
1 ≤ X ≤ N
1 ≤ Y ≤ M
1 ≤ Q ≤ 106
Scoring:
1 ≤ N,M ≤ 102 , Q ≤ 103: (30 pts)
Original Constraints : (70 pts)
SAMPLE INPUT 
3 3 3
0 0 0
1 0 1
0 1 1
1 2
2 2
3 3 */

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)

const int maxn = 1000+2;
int mat[maxn][maxn];
int N, M, Q;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool safe(int x, int y) {
    return (x >= 0 and x < N and y >= 0 and y < M);
}

void dfs(int x, int y, int &cnt) {
    mat[x][y] = 0;
    cnt--;
    
    rep(i,0,4) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!safe(nx, ny)) continue;
        if(mat[nx][ny] == 1) dfs(nx, ny, cnt);
    }
}

int main() {
    scanf("%d%d%d", &N, &M, &Q);
    int cnt = 0;
    
    rep(i,0,N) rep(j,0,M) {
        scanf("%d", &mat[i][j]);
        if(mat[i][j] == 1) cnt++;
    }
    
    int X, Y;
    
    while(Q--) {
        scanf("%d%d", &X, &Y);
        X--; Y--;
        if(mat[X][Y] == 1) dfs(X, Y, cnt);
        
        printf("%d\n", cnt);
    }
    
}