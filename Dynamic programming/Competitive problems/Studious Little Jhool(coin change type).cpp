/*He had two types of notebooks, when he was a kid.

 problems could be solved in one page, in the first notebook.
 problems could be solved in one page, in the second notebook.
Little Jhool remembered how in order to maintain symmetry, if he was given with n problems in total to solve, he tore out pages from both notebooks, so no space was wasted. EVER!

But, now he's unable to solve his own problem because of his depression, and for the exercise of the week, he has to answer the queries asked by his psychologist.

Given n number of questions, print the minimum number of pages he needs to tear out from the combination of both the notebooks, so that no space is wasted.

Input Format:
The first line will contain t - number of test cases.

The second will contain an integer n - number of questions.

Output Format:
Corresponding to the input, print the minimum number of pages Little Jhool needs to tear out from the combination of both the notebooks. If it is NOT possible, print "1".

Constraints: 
 

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    
    int dp[115];
    
    cin >> t;
    
    while (t--) {
        cin >> n;
        fill(dp, dp+n+1, INT_MAX);
        
        dp[0] = 0; dp[10] = dp[12] = 1;
        
        for (int i = 10; i <= n; ++i) if (dp[i-10] != INT_MAX) dp[i] = min(dp[i], 1+dp[i-10]);
        for (int i = 12; i <= n; ++i) if (dp[i-12] != INT_MAX) dp[i] = min(dp[i], 1+dp[i-12]);
        
        cout << (dp[n] == INT_MAX ? -1 : dp[n]) << endl;
    }
}