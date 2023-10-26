/*Given an array a of n elements, where a[i] represents the height of buildings.
Choose any two buildings i and j such that after removing all the building except
i and j, the amount of water trapped btw the building i and j is maximum.
summary: need to find the maximum value of min(a[i], a[j]) * (j - i - 1)
IDEA: use two pointer approach,
set l = 0 and r = n-1
if height[l] < height[r], then
	update ans = max(ans, height[l] * (r - l + 1))
now we can either increment l or decrement r,
if we decrement r then height[r-1] can be either larger or smaller than height[l]
if height[r-1] is larger then the ans will still be the same
if height[r-1] is smaller then ans will decrease coz now ans will be height[r-1] * (r-l+1)
so we have to increment l

if height[r] < height[l], then
	update ans = max(ans, height[r] * (r - l + 1))
	decrement r
*/
// time complexity : O(N)
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


