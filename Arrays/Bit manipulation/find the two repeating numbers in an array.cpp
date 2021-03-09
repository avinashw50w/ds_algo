/*Find the two repeating elements in a given array
You are given an array of n+2 elements. All elements of the array are in range 1 to n.
And all elements occur once except two numbers which occur twice. Find the two repeating numbers.

For example, array = {4, 2, 4, 5, 2, 3, 1} and n = 5

The above array has n + 2 = 7 elements with all elements occurring once except 2 and 4 which occur twice. So the output should be 4 2.


Method 4 (Use XOR)
Thanks to neophyte for suggesting this method.
The approach used here is similar to method 2 of this post.
Let the repeating numbers be X and Y, if we xor all the elements in the array and all integers from 1 to n, then the result is X xor Y.
The 1’s in binary representation of X xor Y is corresponding to the different bits between X and Y. Suppose that the kth bit of X xor Y is 1,
we can xor all the elements in the array and all integers from 1 to n, whose kth bits are 1. The result will be one of X and Y.*/

void printRepeating(int arr[], int size)
{
  int xorr = arr[0]; /* Will hold xor of all elements */
  int set_bit_no;  /* Will have only single set bit of xor */
  int i;
  int n = size - 2;
  int x = 0, y = 0;

  /* Get the xor of all elements in arr[] and {1, 2 .. n} */
  for (i = 1; i < size; i++)
    xorr ^= arr[i];
  for (i = 1; i <= n; i++)
    xorr ^= i;

  /* Get the rightmost set bit in set_bit_no */
  set_bit_no = xorr & ~(xorr - 1);

  /* Now divide elements in two sets by comparing rightmost set
   bit of xor with bit at same position in each element. */
  for (i = 0; i < size; i++)
  {
    if (arr[i] & set_bit_no)
      x = x ^ arr[i]; /*XOR of first set in arr[] */
    else
      y = y ^ arr[i]; /*XOR of second set in arr[] */
  }
  for (i = 1; i <= n; i++)
  {
    if (i & set_bit_no)
      x = x ^ i; /*XOR of first set in arr[] and {1, 2, ...n }*/
    else
      y = y ^ i; /*XOR of second set in arr[] and {1, 2, ...n } */
  }

  printf("\n The two repeating elements are %d & %d ", x, y);
}

///////////////////////////////////////////////////////////////////////
// Method 5 (Use array elements as index)

void findRepeating(int a[], int n) {

  for (int i = 0; i < n; ++i) {
    if (a[abs(a[i])] > 0)
      a[abs(a[i])] = -a[abs(a[i])];
    else
      cout << abs(a[i]) << " ";
  }
}