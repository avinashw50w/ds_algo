/*Find Maximum value of abs(i – j) * min(arr[i], arr[j]) in an array arr[]  */

// Function to calculate maximum value of 
// abs(i - j) * min(arr[i], arr[j]) in arr[]
int Maximum_Product(int arr[], int n)
{
    int maxProduct = INT_MIN; // Initialize result
    int currProduct; // product of current pair
 
    // loop  until they meet with each other
    int Left = 0, right = n-1;
    while (Left < right)
    {
        if (arr[Left] < arr[right])
        {
            currProduct = arr[Left]*(right-Left);
            Left++;
        }
        else // arr[right] is smaller
        {
            currProduct = arr[right]*(right-Left);
            right--;
        }
 
        // maximizing the product
        maxProduct = max(maxProduct, currProduct)
    }
 
    return maxProduct;
}

/*How does this work?
The important thing to show that we don't miss any potential pair in above linear algorithm, i.e., 
we need to show that doing left++ or right-- doesn't lead to a case where we would have got higher value of maxProduct.

Please note that we always multiply with (right - left).

1) If arr[left] < arr[right], then smaller values of right for current left are useless as they can not produce 
higher value of maxProduct (because we multiply with arr[left] with (right - left)). What if arr[left] was greater 
than any of the elements on its left side. In that case, a better pair for that element must have been found with current right. 
Therefore we can safely increase left without missing any better pair with current left.

2) Similar arguments are applicable when arr[right] < arr[left].*/