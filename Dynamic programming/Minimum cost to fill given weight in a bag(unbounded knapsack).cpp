/*Minimum cost to fill given weight in a bag
You are given a bag of size W kg and you are provided costs of packets different weights of oranges in array cost[]
 where cost[i] is basically cost of ‘i’ kg packet of oranges. Where cost[i] = -1 means that ‘i’ kg packet of orange is unavailable

Find the minimum total cost to buy exactly W kg oranges and if it is not possible to buy exactly W kg oranges then print -1. 
It may be assumed that there is infinite supply of all available packet types.

Note : array starts from index 1.
Examples:

Input  : W = 5, cost[] = {20, 10, 4, 50, 100}
Output : 14
We can choose two oranges to minimize cost. First 
orange of 2Kg and cost 10. Second orange of 3Kg
and cost 4. */

// here the ith packet has weight (i+1) because i is 0 indexed
int MinimumCost(int cost[], int n, int W) 
{ 
    int dp[W+1];
    fill(dp, dp+n, INT_MAX);
    
    dp[0] = 0; // 0 cost for weight of 0
    for (int i = 0; i < n; ++i) dp[i+1] = cost[i]; // min cost for weight i is cost[i]
    
    // pick a packet one by one
    for (int i = 0; i < n; ++i) {
    	for (int j = i+1; j <= W; ++j) // update dp[j] if the ith packet is included
    		if (cost[i] != -1 and dp[j-i-1] != INT_MAX)
    			dp[j] = min(dp[j], cost[i] + dp[j-i-1]);
    }
    
    return dp[W];
} 

// Driver program to run the test case 
int main() 
{ 
    int cost[] = {1, 2, 3, 4, 5}, W = 5; 
    int n = sizeof(cost)/sizeof(cost[0]); 
  
    cout << MinimumCost(cost, n, W); 
    return 0; 
} 