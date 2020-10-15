/*We can Use Hashing to solve this problem in O(n) time. The idea is to iterate through the array and for every element arr[i],
calculate sum of elements form 0 to i (this can simply be done as sum += arr[i]). If the current sum has been seen before, then
there is a zero sum array. Hashing is used to store the sum values, so that we can quickly store sum and find out whether the
current sum is seen before or not.
eg,  index :  0   1   2   3   4   5   6   7
  elements : 15  -2   2  -8   1   7  10  23
      sum  : 15  13  15   7   8  15  25  48      */

int maxLen(int A[], int n)
{
  int sum = 0, max_len = 0;
  unordered_map<int, int> m;

  for (int i = 0; i < n; ++i) {
    sum += A[i];

    if (sum == 0) max_len = i + 1;

    if (m.count(sum))
      max_len = max(max_len, i - m[sum]);
    else m[sum] = i;
  }
  return max_len;
}


///////////////////////////////////////////////////////////////////////////////////////////////////
// another variation of the problem :
/*Given an array of 0's and 1's your task is to complete the function maxLen which returns  size of  the
largest subarray with equal number of 0's and 1's .The function maxLen takes 2 arguments .
The first argument is the array A[] and second argument is the size 'N' of the array A[] .

solution: keep adding the prefix sum, in place of 0's add -1. when a sum of 0 appears, then update the max_len.
Also store the occurence of other sums, and check if the current sum has appeared before or not.
If yes, then update max_len by the diff between the index of the current sum and the previous sum*/
int maxLen(int arr[], int n)
{
  int sum = 0, max_len = 0;
  unordered_map<int, int> m;

  for (int i = 0; i < n; ++i) {
    if (arr[i]) sum += 1;
    else sum -= 1;

    if (sum == 0) max_len = i + 1;

    if (m.find(sum) != m.end()) max_len = max(max_len, i - m[sum]);
    else m[sum] = i;
  }

  return max_len;
}
