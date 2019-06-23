 
int knapSack(int W, int wt[], int val[], int n)
{
   if (n == 0 || W == 0) return 0;

   if (wt[n-1] > W)
       return knapSack(W, wt, val, n-1);
 
   // Return the maximum of two cases: 
   // (1) nth item included 
   // (2) not included
   else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
                    knapSack(W, wt, val, n-1)
                  );
}
/* In the following recursion tree, K() refers to knapSack().  The two 
parameters indicated in the following recursion tree are n and W.  
The recursion tree is for following sample inputs.
wt[] = {1, 1, 1}, W = 2, val[] = {10, 20, 30}

                       K(3, 2)         ---------> K(n, W)
                   /            \ 
                 /                \               
            K(2,2)                  K(2,1)
          /       \                  /    \ 
        /           \              /        \
       K(1,2)      K(1,1)        K(1,1)     K(1,0)
       /  \         /   \          /   \
     /      \     /       \      /       \
K(0,2)  K(0,1)  K(0,1)  K(0,0)  K(0,1)   K(0,0)
  */

// A Dynamic Programming based solution for 0-1 Knapsack problem
// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int dp[n+1][W+1];

   memset(dp, 0, sizeof(dp));
 
   for (i = 1; i <= n; i++)
   {
       for (w = 1; w <= W; w++)
       {
           if (wt[i-1] <= w)
                 dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]],  dp[i-1][w]);
           else
                 dp[i][w] = dp[i-1][w];
       }
   }
 
   return dp[n][W];
}
 
int main()
{
    int val[] = {25, 24, 15};
    int wt[] = {18, 15, 10};
    int  W = 20;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}
/////////////////////////////////////////////////////////////////////////
// space opitmized //
int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int dp[2][W+1];
   memset(dp, 0, sizeof(dp));
 
   for (i = 1; i < n; i++)
   {
   		int ii = i&1;
       for (w = 1; w <= W; w++)
       {
           if (wt[i-1] <= w)
                 dp[ii][w] = max(val[i-1] + dp[1-ii][w-wt[i]],  dp[1-ii][w]);
           else
                 dp[ii][w] = dp[1-ii][w];
       }
   }
 
   return dp[n&1][W];
}

// more space optimized
int knapsack(int wt[], int val[], int N, int W) {

    int dp[W+1];

    memset(dp, 0, sizeof(dp));

    // iterate through all the items
    for (int i = 0; i < N; ++i) {
        for (int j = W; j >= wt[i]; --j) 
            dp[j] = max(dp[j], val[i] + dp[j-wt[i]]);
    }

    return dp[W];
}

// unbounded knapsack (if each item is available in infinite quantities)

int Knapsack(int wt[], int val[], int N, int W) {

    int dp[W+1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < N; ++i)
        for (int j = wt[i]; j <= W; ++j)
            dp[j] = max(dp[j], val[i] + dp[j-wt[i]]);
}