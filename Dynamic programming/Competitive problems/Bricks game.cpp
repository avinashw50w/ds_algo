/*You and your friend decide to play a game using a stack consisting of N bricks. In this game, you can alternatively remove 1, 2 or 3 
bricks from the top, and the numbers etched on the removed bricks are added to your score. You have to play so that you obtain the maximum 
possible score. It is given that your friend will also play optimally and you make the first move.

Input Format 
First line will contain an integer T i.e. number of test cases. There will be two lines corresponding to each test case: first line will 
contain a number N i.e. number of elements in the stack and next line will contain N numbers i.e. numbers etched on bricks from top to bottom.

Output Format 
For each test case, print a single line containing your maximum score.

Constraints 
1 ≤ T ≤ 5 
1 ≤ N ≤ 105 
0 ≤ each number on brick ≤ 109

Sample Input

2
5
999 1 1 1 0
5
0 1 1 1 999
Sample Output

1001
999

Solution : 
Given a stack of bricks, You have to remove the bricks in such a way that you get the maximum possible socore while It is given that 
other player will also play optimally. 
So,
Suppose numbers written on bricks are a[0], a[1]....., a[n-1] where a[0] is the bottom-most brick. 
Consider another array of prefix sum i.e. sum[n]
where sum[i] = a[0] + a[1] + ....+ a[i]
Consider another array dp[n]
where dp[i] = maximum score of first player for stack a[0],a[1]...,a[i] when he is playing optimally. 
It is obvious that,
dp[0] = a[0]
dp[1] = a[0] + a[1]
dp[2] = a[0] + a[1] + a[2]

Now suppose that dp[0], dp[1],....., dp[k-1] has been calculated and we want to calcualte dp[k].

For kth brick, first player will have 3 options.
Pick one 
Then first player will get a[k] and his opponenet will get dp[k-1] so first will get { (sum[k-1] - dp[k-1]) + a[k] } in total.
Pick two 
Then first player will get a[k]+a[k-1] and his opponenet will get dp[k-2] so first will get { (sum[k-2] - dp[k-2]) + a[k]+ a[k-1] } in total.
Pick three 
Then first player will get a[k]+a[k-1]+a[k-2] and his opponenet will get dp[k-3] so first will get { (sum[k-3] - dp[k-3]) + a[k]+ a[k-1] +a[k-2] } in total.
so dp[k] = max {(sum[k-1] - dp[k-1]) + a[k] ,(sum[k-2] - dp[k-2]) + a[k]+ a[k-1], (sum[k-3] - dp[k-3]) + a[k]+ a[k-1] +a[k-2] }
This can be calculated in O(1) time, so total time needed will be O(n).*/

#include <bits/stdc++.h>
#define assn(n,a,b) assert(n>=a && n<=b)
using namespace std;
typedef long long LL; 
LL dp[100009]={},val[100009],pre[100009];

int main() 
{ 
    int t; 
    cin >> t;
    while(t--) 
    {
        pre[0]=0;
        LL n,i,j; 
        cin >> n; 
        assn(n,1,100000);
        for(i=n; i>0; i--)
        {
            cin >> val[i];
            assn(val[i],0ll,1000000000ll);
        } 
        for(i=1; i<=n; i++) 
            pre[i]=pre[i-1]+val[i];
        dp[0]=0;
        dp[1]=val[1];
        dp[2]=dp[1]+val[2];
        dp[3]=dp[2]+val[3]; 
        for(i=4; i<=n; i++)
        {
            dp[i]=max(-1ll,pre[i-1]-dp[i-1]+val[i]);
            dp[i]=max(dp[i],pre[i-2]-dp[i-2]+val[i]+val[i-1]); 
            dp[i]=max(dp[i],pre[i-3]-dp[i-3]+val[i]+val[i-1]+val[i-2]); 
        }
        cout << dp[n] << endl; 
    }
    return 0; 
}

/*======================================================================================*/
#include <cmath> 
#include <cstdio>
#include <vector>
#include <iostream> 
#include <algorithm> 

using namespace std;

int a[100010]; 
long long dp[100010]; 

int main()
{ 

    int z;
    for (scanf("%d",&z);z;--z) 
    {
        int n;
        scanf("%d",&n); 
        for (int i = 0; i < n; ++i) 
        { 
            scanf("%d",a + i);
        }
        long long sum = 0; 
        dp[n] = dp[n + 1] = dp[n + 2] = 0; 
        for (int i = n - 1; i >= 0; --i)
        { 
              sum += a[i]; 
              dp[i] = sum - min(min(dp[i + 1], dp[i + 2]), dp[i + 3]); 
         }
        printf("%lld\n",dp[0]); 
    }
    return 0; 
}