/*Rearrange an array in maximum minimum form | Set 2 (O(1) extra space)

Given a sorted array of positive integers, rearrange the array alternately i.e first element should be the maximum value,
second minimum value, third-second max, fourth-second min and so on.

Examples:

Input  : arr[] = {1, 2, 3, 4, 5, 6, 7}
Output : arr[] = {7, 1, 6, 2, 5, 3, 4}

Input  : arr[] = {1, 2, 3, 4, 5, 6}
Output : arr[] = {6, 1, 5, 2, 4, 3}*/

/*Method 2 :
Time Complexity: O(n)
Space Complexity: O(1)

*/
/*The idea is to use multiplication and modular trick to store two elements at an index.*/
vector<int> rearrange(vector<int> a) {
    int n = a.size(), min_idx = 0, max_idx = n - 1;
    int K = a[n - 1] + 1;

    // to store two numbers in a single number, take a number k greater than both the numbers a and b
    // then do a = (a % k) * k + b
    // to retrieve a do: a / k
    // to retrieve b do: a % k
    for (int i = 0; i < n; ++i) {
        if (i & 1 ^ 1) { // if index is even
            a[i] = (a[max_idx] % K) * K + a[i];
            max_idx--;
        }
        else {
            a[i] = (a[min_idx] % K) * K + a[i];
            min_idx++;
        }
    }

    vector<int> res;
    for (int i = 0; i < n; ++i) {
        res.push_back(a[i] / K);
        // revert back the array
        a[i] %= K;
    }
}

////////////////////////////////////////////////////////////////////////
// Method 1:
/* Time complexity: O(n)
   Space complexity: O(n)
*/

void rearrange(int arr[], int n) {
    int temp[n];

    int small = 0, large = n - 1;
    int flag = true;

    for (int i = 0; i < n; i++)
    {
        if (flag)
            temp[i] = arr[large--];
        else
            temp[i] = arr[small++];

        flag = !flag;
    }

    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

///////////////////////////////////////////////////////////////////
