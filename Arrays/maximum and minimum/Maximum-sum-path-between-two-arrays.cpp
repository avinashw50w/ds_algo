/*Maximum Sum Path in Two Arrays
Given two sorted arrays such the arrays may have some common elements. Find the sum of the maximum sum path to reach
from beginning of any array to end of any of the two arrays. We can switch from one array to another array only at common elements.

Expected time complexity is O(m+n) where m is the number of elements in ar1[] and n is the number of elements in ar2[].

Examples:

Input:  ar1[] = {2, 3, 7, 10, 12}, ar2[] = {1, 5, 7, 8}
Output: 35
35 is sum of 1 + 5 + 7 + 10 + 12.
We start from first element of arr2 which is 1, then we
move to 5, then 7.  From 7, we switch to ar1 (7 is common)
and traverse 10 and 12.

Input:  ar1[] = {10, 12}, ar2 = {5, 7, 9}
Output: 22
22 is sum of 10 and 12.
Since there is no common element, we need to take all
elements from the array with more sum.

Input:  ar1[] = {2, 3, 7, 10, 12, 15, 30, 34}
        ar2[] = {1, 5, 7, 8, 10, 15, 16, 19}
Output: 122
122 is sum of 1, 5, 7, 8, 10, 12, 15, 30, 34

The idea is to do something similar to merge process of merge sort. We need to calculate sums of elements between all common points
for both arrays. Whenever we see a common point, we compare the two sums and add the maximum of two to the result. Following are detailed steps.

1) Initialize result as 0. Also initialize two variables sum1 and sum2 as 0. Here sum1 and sum2 are used to store sum of element
in ar1[] and ar2[] respectively. These sums are between two common points.

2) Now run a loop to traverse elements of both arrays. While traversing compare current elements of ar1[] and ar2[].

    2.a) If current element of ar1[] is smaller than current element of ar2[], then update sum1, else if current element
    of ar2[] is smaller, then update sum2.

    2.b) If current element of ar1[] and ar2[] are same, then take the maximum of sum1 and sum2 and add it to the result.
    Also add the common element to the result.*/

int maxPathSum(vector<int> a1, vector<int> a2) {
    int n = a1.size(), m = a2.size();
    int sum1 = 0, sum2 = 0, result = 0;
    int i = 0, j = 0;

    while (i < n and j < m) {
        if (a1[i] < a2[j]) {
            sum1 += a1[i++];
        }
        else if (a2[j] < a1[i]) {
            sum2 += a2[j++];
        }
        else {
            result += max(sum1, sum2);
            sum1 = sum2 = 0;

            while (i < n and j < m and a1[i] == a2[j]) {
                result += a1[i];
                i++; j++;
            }
        }
    }

    while (i < n) sum1 += a1[i++];
    while (j < m) sum2 += a2[j++];

    result += max(sum1, sum2);

    return result;
}
