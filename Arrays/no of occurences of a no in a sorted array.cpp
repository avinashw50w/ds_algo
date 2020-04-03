/*Method 2 (Use Binary Search)
1) Use Binary search to get index of the first occurrence of x in arr[]. Let the index of the first occurrence be i.
2) Use Binary search to get index of the last occurrence of x in arr[]. Let the index of the last occurrence be j.
3) Return (j � i + 1);

/* if x is present in arr[] then returns the count of occurrences of x, 
   otherwise returns -1. */



// using STL lower and upper bound


int count(int a[], int x, int n) {

    int l = lower_bound(a, a+n, x) - a;
    int r = upper_bound(a, a+n, x) - a;

    return r-l;
}

// using binary search for first and last occurence

int first(int a[], int n, int x) {
    int l = 0, r = n-1, mid;
    int ans = -1;

    while (l <= r) {
        mid = (l+r) >> 1;
        if (x <= a[mid]) ans = mid, r = mid-1;
        else l = mid+1;
    }
    return ans;
}

int last(int a[], int n, int x) {
    int l = 0, r = n-1, mid;
    int ans = -1;

    while(l <= r) {
        mid = (l+r) >> 1;
        if (a[mid] <= x) ans = mid, l = mid+1;
        else r = mid-1
    }

    return ans;
}

int count(int a[], int x, int n) {

    int l = first(a, x, n);
    int r = last(a, x, n);

    if (l != -1 and r != -1) return r-l+1;
    else return 0;
}
 
/* driver program to test above functions */
int main()
{
  int arr[] = {1, 2, 2, 3, 3, 3, 3};
  int x =  3;  // Element to be counted in arr[]
  int n = sizeof(arr)/sizeof(arr[0]);
  int c = count(arr, x, n);
  printf(" %d occurs %d times ", x, c);
  getchar();
  return 0;
}
