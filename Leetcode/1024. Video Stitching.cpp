/*You are given a series of video clips from a sporting event that lasted T seconds.  
These video clips can be overlapping with each other and have varied lengths.

Each video clip clips[i] is an interval: it starts at time clips[i][0] and ends at time clips[i][1].  We can cut these clips into segments freely: for example, a clip [0, 7] can be cut into segments [0, 1] + [1, 3] + [3, 7].

Return the minimum number of clips needed so that we can cut the clips into segments that cover the entire sporting event ([0, T]).  If the task is impossible, return -1.

Example 1:

Input: clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], T = 10
Output: 3
Explanation:
We take the clips [0,2], [8,10], [1,9]; a total of 3 clips.
Then, we can reconstruct the sporting event as follows:
We cut [1,9] into segments [1,2] + [2,8] + [8,9].
Now we have segments [0,2] + [2,8] + [8,10] which cover the sporting event [0, 10].

Constraints:

1 <= clips.length <= 100
0 <= clips[i][0] <= clips[i][1] <= 100
0 <= T <= 100

    ------------
        -----
       ----------------
*/

class Solution {
    const int INF = 1e9;
public:

    // using dp
    // dp[i] - minimum cuts needed for clips upto time i
    // [a...b] [b...c], if we know the answer upto T = b then dp[i] = min(dp[i], 1 + dp[b])
    // where b <= i <= c
    int videoStitching(vector<vector<int>>& clips, int T) {
        int n = clips.size();
        sort(clips.begin(), clips.end());
        vector<int> dp(101, INF);

        dp[0] = 0;

        for (auto clip : clips) {
            int s = clip[0];
            int e = clip[1];
            for (int i = s; i <= e; ++i) {
                // make a cut at i
                dp[i] = min(dp[i], 1 + dp[s]);
            }
        }

        return dp[T] == INF ? -1 : dp[T];
    }

    // usign greedy
    int videoStitching(vector<vector<int>>& clips, int T) {
        int n = clips.size();
        // since we need the process minimum no of clips, so sort by start time.
        sort(clips.begin(), clips.end());
        int ans = 0;
        int end = 0;
        int i = 0;

        while (end < T) {
            ans++;
            int currEnd = end;
            // find the clip whose start time is <= the current end and its end time is the 
            // largest
            while (i < n and clips[i][0] <= currEnd) {
                end = max(end, clips[i][1]);
                i++;
            }

            if (currEnd == end) return -1;
        }

        return ans;
    }
};