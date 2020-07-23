/*The G tech company has deployed many balloons. Sometimes, they need to be collected
for maintenance at the company's tower, which is located at horizontal position 0.
Each balloon is currently at horizontal position Pi and height Hi.

G engineers can move a balloon up and down by sending radio signals to tell it to
drop ballast or let out air. But they can't move the balloon horizontally;
they have to rely on existing winds to do that.

There are M different heights where the balloons could be. The winds at different heights
may blow in different directions and at different velocities.
Specifically, at height j, the wind has velocity Vj, with positive velocities meaning
that the wind blows left to right, and negative velocities meaning that the
wind blows right to left. A balloon at position P at a height with wind velocity V will
be at position P+V after one time unit, P+2V after two time units, etc.
If a balloon touches the tower, it is immediately collected.

It costs | Horiginal - Hnew | points of energy to move one balloon between two different heights.
(This transfer takes no time.) You have Q points of energy to spend,
although you do not need to spend all of it. What is the least amount of time it will take to
collect all the balloons, if you spend energy optimally?

Input

The first line of the input gives the number of test cases, T. T test cases follows.
The first line of each case has three integers N, M, and Q, representing the number
of balloons, the number of height levels, and the amount of energy available.
The second line has M integers; the jth value on this line (counting starting from 0)
is the wind velocity at height j.
Then, N more lines follow. The ith of these lines consists of two integers, Pi and Hi,
representing the position and height of the ith balloon.

Output

For each test case, output one line containing "Case #x: y", where x is the test case number
(starting from 1) and y is the minimum number of time units needed to
collect all of the balloons, returns IMPOSSIBLE if it's impossible to collect all the balloons using the energy given.

Limits

Small dataset

1 = T = 100.
1 = N = 10.
1 = M = 10.
-10 = Vj = 10.
1 = Q = 10.
0 = Hi <M.
-10 = Pi = 10.
Large dataset

1 = T = 25.
1 = N = 100.
1 = M = 1000.
-100 = Vj = 100.
1 = Q = 10000
0 = Hi <M.
-10000 = Pi = 10000.
Sample


Input

Output

2
2 4 1
2 1 -2 -1
3 3
-2 1
1 3 1
1 -1 -2
-2 2*/

ll MOD = int(1e9) + 7;

int debug = 1;
const int N = int(1e6) + 5;
using namespace std;
int speed[1005], p[105], h[105];
int n, m, q;

int check(int tim)
{
        int i, j;
        int req = 0;
        rep(i, n)       // for each ballon
        {
                if (p[i] == 0)
                        continue;
                int tempcost = q + 1;
                rep(j, m)       // for each height level
                {
                        if (speed[j] == 0)      // if speed is 0 at this height then continue to another height
                                continue;
                        if (p[i]*speed[j] > 0)  // if speed is away from the tower, continue to another height
                                continue;
                        int pos = abs(p[i]), spe = abs(speed[j]);
                        int timreq = ((pos + spe - 1) / spe);
                        if (timreq <= tim)
                                tempcost = min(tempcost, abs(h[i] - j));
                }
                req += tempcost;
        }
        return req <= q;
}

int main()
{
        int i, j, t;
        ios::sync_with_stdio(false);
        cin >> t;
        int t1 = t;
        while (t--)
        {

                cin >> n >> m >> q;
                rep(i, m)cin >> speed[i];
                rep(i, n)cin >> p[i] >> h[i];
                int ans = -1 , lo = 0 , hi =  int(1e7);
                int mid;
                while (lo <= hi)
                {
                        mid = (lo + hi) / 2;
                        if (check(mid))
                        {
                                hi = mid - 1;
                                ans = mid;
                        }
                        else
                                lo = mid + 1;
                }
                if (ans == -1)
                        cout << "Case #" << t1 - t << ": " << "IMPOSSIBLE" << endl;

                else
                        cout << "Case #" << t1 - t << ": " << ans << endl;
        }
}
