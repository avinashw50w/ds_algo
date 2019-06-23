/*Find the largest pair sum in an unsorted array
Given an unsorted of distinct integers, find the largest pair sum in it. For example, the largest pair sum in {12, 34, 10, 6, 40} is 74.

This problem mainly boils down to finding the largest and second largest element in array. 
We can find the largest and second largest in O(n) time by traversing array once.*/

int findLargestSumPair(int arr[], int n)
{
    int first, second;
    if (arr[0] > arr[1])
    {
        first = arr[0];
        second = arr[1];
    }
    else
    {
        first = arr[1];
        second = arr[0];
    }
 
    for (int i = 2; i<n; i ++)
    {
        if (arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
 
        else if (arr[i] > second && arr[i] != first)
            second = arr[i];
    }
    return (first + second);
}