/*Two friends Kunal and Satyam are playing an interesting game. They take turns drawing a ball from a bag which initially contains R red balls and G green balls. Each player draws a ball alternatively and never put it back. The person who is the first to draw a red balls wins. Satyam always draws first. If there are no more balls in the bag and nobody has drawn a red ball, the satyam wins.

What is the probability of the Satyam winning?
Input:
The first line will contain the number of test cases T.
The first line of each test case will contain a number R (number of red balls) and G(number of green balls )

Output 
For each testcase, print the desired probability.
Constraints:
1<=T<=10
0<=R,G<=10^3

Problem Setter : Surya Pratap Singh

SAMPLE INPUT 
3
2 1
1 1
10 0
SAMPLE OUTPUT 
0.666667
0.500000
1.000000*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;
// dp[r][g] - the prob that satyam wins when the no of red and green balls are r and g respectively
double dp[maxn][maxn];

int main() {
    int t, r, g;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &r, &g);
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i <= r; ++i) {
            for (int j = 0; j <= g; ++j) {
                if (i == 0) { dp[i][j] = 1; continue; }
                if (j == 0) { dp[i][j] = 1; continue; }

                dp[i][j] = i * 1.0 / (i + j);
                if (j - 2 >= 0) 
                    dp[i][j] += (j * 1.0 / (i + j)) * ((j-1) * 1.0 / (i + j - 1)) * dp[i][j-2];
            }
        }

        printf("%0.6lf\n", dp[r][g]);
    }
}