/*Maximize number of 0s by flipping a subarray
Given a binary array, find the maximum number zeros in an array with one flip of a subarray allowed. A flip operation switches all 0s to 1s and 1s to 0s.

Examples:

Input :  arr[] = {0, 1, 0, 0, 1, 1, 0}
Output : 6
We can get 6 zeros by flipping the subarray {1, 1}

Input :  arr[] = {0, 0, 0, 1, 0, 1}
Output : 5

/*Method 2 (Efficient : O(n))

This problem can be reduced to largest subarray sum problem. The idea is to consider every 0 as -1 and every 1 as 1,
find the sum of largest subarray sum in this modified array. This sum is our required max_diff
( count of 0s – count of 1s in any subarray). Finally we return the max_diff plus count of zeros in original array.*/

int findMaxZeroCount(bool arr[], int n)
{
    // Initialize count of zeros and maximum difference
    // between count of 1s and 0s in a subarray
    int orig_zero_count = 0;

    // Initiale overall max diff for any subarray
    int max_diff = 0;

    // Initialize current diff
    int curr_max = 0;

    for (int i = 0; i < n; i++)
    {
        // Count of zeros in original array (Not related
        // to Kadane's algorithm)
        orig_zero_count += a[i] == 0;

        // Value to be considered for finding maximum sum
        int val = (arr[i] == 1) ? 1 : -1;

        // Update current max and max_diff
        curr_max = max(val, curr_max + val);
        max_diff = max(max_diff, curr_max);
    }
    max_diff = max(0, max_diff);

    return orig_zero_count + max_diff;
}

/* Let the subarray to flip be A, then
Max no of 0s in the array = total no of 0s in the original array - No of 0s in A + No of 1s in A
                          = total no of 0s in the original array + (No of 1s in A - No of 0s in A)
*/


/*Method 1 (Simple : O(n2))

A simple solution is to consider all subarrays and find a subarray with maximum value of (count of 1s) – (count of 0s).
Let this value be max_diff. Finally return count of zeros in original array plus max_diff.*/
int findMaxZeroCount(bool arr[], int n) {

    int max_diff = 0, orig_zero_count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            orig_zero_count++;

        int count1 = 0, count0 = 0;

        for (int j = i; j < n; j++)
        {
            (arr[j] == 1) ? count1++ : count0++;
            max_diff = max(max_diff, count1 - count0);
        }
    }

    return orig_zero_count + max_diff;
}
