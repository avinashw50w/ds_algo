/*To put the game a bit formally, we have two players Little Deepu and Kate and M items in the bag B, also we have a game set S with N elements, each element of game set is an integer. The game is played as follows, each player takes turn to pick an element from the game set S and removes that number of items from the bag, the player that is unable to remove the items from the bag looses the game. Little Deepu start the game ,If both Little Deepu and Kate play the game optimally, your task is to determine who wins the game. 

Input:
First line contains a integer T , number of test cases. Each test case contain two lines , first line contain two integer M and N and second line contain elements of S.

Output:
For each test case print name of the winner of the game .

Constraints:
1 ≤ T ≤ 1000
1 ≤ M ≤ 10000
1 ≤ N ≤ 100
1 ≤ S[i] ≤ M

SAMPLE INPUT 
2
3 2
1 2
5 3
1 2 3 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    int t; cin >> t;
    while (t--) {
        int m, n; 
        cin >> m >> n;

        int dp[m+1], a[n];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            dp[a[i]] = true;    
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i-a[j] >= 0 and !dp[i-a[j]]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        if (dp[m]) {
            cout << "Little Deepu\n";
        }
        else {
            cout << "Kate\n";
        }
    }

}