/*Find Maximum value of abs(i – j) * min(arr[i], arr[j]) in an array arr[]  */

// Function to calculate maximum value of 
// abs(i - j) * min(arr[i], arr[j]) in arr[]
const int inf = 1e9 + 7;
int maxProduct(vector<int> a) {
    int n = a.size();
    int l = 0, r = n-1;
    int maxprod = -inf;
    while (l < r) {
        int prod = (r-l) * min(a[l], a[r]);
        maxprod = max(maxprod, prod);
        if (a[l] < a[r]) l++;
        else r--;
    }
    return maxprod;
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