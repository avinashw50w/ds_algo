/*What is an island?
A group of connected 1s forms an island. For example, the below matrix contains 5 islands

	                    {1, 1, 0, 0, 0},
                        {0, 1, 0, 0, 1},
                        {1, 0, 0, 1, 1},
                        {0, 0, 0, 0, 0},
                        {1, 0, 1, 0, 1}*/
/*you are required to complete this method*/
int dx[] = {1,0,-1,0,1,-1,1,-1};
int dy[] = {0,1,0,-1,1,-1,-1,1};

void dfs(int A[MAX][MAX], int N, int M, bool vis[MAX][MAX],int x, int y) {
    
    vis[x][y] = true;
    
    for(int i = 0; i < 8; ++i) {

        int nx = x+dx[i], ny = y+dy[i];

        if(nx>=0 and nx<N and ny>=0 and 
            ny<M and A[nx][ny] and !vis[nx][ny])
            
            dfs(A, N, M, vis, nx, ny);      
    }
}


int findIslands(int A[MAX][MAX], int N, int M)
{
    bool vis[MAX][MAX];
    memset(vis, false, sizeof(vis));

    int cnt = 0;
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {

            if(A[i][j] and !vis[i][j]) {

                dfs(A, N, M, vis, i, j);
                
                cnt++;
            }
        }
    }
    return cnt;
}

// NOTE : we can further optimize it by taking the matrix array itself as the visited array.
// if A[i][j] == 1 then do dfs and make A[i][j] = -1 if (i,j) is visited