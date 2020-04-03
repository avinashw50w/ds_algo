/*You are given a matrix of size N×M that contains the digits 0, 1, or 2 only. All the cells that contain 
1 and are adjacent to any cell that contains 2 will be converted from 1 to 2, simultaneously in 1 second. 
Write a program to find the minimum time to convert all the cells having value 1 to 2.

Input format

First line: Two space-separated integers 
N and M
Next N lines: M space-separated integers (denoting the matrix)
Output format

Print the minimum time to convert all the cells having value 1 to 2.

Constraints

1≤N,M≤103
SAMPLE INPUT 
3 5
2 1 0 2 1
1 0 1 2 1
1 0 0 2 1
SAMPLE OUTPUT 
2 */

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)

const int maxn = 1e3+2;
int N, M;
int mat[maxn][maxn];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

queue<pair<int,int>> Q;

bool safe(int x, int y) {
    return (x >= 0 and x < N and y >= 0 and y < M);
}

int main() {
    cin >> N >> M;
    
    int ones = 0;
    
    rep(i,0,N) rep(j,0,M) {
        scanf("%d", &mat[i][j]);
        
        if(mat[i][j] == 2) Q.push({i, j});
        if(mat[i][j] == 1) ones++;
    }
    
    if(ones == 0) {
        printf("0\n");
        return 0;
    }
    
    Q.push({-1, -1});
    int ans = -1;
    
    while(!Q.empty()) {
        int flag = false;

        while(! (Q.front().first == -1 && Q.front().second == -1)) {
            auto top = Q.front();
            Q.pop();
            int x = top.first;
            int y = top.second;
            
            if (!flag) ans++, flag = true;
            
            rep(i,0,4) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(!safe(nx, ny)) continue;
                
                if(mat[nx][ny] == 1) {
                    mat[nx][ny] = 2;
                    ones--;
                    Q.push({nx, ny});
                }
            }
        }
  
        Q.pop();

        if (!Q.empty()) 
            Q.push({-1,-1});
        
    }

    int f = 0;
    rep(i, 0, N)
        rep(j, 0, M)
            if (mat[i][j] == 1) {
                f = 1; break;
            }
    
    if (f == 1) printf("-1\n");
    else printf("%d\n", ans);
}

///////////////////////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;
 
// function to check whether a cell is valid / invalid
bool isvalid(int i, int j,int n,int m)
{
    return (i >= 0 && j >= 0 && i < n && j < m);
}
 
// structure for storing coordinates of the cell
struct ele {
    int x, y;
};
 
// Drive program
int main()
{
 	int n,m,i,j;
 	cin>>n>>m;
 	
 	short int arr[1001][1001];
 	
 	for(i=0;i<n;i++){
 		for(j=0;j<m;j++)cin>>arr[i][j];
	 }
	 
    // Create a queue of cells
    queue<ele> Q;
    ele temp;
    int ans = 0;
 
    // Store all the cells having Bad People in first time frame
    for (int i=0; i<n; i++)
    {
       for (int j=0; j<m; j++)
       {
            if (arr[i][j] == 2)
            {
                temp.x = i;
                temp.y = j;
                Q.push(temp);
            }
        }
    }
 
    // Separate these Bad People from the Good People which will became bad
    // due the Bad People in first time frame using delimiter which is (-1, -1)
    temp.x = -1;
    temp.y = -1;
    Q.push(temp);
 
    // Process the grid while there are Bad People in the Queue
    while (!Q.empty())
    {
        // This flag is used to determine whether even a single Good
        // Person gets Bad due to Bad Person in current time
        // frame so we can increase the count of the required time.
        bool flag = false;
 
        // Process all the Bad People in current time frame until 
		//it is not a delimiter.
        while (!(Q.front().x ==-1 && Q.front().y == -1))
        {
            temp = Q.front();
 
            // Check right adjacent cell that if it has Good Person
            if (isvalid(temp.x+1, temp.y,n,m) && arr[temp.x+1][temp.y] == 1)
            {
                // if this is the first Person to become Bad, increase
                // count and set the flag.
                if (!flag) ans++, flag = true;
 
                // Make the Good People Bad
                arr[temp.x+1][temp.y] = 2;
 
                // push the adjacent Person to Queue
                temp.x++;
                Q.push(temp);
 
                temp.x--; // Move back to current cell
            }
 
            // Check left adjacent cell that if it has Good Person
            if (isvalid(temp.x-1, temp.y,n,m) && arr[temp.x-1][temp.y] == 1) {
                if (!flag) ans++, flag = true;
                arr[temp.x-1][temp.y] = 2;
                temp.x--;
                Q.push(temp); // push this cell to Queue
                temp.x++;
            }
 
            // Check top adjacent cell that if it has Good Person
            if (isvalid(temp.x, temp.y+1,n,m) && arr[temp.x][temp.y+1] == 1) {
                if (!flag) ans++, flag = true;
                arr[temp.x][temp.y+1] = 2;
                temp.y++;
                Q.push(temp); // Push this cell to Queue
                temp.y--;
            }
 
            // Check bottom adjacent cell if it has Good Person
            if (isvalid(temp.x, temp.y-1,n,m) && arr[temp.x][temp.y-1] == 1) {
                if (!flag) ans++, flag = true;
                arr[temp.x][temp.y-1] = 2;
                temp.y--;
                Q.push(temp); // push this cell to Queue
            }
 
            Q.pop();
        }
 
        // Pop the delimiter
        Q.pop();
 
        // If Person is Bad in current frame than separate the
        // Bad People using delimiter for the next frame for processing.
        if (!Q.empty()) {
            temp.x = -1;
            temp.y = -1;
            Q.push(temp);
        }
 
        // If Queue was empty than no Bad People left to process so exit
    }
 
 	int f=0;
	for (int i=0; i<n; i++)
    	for (int j=0; j<m; j++)
     		if(arr[i][j]==1){
       			f=1;
       			break;
			}
 
 	//f=1 if some Good People Left
    if (f == 1)
        cout << -1<<endl;
    else
         cout << ans << endl;
    return 0;
}