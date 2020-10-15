/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Examples:

Input: arr[]   = {2, 0, 2}
Output: 2
Structure is like below
| |
|_|
We can trap 2 units of water in the middle gap.

Input: arr[]   = {3, 0, 0, 2, 0, 4}
Output: 10
Structure is like below
     |
|    |
|  | |
|__|_|
We can trap "3*2 units" of water between 3 an 2,
"1 unit" on top of bar 2 and "3 units" between 2
and 4.  See below diagram also.

Input: arr[] = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
Output: 6
       |
   |   || |
_|_||_||||||
Trap "1 unit" between first 1 and 2, "4 units" between
first 2 and 3 and "1 unit" between second last 1 and last 2

A Simple Solution is to traverse every array element and find the highest bars on left and right sides. Take the smaller of two heights.
The difference between smaller height and height of current element is the amount of water that can be stored in this array element.
Time complexity of this solution is O(n2).

An Efficient Solution is to prre-compute highest bar on left and right of every bar in O(n) time. Then use these pre-computed
values to find the amount of water in every array element. Below is C++ implementation of this solution.*/

// in place algo
// idea: water trapped at index i = max(left_max, right_max) - a[i]
// so instead of calculating the water trapped at index i,
//  calcuate the water trapped at left_max and keep updating the left_max

int solve(vector<int> a) {
    int n = a.size();
    int left_max = -1, right_max = -1;
    int l = 0, r = n - 1, ans = 0;
    while (l <= r) {
        // note that left_max will always be less than a[r] and greater than a[l]
        // coz we update left_max to max(left_max, a[l]) when a[l] < a[r]
        if (a[l] < a[r]) {
            if (a[l] > left_max) left_max = a[l];
            else ans += left_max - a[l]; // water trapped at l
        }
        else {
            if (a[r] > right_max) right_max = a[r];
            else ans += right_max - a[r];
        }
    }

    return ans;
}

///////////////////////////////////////////

int findWater(int arr[], int n)
{
    // left[i] contains height of tallest bar to the
    // left of i'th bar including itself
    int left[n];

    // Right [i] contains height of tallest bar to
    // the right of ith bar including itself
    int right[n];

    int water = 0;

    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);

    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);

    // Calculate the accumulated water element by element
    // consider the amount of water on i'th bar, the
    // amount of water accumulated on this particular
    // bar will be equal to min(left[i], right[i]) - arr[i] .
    for (int i = 0; i < n; i++)
        water += min(left[i], right[i]) - arr[i];

    return water;
}

////////////////////////////////////////////////////////////////////////
