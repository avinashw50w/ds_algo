/*In a country popular for train travel, you have planned some train travelling one year in
advance.  The days of the year that you will travel is given as an array days.  Each day is an
integer from 1 to 365.

Train tickets are sold in 3 different ways:

a 1-day pass is sold for costs[0] dollars;
a 7-day pass is sold for costs[1] dollars;
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on
day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.

Return the minimum number of dollars you need to travel every day in the given list of days.



Example 1:

Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation:
For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total you spent $11 and covered all the days of your travel.*/

// O(365) time and space
class Solution {
    unordered_set<int> d;
    vector<int> dp;
    vector<int> cost;
public:
    int solve(int i) {
        if (i > 365) return 0;
        if (dp[i] != -1) return dp[i];

        int ans;
        if (d.count(i)) {
            ans = min(solve(i + 1) + cost[0], solve(i + 7) + cost[1]);
            ans = min(ans, solve(i + 30) + cost[2]);
        }
        else ans = solve(i + 1);

        return dp[i] = ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        cost = costs;
        int n = days.size();
        dp.assign(366, -1);

        for (int i : days) d.insert(i);

        return solve(1);
    }
};

///////////////////////////////////////////////////////
// O(N) time and space
class Solution {
    vector<int> dp;
    vector<int> duration{1, 7, 30};
    vector<int> costs, days;
public:
    int solve(int i) {
        if (i >= days.size()) return 0;

        if (dp[i] != -1) return dp[i];

        int ans = 1e6;
        int j = i;
        for (int k = 0; k < 3; ++k) {
            while (j < days.size() and days[j] < days[i] + duration[k]) j++;
            ans = min(ans, solve(j) + costs[k]);
        }

        return dp[i] = ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();

        this->days = days;
        this->costs = costs;
        dp.assign(n, -1);

        return solve(0);
    }
};