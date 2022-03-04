/*Given a list of n sorted transations. Merge these transactions such that at any point of time
the sum of the transactions is non-negative. If found to negative, then print “-1”. Otherwise, 
print the merged list of transactions.
Input: arr[][] = {{100 → 400 → -1000 → -500}, 
                  {-300 → 2000 → -500}}
Output: 100 → 400 → -300 → 2000 → -500 → -1000 → -500
Explanation: The sum at every instant of the above list of transactions is given by {100, 500, 200, 2200, 1700, 700, 200}, which has no negative values.*/

vector<int> solve(vector<vector<int>> list) {
    vector<int> res;
    // max heap
    priority_queue<array<int,3>> pq;
    for (int i = 0; i < list.size(); ++i) {
        pq.push({ list[i][0], i, 0 });
    }

    while (pq.size()) {
        auto top = pq.top(); pq.pop();
        int val = top[0], i = top[1], j = top[2];
        res.push_back(val);
        if (j + 1 < list[i].size()) pq.push({ list[i][j+1], i, j + 1 });
    }

    return res;
}