/*Costs required to move all 1s to each index of a given Binary Array
Difficulty Level : Medium
Last Updated : 26 Oct, 2020
Given a binary array, in which, moving an element from index i to index j requires abs(i – j) cost. The task is to find the cost to move all 1s to each index of the given array.

Examples:

Input: arr[] = {0, 1, 0, 1}
Output: 4 2 2 2
Explanation: 
Moving elements from index 1, index 3 to index 0 requires abs(0 – 1) + abs(0 – 3) = 4.
Moving elements from index 1, index 3 to index 1 requires abs(1 – 1) + abs(1 – 3) = 2.
Moving elements from index 1, index 2 to index 2 requires abs(2 – 1) + abs(2 – 3) = 2.
Moving elements from index 1, index 2 to index 3 requires abs(3 – 1) + abs(3 – 3) = 2.
Therefore, the required output is 4 2 2 2.*/

vector<int> solve(vector<int> a) {
    int n = a.size();
    vector<int> cost(n);

    int ones = 0;
    for (int i = 1; i < n; ++i) {
        cost[i] = cost[i-1] + ones;
        ones += a[i] == 1;
    }

    ones = 0;
    for (int i = n-2; i >= 0; --i) {
        cost[i] = cost[i+1] + ones;
        ones += a[i] == 1;
    }

    return cost;
}