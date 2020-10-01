/*Maximum water that can be stored between two buildings
Given an integer array which represents the heights of N buildings, the task is to delete N-2 buildings such that the water that can be trapped between the remaining two building is maximum. Please note that the total water trapped between two buildings is gap between them (number of buildings removed) multiplied by height of the smaller building.

Examples:

Input: arr[] = {1, 3, 4}
Output: 1
We have to calculate the maximum water that can be stored between any 2 buildings.
Water between the buildings of height 1 and height 3 = 0.
Water between the buildings of height 1 and height 4 = 1.
Water between the buildings of height 3 and height 4 = 0.
Hence maximum of all the cases is 1.

Input: arr[] = {2, 1, 3, 4, 6, 5}
Output: 8
We remove the middle 4 buildings and get the total water stored as 2 * 4 = 8

IDEA: Take two pointers i and j pointing to the first and the last building respectively and calculate the water that can be stored between these two buildings. Now increment i if height[i] < height[j] else decrement j. This is because the water that can be trapped is dependent on the height of the small building and moving from the greater height building will just reduce the amount of water instead of maximizing it. In the end, print the maximum amount of water calculated so far.*/

int maxWater(int height[], int n) {

    int maximum = 0;

    int i = 0, j = n - 1;

    while (i < j) {

        if (height[i] < height[j])
        {
            maximum = max(maximum, (j - i - 1) * height[i]);
            i++;
        }
        else if (height[j] < height[i])
        {
            maximum = max(maximum, (j - i - 1) * height[j]);
            j--;
        }
        else
        {
            maximum = max(maximum, (j - i - 1) * height[i]);
            i++;
            j--;
        }
    }

    return maximum;
}