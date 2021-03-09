/*There is a one-dimensional garden on the x-axis. The garden starts at the point 0 and ends at the point n. (i.e The length of the garden is n).

There are n + 1 taps located at points [0, 1, ..., n] in the garden.

Given an integer n and an integer array ranges of length n + 1 where ranges[i] (0-indexed) means the i-th tap can water the area [i - ranges[i], i + ranges[i]] if it was open.

Return the minimum number of taps that should be open to water the whole garden, If the garden cannot be watered return -1.*/

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> jumps(n + 1, 0);
        // jumps[i] stores the max distance to which tap can water from index i
        for (int i = 0; i < ranges.size(); ++i) {
            int pos = max(0, i - ranges[i]);
            jumps[pos] = max(i + ranges[i], jumps[pos]);
        }

        int end = 0, pos = 0, cnt = 0;
        // we are not considering i = n, coz we don't need to jump when we reach n
        for (int i = 0; i < n; ++i) {
            if (end < i) return -1;

            end = max(end, jumps[i]);

            if (pos == i) {
                cnt++;
                pos = end;
            }
        }

        return end >= n ? cnt : -1;
    }
};