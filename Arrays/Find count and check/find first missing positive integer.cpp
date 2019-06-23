/*Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.*/
/* take the example of [3, 4, 1, -1] , we need to arrange the array such that each positive number is at its 
correct position ,ie,( 1, -1, 3, 4 ) . Since the array is 0 indexed, a positive number x should be at index x-1.
Here, we can see that 3 is not at its correct position, it should be at index 2, so we swap the element at index 2 with 3, 
and recursively check whether the new swapped number is at its correct position or not. Finally, after doing the arrangement,
we check from the start of the array, the first index i where the value is not i+1, then i+1 is our answer. */
class Solution {
public:
  
    static void correct(vector<int>& a, int idx) {
        
        if(a[idx] < a.size()) {
            if(a[a[idx]-1] != a[idx]) {
                swap(a[a[idx]-1], a[idx]);
                
                if(a[idx] > 0 and a[idx] != idx+1)
                    correct(a, idx);
            }
        }
    }

    int firstMissingPositive(vector<int>& a) {
        int n = a.size();
        
        for(int i = 0; i < n; ++i) 
            if(a[i] > 0 and a[i] != (i+1)) 
               correct(a, i)
        
        for(int i = 0; i < n; ++i)
            if(a[i] != i+1) return i+1;
            
        return n+1;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////
/*We can use sorting to solve it in lesser time complexity. We can sort the array in O(nLogn) time. Once the array is sorted, 
then all we need to do is a linear scan of the array. So this approach takes O(nLogn + n) time which is O(nLogn).

We can also use hashing. We can build a hash table of all positive elements in the given array. Once the hash table is built. 
We can look in the hash table for all positive integers, starting from 1. As soon as we find a number which is not there in hash table, 
we return it. This approach may take O(n) time on average, but it requires O(n) extra space.

A O(n) time and O(1) extra space solution:
The idea is similar to this post. We use array elements as index. To mark presence of an element x, we change the value at the index x to negative. 
But this approach doesn’t work if there are non-positive (-ve and 0) numbers. 
So we segregate positive from negative numbers as first step and then apply the approach.

Following is the two step algorithm.
1) Segregate positive numbers from others i.e., move all non-positive numbers to left side. 
In the following code, segregate() function does this part.
2) Now we can ignore non-positive elements and consider only the part of array which contains all positive elements. 
We traverse the array containing all positive numbers and to mark presence of an element x, we change the sign of 
value at index x to negative. We traverse the array again and print the first index which has positive value. 
In the following code, findMissingPositive() function does this part. Note that in findMissingPositive, 
we have subtracted 1 from the values as indexes start from 0 in C.*/
 
/* Utility function that puts all non-positive (0 and negative) numbers on left 
  side of arr[] and return count of such numbers */
int segregate (int arr[], int size) {
    int j = 0, i;
    for(i = 0; i < size; i++){
       if (arr[i] <= 0) {
           swap(arr[i], arr[j]);
           j++;  // increment count of non-positive integers
       }
    return j;
}
 
/* Find the smallest positive missing number in an array that contains
  all positive integers */
int findMissingPositive(int arr[], int size)
{
  int i;
 
  // Mark arr[i] as visited by making arr[arr[i] - 1] negative. Note that 
  // 1 is subtracted because index start from 0 and positive numbers start from 1
  for(i = 0; i < size; i++)
  {
    if(abs(arr[i]) - 1 < size && arr[abs(arr[i]) - 1] > 0)
      arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
  }
  // Return the first index value at which is positive
  for(i = 0; i < size; i++)
    if (arr[i] > 0)
      return i+1;  // 1 is added becuase indexes start from 0
 
  return size+1;
}
 
/* Find the smallest positive missing number in an array that contains
  both positive and negative integers */
int findMissing(int arr[], int size)
{
   // First separate positive and negative numbers
   int shift = segregate (arr, size);
  
   // Shift the array and call findMissingPositive for
   // positive part
   return findMissingPositive(arr+shift, size-shift);
}
 
int main()
{
  int arr[] = {4,3,-1,1};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  int missing = findMissing(arr, arr_size);
  printf("The smallest positive missing number is %d ", missing);
  getchar();
  return 0;
}