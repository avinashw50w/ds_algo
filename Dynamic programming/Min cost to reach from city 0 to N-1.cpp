/*Calculate minimum cost to reach destination city from source city
given a NxN matrix where each cell (i,j) indicates the cost of the direct flight from city i to j.
Find the min cost to reach city N-1 from city 0.
*/

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// N x N matrix
#define N 5

// DP function to calculate the minimum cost to reach the destination city n
// from the source city 0
int findMinCost(int cost[][N])
{
    // dp[i] stores the minimum cost to reach city i from city 0
    int dp[N];

    // Initialize dp[] with the direct ticket price from the source city
    for (int i = 0; i < N; i++)
        dp[i] = cost[0][i];


    // repeat loop till dp[] is filled with all minimum values
    bool is_filled = false;
    while (!is_filled)
    {
        is_filled = true;

        // fill dp[] in bottom-up manner
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dp[i] > dp[j] + cost[j][i]) {
                    dp[i] = dp[j] + cost[j][i];
                    is_filled = false;  // mark dp[] as NOT filled
                }
            }
        }
    }

    // return the minimum cost to reach city N-1 from city 0
    return dp[N-1];
}

int main()
{
    int cost[N][N] =
    {
        { 0, 25, 20, 10, 105 },
        { 20, 0, 15, 80, 80 },
        { 30, 15, 0, 70, 90 },
        { 10, 10, 50, 0, 100 },
        { 40, 50, 5, 10, 0 }
    };

    cout << "The minimum cost is " << findMinCost(cost) << "$";

    return 0;
}