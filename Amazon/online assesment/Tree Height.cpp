/*
There are N trees in Jon’s backyard and height of tree i is h[i]. 
Jon doesn’t like the appearance of it and is planning to increase and decrease the height of trees such that 
the new heights are in strictly increasing order. Every day he can pick one tree and increase or decrease 
the height by 1 unit. Heights can be 0 or even negative (it’s a magical world).

A number will never be decreased to value lesser than the minimum of the initial array.
A number will never be increased to a value greater than the maximum of the initial array.
The number of operations required to change a number from X to Y is abs(X – Y).
Approach : Based on the above observation, this problem can be solved using dynamic programming. 
 

Let DP(i, j) represent the minimum operations needed to make the 1st i elements of the array sorted in non-decreasing order when the ith element is equal to j.
Now DP(N, j) needs to be calculated for all possible values of j where N is the size of the array. According to the observations, j ? smallest element of the initial array and j ? the largest element of the initial array.
The base cases in the DP(i, j) where i = 1 can be easily answered. What are the minimum operations needs to sort the 1st element in non-decreasing order such that the 1st element is equal to j?. DP(1, j) = abs( array[1] – j).
Now consider DP(i, j) for i > 1. If ith element is set to j then the 1st i – 1 elements need to be sorted and the (i – 1)th element has to be ? j i.e. DP(i, j) = (minimum of DP(i – 1, k) where k goes from 1 to j) + abs(array[i] – j) 
 
Using the above recurrence relation and the base cases, the result can be easily calculated.
*/

int getMinimumOps(vector<int> ar)
{
    // Number of elements in the array
    int n = ar.size();
 
    // Smallest element in the array
    int small = *min_element(ar.begin(), ar.end());
 
    // Largest element in the array
    int large = *max_element(ar.begin(), ar.end());
 
    /*
        dp(i, j) represents the minimum number
        of operations needed to make the 
        array[0 .. i] sorted in non-decreasing
        order given that ith element is j
    */
    int dp[n][large + 1];
 
    // Fill the dp[]][ array for base cases
    for (int j = small; j <= large; j++) {
        dp[0][j] = abs(ar[0] - j);
    }
 
    /*
        Using results for the first (i - 1) 
        elements, calculate the result 
        for the ith element
    */
    for (int i = 1; i < n; i++) {
        int minimum = INT_MAX;
        for (int j = small; j <= large; j++) {
 
            /*
            If the ith element is j then we can have
            any value from small to j for the i-1 th
            element
            We choose the one that requires the 
            minimum operations
        */
            minimum = min(minimum, dp[i - 1][j]);
            dp[i][j] = minimum + abs(ar[i] - j) + 1;
        }
    }
 
    /*
        If we made the (n - 1)th element equal to j
        we required dp(n-1, j) operations
        We choose the minimum among all possible 
        dp(n-1, j) where j goes from small to large
    */
    int ans = INT_MAX;
    for (int j = small; j <= large; j++) {
        ans = min(ans, dp[n - 1][j]);
    }
 
    return ans;
}

// optimised

int getMinimumOps(vector<int> ar)
{   
    // Number of elements in the array
    int n = ar.size();
     
    // Smallest element in the array
    int small = *min_element(ar.begin(), ar.end());
 
    // Largest element in the array
    int large = *max_element(ar.begin(), ar.end());
     
    // create vector to store value of subproblems
    vector<int> dp(large + 1);
     
     
    // initialize base case
    for (int j = small; j <= large; j++) {
        dp[j] = abs(ar[0] - j);
    }
     
    // iterate iver subproblems to get the current
    // value from previous computations
    for (int i = 1; i < n; i++) {
        int minimum = INT_MAX;  
         
        // create vector to store current row values
        vector<int> curr(large + 1);
        for (int j = small; j <= large; j++) {
            minimum = min(minimum, dp[j]);
            curr[j] = minimum + abs(ar[i] - j) + 1;
        }
         
        // assigning values for further iterations
        dp = curr;
    }   
     
    // to store answer
    int ans = INT_MAX;
    for (int j = small; j <= large; j++) {
         
        // update answer
        ans = min(ans, dp[j]);
    }
     
    // return final answer
    return ans;
}