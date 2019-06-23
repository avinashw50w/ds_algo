/* When you’re given a set of cities and the distances between the cities, you wish to travel all of the cities exactly once and cover the 
least distance, then this is the Travelling Salesman Problem. It is an NP-Hard problem that is important in the in combinatorial optimizations,
operations research and theoretical computer science. Also, ever so often, we end up seeing variations of this problem, or problems that use 
the techniques used in this problem. The most important of these techniques is DP with Bitmasking.

Let’s formalize this problem. There’s a list of 20 cities and the distances between the ith and jth city is given in an adjacency matrix dist. 
You start at the 0th city and want to finish visiting all of the cities by covering the least possible distance.

Given that you have not more than 20 cities, try and formalize a DP by incorporating bitmasking.

Please don’t scroll down without thinking about it for a few minutes.

Let’s consider some subset of cities, S. Say you have visited all of the cities in S. Now you want to visit some city C that’s not in S. 
What do you want to minimize now? The sum of the distance already covered by visiting all the cities in S and the distance between the 
last city visited in S (let’s call it P) and C.

From this we can see that a state in our DP is characterized by two variables.
The set of cities we have visited, S The last city visited in the set of cities, L
The base cases would be visiting just 1 city and that distance would be 0.
Now, we can represent the set of visited cities by using bitmasking. Each integer has 32 bits, and we have at most 20 cities. 
So, if the i-th bit is 1, then it has been visited, else it’s unvisited.

for more details : http://codeforces.com/blog/entry/337   */

const int INF = 1e9;  
int shortestTSPdistance(vector<vector<int> > dist) {  
    int n = dist.size();  // total nodes to travel
    int lim = 1 << n;  
    int dp[lim][n];  
    memset(dp, INF, sizeof(dp));   // set distance of each node to every other node to inf
    for (int i = 0; i < n; i++) {  
        dp[1 << i][i] = 0;    // distance from a node to itself will be ofcourse 0  
    }  
    // for each subset of nodes
    for (int mask = 0; mask < lim; mask++) { 
    // pick a node which will be considered the last node visited 
        for (int last = 0; last < n; last++) {  
            if (mask && (1 << last) == 0) {      
                continue;  
            }  
            // pick a node which is to be visited next
            for (int curr = 0; curr < n; curr++) {  
                if (mask && (1 << curr) == 0) {  
                    continue;  
                } 
                // take a subset of nodes in which the next visiting node is not there 
                int otherMask = mask ^ (1 << curr);  
                // the min dist to curr in the subset-mask is min of either the current dist or
                // the dist to the last node in the subset-otherMask + dist from last node to the curr node
                dp[mask][curr] = min(dp[mask][curr], dp[otherMask][last] + dist[last][curr]);  
            }  
        }  
    }  
    int ans = INF;  
    for (int i = 0; i < n; i++) {  
        ans = min(ans, dp[lim - 1][i]);  
    }  
    return ans;  
}
/*
Note that in most DP with bitmasking problems, there will be a variable constrained to a value of almost ~20.

Space Complexity: O(n * 2n)
Time Complexity: O(n2 * 2n)
*/