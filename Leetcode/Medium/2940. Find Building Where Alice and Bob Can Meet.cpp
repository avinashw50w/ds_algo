/*You are given a 0-indexed array heights of positive integers, where heights[i] represents the height of 
the ith building.

If a person is in building i, they can move to any other building j if and only if i < j and heights[i] < heights[j].

You are also given another array queries where queries[i] = [ai, bi]. On the ith query, Alice is in 
building ai while Bob is in building bi.

Return an array ans where ans[i] is the index of the leftmost building where Alice and Bob can meet on 
the ith query. If Alice and Bob cannot move to a common building on query i, set ans[i] to -1.

IDEA: first store the queries in a map where key = max index, value = {max height, query index}
Then iterate throught the heights from left to right and find all the queries for which the current height
can be the answer.*/
class Solution {
    typedef array<int,2> arr;
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int qlen = queries.size();
        set<arr> st;
        map<int, vector<arr>> mp;
        vector<int> ans(qlen, -1);

        for (int i = 0; i < qlen; ++i) {
            auto q = queries[i];
            int a = q[0], b = q[1];
            if (b > a and  heights[a] < heights[b]) ans[i] = b;
            else if (a > b and heights[a] > heights[b]) ans[i] = a;
            else if (a == b) ans[i] = a;
            else mp[max(a,b)].push_back({max(heights[a], heights[b]), i});
        }

        priority_queue<arr, vector<arr>, greater<arr>> pq;

        for (int i = 0; i < n; ++i) {

            while (!pq.empty() and pq.top()[0] < heights[i]) {
                ans[pq.top()[1]] = i;
                pq.pop();
            }
            for (auto it: mp[i]) {
                pq.push(it);
            }
        }

        return ans;
    }
};