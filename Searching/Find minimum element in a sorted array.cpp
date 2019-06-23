/*Suppose a sorted array A is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array will not contain duplicates.*/

/* take example : 1 2 3 4 5 6 7 8 9 ==> after rotation : 5 6 7 8 9 1 2 3 4 . Notice that the previous element of the 
 minimum element is always greater than it. So, simply binary the number whose previous number is greater than it. */

int Solution::findMin(const vector<int> &A) {
    
    int n = A.size();
    int mid, l = 0, r = n-1;

    while(l <= r) {
    
        mid = (l+r)>>1;
    	// if A[mid+1] is the smallest number
        if(mid < r and A[mid] > A[mid+1]) return A[mid+1];
        // if A[mid] is the smallest number
        if(mid > l and A[mid-1] > A[mid]) return A[mid];
        
        // if middle element is smaller than the righmost element of this set
        // then it means that this part of the array [mid, r] is sorted. 
        // So A[mid] is the smallest in this set, so search for smaller elements than
        // A[mid] on the range [l, mid-1]
        if(A[r] > A[mid]) r = mid-1;
        else l = mid+1;
    }

    return A[0];
}
