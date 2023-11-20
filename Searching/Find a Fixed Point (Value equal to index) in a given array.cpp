/*Find a Fixed Point (Value equal to index) in a given array
Given an array of n distinct integers sorted in ascending order, write a function that returns a Fixed Point in the array, if there is any Fixed Point present in array, else returns -1. Fixed Point in an array is an index i such that arr[i] is equal to i. Note that integers in array can be negative.

Examples:

  Input: arr[] = {-10, -5, 0, 3, 7}
  Output: 3  // arr[3] == 3 

  Input: arr[] = {0, 2, 5, 8, 17}
  Output: 0  // arr[0] == 0 

idea: 
if element at index i is greater than i, ie. a[i] > i, then we can never find the answer in the right side of i, coz array is strictly increasing, so next number will be atleast a[i] + 1 and index is also 
increasing by 1, so every index after i, a[j] will be greater than j.
That's why we search the left side of i
*/

int find(int a[], int n) {

    int l = 0, r = n-1, mid;

    while(l <= r) {
        mid = (l+r)>>1;
        if (mid == a[mid]) return mid;
        if (mid < a[mid]) r = mid-1;
        else l = mid+1;
    }
}

// recursive
int search(int a[], int l, int r) {

    while (l <= r) {
        int mid = (l+r)>>1;
        if (a[mid] == mid) return mid;

        if(a[mid] < mid) return search(a, mid+1, r);
        else return search(a, l, mid-1);
    }
}