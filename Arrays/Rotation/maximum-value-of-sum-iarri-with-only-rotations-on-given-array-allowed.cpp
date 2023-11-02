/*Find maximum value of Sum( i*arr[i]) with only rotations on given array allowed
3.4
Given an array, only rotation operation is allowed on array. We can rotate the array as many times as we want. 
Return the maximum possbile of summation of i*arr[i].

Example:

Input: arr[] = {1, 20, 2, 10}
Output: 72
We can 72 by rotating array twice.
{2, 10, 1, 20}
20*3 + 1*2 + 10*1 + 2*0 = 72

Input: arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
Output: 330
We can 330 by rotating array 9 times.
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
0*1 + 1*2 + 2*3 ... 9*10 = 330

Let Rj be value of i*arr[i] with j rotations. The idea is to calculate next rotation value from previous rotation, i.e., 
calculate Rj from Rj-1. We can calculate initial value of result as R0, then keep calculating next rotation values.
How to efficiently calculate Rj from Rj-1?
This can be done in O(1) time. Below are details.

Let us calculate initial value of i*arr[i] with no rotation
R0 = 0*arr[0] + 1*arr[1] +...+ (n-1)*arr[n-1]

After 1 rotation arr[n-1], becomes first element of array, 
arr[0] becomes second element, arr[1] becomes third element
and so on.
R1 = 0*arr[n-1] + 1*arr[0] +...+ (n-1)*arr[n-2]

R1 - R0 = arr[0] + arr[1] + ... + arr[n-2] - (n-1)*arr[n-1]
        = arr[0] + arr[1] + ... + arr[n-2] + arr[n-1] + n*arr[n-1]

After 2 rotations arr[n-2], becomes first element of array, 
arr[n-1] becomes second element, arr[0] becomes third element
and so on.
R2 = 0*arr[n-2] + 1*arr[n-1] +...+ (n?1)*arr[n-3]

R2 - R1 = arr[0] + arr[1] + ... + arr[n-3] - (n-1)*arr[n-2] + arr[n-1]

If we take a closer look at above values, we can observe 
below pattern

Rj - Rj-1 = arrSum - n * arr[n-j]

Where arrSum is sum of all array elements, i.e., 

arrSum = ? arr[i]
        i<=0<=n-1 
Below is complete algorithm:

1) Compute sum of all array elements. Let this sum be 'arrSum'.

2) Compute R0 by doing i*arr[i] for given array. 
   Let this value be currVal.

3) Initialize result: maxVal = currVal // maxVal is result.

// This loop computes Rj from  Rj-1 
4) Do following for j = 1 to n-1
......a) currVal = currVal + arrSum-n*arr[n-j];
......b) If (currVal > maxVal)
            maxVal = currVal   

5) Return maxVal
Below are C++ and Python implementations of above idea.

*/
// C++ program to find max value of i*arr[i]
 
// Returns max possible value of i*arr[i]
int maxSum(int arr[], int n)
{
    int arrSum = 0, currVal = 0;
    
    for (int i=0; i<n; i++) {
        arrSum 	+= arr[i];
        currVal += (i*arr[i]);
    }
 
    int maxVal = currVal;

    for (int j=1; j<n; j++) {
        currVal = currVal + arrSum - n*arr[n-j];
        maxVal = max(maxVal, currVal);
    }
 
    return maxVal;
}
 
int main(void)
{
    int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "\nMax sum is " << maxSum(arr, n);
    return 0;
}
