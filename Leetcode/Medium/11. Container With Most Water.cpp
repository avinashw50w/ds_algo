/*You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Sol: Max water that can be trapped between any two lines(if all other lines are removed)
use two pointer approach:
l = 0, r = end
current water trapped = min(height[l], height[r]) * (r - l)
if (height[l] < height[r]) 
    then we can either inc l or dec r
    if we decrement r, then height[r-1] can be either greater or smaller than height[l]
    if height[r-1] is greater than height[l] then still we will choose height[l] since it is 
    the smaller. so there will be no effect in the ans;
    if height[r-1] is smaller than height[l] then we will choose height[r-1] and currWater will 
    become height[r-1] * (r-1 - l), but it will decrease our ans since height[r-1] < height[l].
    So the best option in this case will be to increment l
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int l = 0, r = n - 1;
        int water = 0;
        while (l < r) {
            int currWater = min(height[l], height[r]) * ( r - l );
            water = max(water, currWater);

            if (height[l] < height[r]) l++;
            else r--;
        }

        return water;
    }
};