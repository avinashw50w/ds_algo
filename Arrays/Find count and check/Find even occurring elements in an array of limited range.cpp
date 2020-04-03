/*Find even occurring elements in an array of limited range
Given an array that contains odd number of occurrences for all numbers except for a few elements which are present even number of times. 
Find the elements which have even occurrences in the array in O(n) time complexity and O(1) extra space.
Assume array contain elements in the range 0 to 63.

Examples:

Input: [9, 12, 23, 10, 12, 12, 15, 23, 14, 12, 15]
Output: 12, 23 and 15

Input: [1, 4, 7, 5, 9, 7, 3, 4, 6, 8, 3, 0, 3]
Output: 4 and 7

A simple method would be to traverse the array and store frequencies of its elements in a map. Later, print elements that have even count in the map. 
The solution takes O(n) time but requires extra space for storing frequencies. Below is an interesting method to solve this problem using bitwise operators.

This method assumes that long long integers are stored using 64 bits. The idea is to use XOR operator. We know that

1 XOR 1 = 0
1 XOR 0 = 1
0 XOR 1 = 1
0 XOR 0 = 0
Consider below input –

 1, 4, 7, 5, 9, 7, 3, 4, 6, 8, 3, 0, 3 
If we right shift 1 by value of each element of the array and take XOR of all the items, we will get below binary integer –

1101101011
Each 1 in the i’th index from the right represents odd occurrence of element i. 
And each 0 in the i’th index from the right represents even or non-occurrence of element i in the array.

0 is present in 2nd, 4th and 7th position in above binary number. But 2 is not present in our array. So our answer is 4 and 7.*/

void printRepeatingEven(int arr[], int n)
{
    long long _xor = 0L;
    long long pos;
 
    // do for each element of array
    for( int i = 0; i < n; ++i)
    {
        // Toggle the bit everytime element gets repeated
        _xor ^= (1 << a[i]);
    }
 
    // Traverse array again and use _xor to find even
    // occuring elements
    for (int i = 0; i < n; ++i)
    {
        // Each 0 in _xor represents an even occurrence
        if ((_xor & (1 << a[i])) == 0)
        {
            // print the even occurring numbers
            cout << arr[i] << " ";
 
            // set bit as 1 to avoid printing duplicates
            _xor ^= pos;
        }
    }
}