/*Two friends Kunal and Satyam are playing an interesting game. They take turns drawing a ball from a bag which initially contains R red balls and G green balls. Each player draws a ball alternatively and never put it back. The person who is the first to draw a red balls wins. Satyam always draws first. If there are no more balls in the bag and nobody has drawn a red ball, the satyam wins.

What is the probability of the Satyam winning?
Input:
The first line will contain the number of test cases T.
The first line of each test case will contain a number R (number of red balls) and G(number of green balls )

Output 
For each testcase, print the desired probability.
Constraints:
1<=T<=10
0<=R,G<=10^3 */

/*Prob that satyam wins - 
1. he picks a red ball : r/(r+g)
2. he picks a green ball g/(r+g), then kunal must select a green ball(otherwise kunal would win) (g-1/(r+g-1), 
then finaly Satyam select a red ball dp[r][g-2]

Now, prob that Satyam wins  = P(case1) + P(case2)
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int t; cin >> t;
    double dp[1003][1003];
    
    while(t--) {
        int r, g;
        scanf("%d%d", &r, &g);
            
        memset(dp, 0, sizeof(dp));
        
        for (int i = 0; i <= r; ++i) {
            for (int j = 0; j <= g; ++j) {
                if (i == 0 or j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = i*1.0/(i+j) + (j*1.0/(i+j))*((j-1)*1.0/(i+j-1))*dp[i][j-2];
            }
        }
        
        printf("%.6lf\n", dp[r][g]);
    }
}