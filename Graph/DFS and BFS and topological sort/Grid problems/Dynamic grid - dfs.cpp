/*We have a grid with R rows and C columns in which every entry is either 0 or 1. 
We are going to perform N operations on the grid, each of which is one of the following:

Operation M: Change a number in one cell of the grid to 0 or 1
Operation Q: Determine the number of different connected regions of 1s. 
A connected region of 1s is a subset of cells that are all 1, in which any cell in the region can be 
reached from any other cell in the region by traveling between cells along edges (not corners).
Input

The first line of the input gives the number of test cases, T. T test cases follow. 
Each test case starts with one line with two integers, R and C, which represent the 
number of rows and columns in the grid. Then, there are R lines of C characters each, 
in which every character is either 0 or 1. These lines represent the initial state 
of the grid.

The next line has one integer, N, the number of operations to perform on the grid. 
N more lines follow; each has one operation. All operation Ms will be of the form M x y z, 
meaning that the cell at row x and column y should be changed to the value z. All operation Qs will be of the form Q.
Output

For each test case, output one line containing "Case #x:", where x is the test case number (starting from 1). 
Then, for every operation Q in the test case, in order, 
output one line containing the number of connected regions of 1s.

Limits

1 = T = 10.
1 = R, C = 100.
0 = x < R.
0 = y < C.
0 = z = 1.
Small dataset

1 = N = 10.
Large dataset

1 = N = 1000.
Sample


Input 
 	
Output 
 
1
4 4
0101
0010
0100
1111
7
Q
M 0 2 1
Q
M 2 2 0
Q
M 2 1 0
Q

Case #1:
4
2
2
2

*/
ll MOD = int(1e9) + 7;

int debug = 0;
const int N = int(1e6) + 5;
using namespace std;
string a[105];
int r,c,vis[105][105];
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};

void dfs(int x,int y)
{
        if(a[x][y] == ' ' || a[x][y] == '0' || vis[x][y])
                return;
        int i;
        vis[x][y] = 1;
        rep(i,4)
        {
                dfs(x+dx[i],y+dy[i]);
        }
}

int query()
{
        int i,j,ret = 0;
        memset(vis,0,sizeof(vis));
        f(i,1,r+1)
        {
                f(j,1,c+1)
                {
                        if(vis[i][j] || a[i][j] == '0')
                                continue;
                        ret++;
                        dfs(i,j);
                }
        }
        return ret;
}

int main()
{
        int i,j,n,t;
        ios::sync_with_stdio(false);
        cin>>t;
        int t1 = t;
        while(t--)
        {
                cin>>r>>c;
                a[0] = a[r+1] = string(c+2,'0');
                rep(i,r)
                {
                        cin>>a[i+1];
                        a[i+1] = "0" + a[i+1] + "0";
                }
               
                int q;
                cin>>q;
                cout<<"Case #"<<t1-t<<": "<<endl;

                while(q--)
                {
                        char type;
                        cin>>type;
                        if(type == 'Q')
                        {
                                cout<<query()<<endl;
                        }
                        else
                        {
                                int l,r,val;
                                cin>>l>>r>>val;
                                a[l+1][r+1] = '0' + val;
                        }
                }
        }
}
