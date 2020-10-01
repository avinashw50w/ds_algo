/*Suppose you have some guests arriving at a party.
For each guest, you are given the arrival and departure time.
When a guest arrives he is given a wine glass and when he leaves he returns that wine glass
(it becomes available to be given to another guest).
Find the minimum number of wine glasses needed to serve all the guests. The arrival
and departure team can only be between 1800 to 2359 hours.*/

/*initial we need 1 glass, we will need extra glasses only if timings of two guests overlap
    --------    ---------
        ------------
                  -----------

so the maximum no of glasses required will be when the overlap is maximum
*/

int solve(vector<vector<int>> timings) {
    vector<int> f(2350 - 1800 + 1);

    for (auto t : timings) {
        f[t[0] - 1800]++;
        f[t[1] + 1 - 1800]--;
    }
    int glasses = f[0];
    for (int i = 1; i < f.size(); ++i) {
        f[i] += f[i - 1];
        glasses = max(glasses, f[i]);
    }

    return glasses;
}