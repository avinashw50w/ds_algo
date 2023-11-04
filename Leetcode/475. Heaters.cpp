/*Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

Note:

Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
As long as a house is in the heaters' warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.


Example 1:

Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.*/

class Solution {
public:
    int closest(int x, vector<int> a) {
        int ans = INT_MAX;
        int idx = upper_bound(a.begin(), a.end(), x) - a.begin();
        if (idx < a.size()) ans = min(ans, a[idx] - x);
        if (idx) ans = min(ans, x - a[idx - 1]);
        return ans;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int ans = INT_MIN;

        for (int e : houses) {
            int dist = closest(e, heaters);
            ans = max(ans, dist);
        }

        return ans;
    }
};

/////////////////////////////////////////
// another way is to solve it using painter's partition technique
class Solution {
public:
    // Checks if with the given radius all the houses can be covered or not
    bool housesCovered(vector<int> houses, vector<int>& heaters,
                       int radius) {
        int left = heaters[0] - radius;
        int right = heaters[0] + radius;
        int heater_idx = 0, house_idx = 0;

        while (house_idx < houses.size()) {
            if (houses[house_idx] >= left && houses[house_idx] <= right) {
                ++house_idx;
            }
            else {
                ++heater_idx;
                if (heater_idx == heaters.size())
                    return false;
                left = heaters[heater_idx] - radius;
                right = heaters[heater_idx] + radius;
            }
        }
        return true;
    }

    // TC: O(nlogn + mlogm + nlogn)
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (houses.empty())
            return true;
        if (heaters.empty())
            return false;

        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int low = 0, high = abs(max(houses.back(), heaters.back()) - houses.front());

        while (low < high) {
            int radius = low + (high - low) / 2;
            // check if the radius is enough to cover all the houses
            if (housesCovered(houses, heaters, radius))
                high = radius;
            else
                low = radius + 1;
        }
        return high;
    }
};