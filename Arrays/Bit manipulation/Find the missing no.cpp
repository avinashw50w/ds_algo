/*Find the Missing Number
You are given a list of n-1 integers and these integers are in the range of 1 to n. There are no duplicates in list.
One of the integers is missing
in the list. Write an efficient code to find the missing integer.
Example:
I/P    [1, 2, 4, ,6, 3, 7, 8]
O/P    5
*/

//Time Complexity: O(n)
/*
METHOD 2(Use XOR)

  1) XOR all the array elements, let the result of XOR be x.
  2) XOR all numbers from 1 to n with x.
  3) x is the required ans.
  */

/* getMissingNo takes array and size of array as arguments*/
int getMissingNo(vector<int> a)
{
  int i, x = 0;

  for (int i = 0; i < a.size(); ++i) x ^= a[i];
  for (int i = 1; i <= a.size() + 1; ++i) x ^= i;

  return x;
}

/*METHOD 1(Use sum formula)
Algorithm:
1. Get the sum of numbers
       total = n*(n+1)/2
2  Subtract all the numbers from sum and
   you will get the missing number.*/
/* getMissingNo takes array and size of array as arguments*/
int getMissingNo (int a[], int n)
{
  int i, total;
  total  = (n + 1) * (n + 2) / 2;
  for ( i = 0; i < n; i++)
    total -= a[i];
  return total;
}

/*program to test above function */
int main()
{
  int a[] = {1, 2, 4, 5, 6};
  int miss = getMissingNo(a, 5);
  printf("%d", miss);
  getchar();
}
/*Time Complexity: O(n)

In method 1, if the sum of the numbers goes beyond maximum allowed integer, then there can be integer overflow and we may not get correct answer.
Method 2 has no such problems.*/
