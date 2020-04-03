/*Given a set, we need to find maximum and minimum possible product among all subsets of the set.
Examples:

Input : arr[] = {4, -2, 5};
Output: Maximum product = 20 
        Minimum product = -40
Maximum product is obtained by multiplying
4 5
Minimum product is obtained by multiplying 
4, -2, 5

As array can have negative value, zero and positive value, this problem can have lot of edge cases, if not attacked properly. 
Below given solution maintains maximum product and minimum product at current index and previous index and at any instant 
current product takes value from previous max or previous min multiplied with current element, depending on the sign of 
current element. For example, if we are finding maximum product then current maximum will be previous max times current value 
if current element is positive otherwise previous min times current value if current element is negative.*/

pair<int, int> getMaxandMinProduct(int arr[], int n)
{
    // Initialize all products with arr[0]
    int curMaxProduct = arr[0];
    int curMinProduct = arr[0];
    int prevMaxProduct = arr[0];
    int prevMinProduct = arr[0];
    int maxProduct = arr[0];
    int minProduct = arr[0];
 
    // Process all elements after arr[0]
    for (int i = 1; i < n; ++i)
    {
        /* Current maximum product is maximum of following
            1) prevMax * curelement (when curelement is +ve)
            2) prevMin * curelement (when curelement is -ve)
            3) Element itself
            4) Previous max product */
        curMaxProduct = max(prevMaxProduct * arr[i],
                            max(prevMinProduct * arr[i],
                                arr[i]));
        curMaxProduct = max(curMaxProduct, prevMaxProduct);
 
        /* Current min product computation is Similar to
           that of current max profuct     */
        curMinProduct = min(prevMaxProduct * arr[i],
                            min(prevMinProduct * arr[i],
                                arr[i]));
        curMinProduct = min(curMinProduct, prevMinProduct);

        maxProduct = max(maxProduct, curMaxProduct);
        minProduct = min(minProduct, curMinProduct);
 
        // copy current values to previous values
        prevMaxProduct = curMaxProduct;
        prevMinProduct = curMinProduct;
    }
 
    return make_pair(minProduct, maxProduct);
}
 
//  driver code to test above methods
int main()
{
    int arr[] = {-4, -2, 3, 7, 5, 0, 1};
    int n = sizeof(arr) / sizeof(int);
    pair<int, int> product = getMaxandMinProduct(arr, n);
    printf("Minimum product is %d and "
            "Maximum product is %d\n",
             product.first, product.second);
    return 0;
}