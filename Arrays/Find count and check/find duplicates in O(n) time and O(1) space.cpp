/*Find duplicates in O(n) time and O(1) extra space
Given an array of n elements which contains elements from 0 to n-1, with any of these numbers appearing any number of times. 
Find these repeating numbers in O(n) and using only constant memory space.

For example, let n be 7 and array be {1, 2, 3, 1, 3, 6, 6}, the answer should be 1, 3 and 6.

This problem is an extended version of following problem.

Find the two repeating elements in a given array

Method 1 and Method 2 of the above link are not applicable as the question says O(n) time complexity and O(1) constant space. 
Also, Method 3 and Method 4 cannot be applied here because there can be more than 2 repeating elements in this problem. 
Method 5 can be extended to work for this problem. Below is the solution that is similar to the Method 5.

Algorithm:

traverse the list for i= 0 to n-1 elements
{
  check for sign of A[abs(A[i])] ;
  if positive then
     make it negative by   A[abs(A[i])]=-A[abs(A[i])];
  else  // i.e., A[abs(A[i])] is negative
     this   element (ith element of list) is a repetition
}
 */
void printRepeating(int arr[], int size)
{
  int i;
  printf("The repeating elements are: \n");
  for (i = 0; i < size; i++)
  {
    if (arr[abs(arr[i])] >= 0)
      arr[abs(arr[i])] = -arr[abs(arr[i])];
    else
      printf(" %d ", abs(arr[i]));
  }
}
 
int main()
{
  int arr[] = {1, 2, 3, 1, 3, 6, 6};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  printRepeating(arr, arr_size);
  getchar();
  return 0;
}
/*
Output:
The repeating elements are:
1  3  6
Note: The above program doesn’t handle 0 case (If 0 is present in array). The program can be easily modified to handle that also. 
It is not handled to keep the code simple. just take a variable zero and set it to true if 0 is found for the first time. 
So, that if again a 0 is found, then check the variable zero if it is true, means that 0 is repeating */