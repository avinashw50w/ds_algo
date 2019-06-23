/*We are given an array of digits (values lie in range from 0 to 9). The task is to count all the sub sequences 
possible in array such that in each subsequence every digit is greater than its previous digits in the subsequence.

Examples:

Input : arr[] = {1, 2, 3, 4}
Output: 15
There are total increasing subsequences
{1}, {2}, {3}, {4}, {1,2}, {1,3}, {1,4}, 
{2,3}, {2,4}, {3,4}, {1,2,3}, {1,2,4}, 
{1,3,4}, {2,3,4}, {1,2,3,4}

The above solution doesn't use the fact that we have only 10 possible values in given array. 
We can use this fact by using an array count[] such that count[d] stores current count digits smaller than d.
For example, arr[] = {3, 2, 4, 5, 4}

// We create a count array and initialize it as 0.
count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

// Note that here value is used as index to store counts
count[3] += 1 = 1  // i = 0, arr[0] = 3
count[2] += 1 = 1  // i = 1, arr[0] = 2

// Let us compute count for arr[2] which is 4
count[4] += 1 + count[3] + count[2] += 1 + 1 + 1  = 3

// Let us compute count for arr[3] which is 5
count[5] += 1 + count[3] + count[2] + count[4] 
         += 1 + 1 + 1 + 3
         = 6

// Let us compute count for arr[4] which is 4
count[4] += 1 + count[0] + count[1]
         += 1 + 1 + 1
         += 3
         = 3 + 3
         = 6
            
Note that count[] = {0, 0, 1, 1, 6, 6, 0, 0, 0, 0}                  
Result = count[0] + count[1] + ... + count[9]
       = 1 + 1 + 6 + 6 {count[2] = 1, count[3] = 1
                        count[4] = 6, count[5] = 6} 
       = 14.*/

int countSub(int arr[], int n)
{
    // count[] array is used to store all sub-
    // sequences possible using that digit
    // count[] array covers all the digit
    // from 0 to 9
    int count[10] = {0};
 
    // scan each digit in arr[]
    for (int i=0; i<n; i++)
    {
        // count all possible sub-sequences by
        // the digits less than arr[i] digit
        for (int j=arr[i]-1; j>=0; j--)
            count[arr[i]] += count[j];
 
        // store sum of all sub-sequences plus
        // 1 in count[] array
        count[arr[i]]++;
    }
 
    // now sum up the all sequences possible in
    // count[] array
    int result = 0;
    for (int i=0; i<10; i++)
        result += count[i];
 
    return result;
}