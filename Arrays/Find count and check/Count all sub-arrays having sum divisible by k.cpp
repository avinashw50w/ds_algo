/*Count all sub-arrays having sum divisible by k
You are given an array of positive and/or negative integers and a value K . 
The task is to find count of all sub-arrays whose sum is divisible by K?

Examples:

Input  : arr[] = {4, 5, 0, -2, -3, 1}, 
         K = 5
Output : 7
there are 7 sub-arrays whose is divisible by K
{4, 5, 0, -2, -3, 1}
{5}
{5, 0}
{5, 0, -2, -3}
{0}
{0, -2, -3}
{-2, -3}

Let's suppose A[i...j] is divisible by k
=> A[i...j] % k = 0
=> (A[0...j] - A[0...i-1]) % k = 0 // exclusion inclusion principle
=> A[0...j] % k - A[0...i-1] % k = 0
=> A[0...j] % k = A[0...i-1] % k

Which means we have to count the no of prefix sums sum[L], sum[R] whose residue modulo k is same,
where sum[i] = sum[0] + sum[1] + ... + sum[i]
*/

// function to find all sub-arrays divisible by k
int subCount(int arr[], int n, int k)
{
    int mod[k];
    memset(mod, 0, sizeof(mod));
 
    int cumSum = 0;
    for (int i=0; i<n; i++)
    {
        cumSum += arr[i];
        mod[cumSum%k]++;
    }
 
    int result = 0;  // Initialize result
 
    if (mod[0] == 1)
        result = 1;
 
    for (int i=0; i<k ; i++)
        if (mod[i] > 1)
            result += (mod[i]*(mod[i]-1))/2;
 
    return result;
}
 
int main()
{
    int arr[] = {4, 5, 0, -2, -3, 1};
    int k = 5;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << subCount(arr, n, k);
    return 0;
}