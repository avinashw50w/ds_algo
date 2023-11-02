/*Given an array a of n elements, where a[i] represents the height of buildings.
Choose any two buildings i and j such that after removing all the building except
i and j, the amount of water trapped btw the building i and j is maximum.
summary: need to find the maximum value of min(a[i], a[j]) * (j - i)
IDEA: use two pointer approach,

NOTE: if (height[l] < height[r]) l++;
here we have incremented l instead of decr r;
Suppose we decr r, then there can be 2 cases
case 1:
    height[r-1] > height[l], in this case we will still choose height[l],
    so, ans becomes height[l] * (r-1-1), since dist has decreased so ans has decreased
case 2:
    height[r-1] < height[l], in this case ans = height[r-1] * (r-1-l), 
    since chosen height is decreased from prev so ans has decreased
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


