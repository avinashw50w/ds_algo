/*There are 2 sorted arrays A and B of size n each. Write an algorithm to find the median of the array
obtained after merging the above 2 arrays(i.e. array of length 2n). The complexity should be O(log(n)
//Note : since each array contains n elements, so the size of the array after merging will be 2n(even)
so, the median is the average the middle and next middle element.

Method 1: use binary search
Case 1: when total number of elements (n) is odd, then the median is at position n/2
Case 2: when total number of elements (n) is even, then the median is the sum of elements 
at position n/2 and position n/2-1
*/
// T: O(logN)
double median(vector<int> a, vector<int> b) {
    int n = a.size();
    int pos = n, l = -1e9, r = 1e9, mid;
    double ans = 0.0;

    // for case 1:
    while (l <= r) {
        mid = l + (r-l)/2;
        int ub = (upper_bound(a.begin(), a.end(), mid) - a.begin()) + 
        (upper_bound(b.begin(), b.end(), mid) - b.begin());
        if (ub <= pos) l = mid + 1;
        else r = mid - 1;
    }

    ans = l;

    // for case 2, we also need to find element at pos n/2-1
    pos--;
    l = -1e9;
    r = 1e9;

    while (l <= r) {
        mid = l + (r-l)/2;
        int ub = (upper_bound(a.begin(), a.end(), mid) - a.begin()) + 
        (upper_bound(b.begin(), b.end(), mid) - b.begin());
        if (ub <= pos) l = mid + 1;
        else r = mid - 1;
    }

    ans = (ans + l)/2;

    return ans;
}

/*
/*Method 2 (By comparing the medians of two arrays)
This method works by first getting medians of the two sorted arrays and then comparing them.

Let ar1 and ar2 be the input arrays.

Algorithm:

1) Calculate the medians m1 and m2 of the input arrays ar1[]
   and ar2[] respectively.
2) If m1 and m2 both are equal then we are done.
     return m1 (or m2)
3) If m1 is greater than m2, then median is present in one
   of the below two subarrays.
    a)  From first element of ar1 to m1 (ar1[0...|_n/2_|])
    b)  From m2 to last element of ar2  (ar2[|_n/2_|...n-1])
4) If m2 is greater than m1, then median is present in one
   of the below two subarrays.
   a)  From m1 to last element of ar1  (ar1[|_n/2_|...n-1])
   b)  From first element of ar2 to m2 (ar2[0...|_n/2_|])
5) Repeat the above process until size of both the subarrays
   becomes 2.
6) If size of the two arrays is 2 then use below formula to get
  the median.
    Median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2  */

/* O(logn) */
int median(int arr[], int n)
{
    if (n % 2 == 0)
        return (arr[n / 2] + arr[n / 2 - 1]) / 2;
    else
        return arr[n / 2];
}

int getMedian(int ar1[], int ar2[], int n)
{
    /* return -1  for invalid input */
    if (n <= 0)
        return -1;
    if (n == 1)
        return (ar1[0] + ar2[0]) / 2;
    if (n == 2)
        return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])) / 2;

    int m1 = median(ar1, n); /* get the median of the first array */
    int m2 = median(ar2, n); /* get the median of the second array */

    /* If medians are equal then return either m1 or m2 */
    if (m1 == m2)
        return m1;

    /* if m1 < m2 then median must exist in ar1[m1....] and
        ar2[....m2] */
    if (m1 < m2)
    {
        if (n % 2 == 0)
            return getMedian(ar1 + n / 2 - 1, ar2, n - (n / 2 - 1));
        return getMedian(ar1 + n / 2, ar2, n - n / 2);
    }

    /* if m1 > m2 then median must exist in ar1[....m1] and
        ar2[m2...] */
    if (n % 2 == 0)
        return getMedian(ar2 + n / 2 - 1, ar1, n - (n / 2 - 1));
    return getMedian(ar2 + n / 2, ar1, n - n / 2);
}

//////////////////////////////////////////////////////////////////
// Method 1: Simply count while merging.  Time Complexity: O(n)

int getMedian(int ar1[], int ar2[], int n) {
    int i = 0;  /* Current index of i/p array ar1[] */
    int j = 0; /* Current index of i/p array ar2[] */
    int count;
    int m1 = -1, m2 = -1;

    /* Since there are 2n elements, median will be average
     of elements at index n-1 and n in the array obtained after
     merging ar1 and ar2 */
    for (count = 0; count <= n; count++) {
        /*Below is to handle case where all elements of ar1[] are
          smaller than smallest(or first) element of ar2[]*/
        if (i == n) {
            m1 = m2;
            m2 = ar2[0];
            break;
        }

        /*Below is to handle case where all elements of ar2[] are
          smaller than smallest(or first) element of ar1[]*/
        else if (j == n) {
            m1 = m2;
            m2 = ar1[0];
            break;
        }

        if (ar1[i] < ar2[j]) {
            m1 = m2;  /* Store the prev median */
            m2 = ar1[i];
            i++;
        }
        else {
            m1 = m2;  /* Store the prev median */
            m2 = ar2[j];
            j++;
        }
    }

    return (m1 + m2) / 2;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////


