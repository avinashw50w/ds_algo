/*In QuickSort, partition function is in-place, but we need extra space for recursive function calls. A simple implementation of QuickSort makes 
two calls to itself and in worst case requires O(n) space on function call stack.The worst case happens when the selected pivot always divides the 
array such that one part has 0 elements and other part has n-1 elements. For example, in below code, if we choose last element as pivot, 
we get worst case for sorted arrays (See this for visualization)  */

/* A Simple implementation of QuickSort that makes two
   two recursive calls. */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
  
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
/*
Can we reduce the auxiliary space for function call stack?
We can limit the auxiliary space to O(Log n). The idea is based on tail call elimination. As seen in the previous post, we can convert the code so that it makes one recursive call. For example, in the below code, we have converted the above code to use a while loop and have reduced the number of recursive calls.  */

/* QuickSort after tail call elimination using while loop */
void quickSort(int arr[], int low, int high)
{
    while (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
 
        low = pi+1;
    }
}
/*
Although we have reduced number of recursive calls, the above code can still use O(n) auxiliary space in worst case. In worst case, it is possible 
that array is divided in a way that the first part always has n-1 elements. For example, this may happen when last element is choses as pivot and array 
is sorted in decreasing order.
We can optimize the above code to make a recursive call only for the smaller part after partition. Below is implementation of this idea.
Further Optimization :   */

/* This QuickSort requires O(Log n) auxiliary space in
   worst case. */
void quickSort(int arr[], int low, int high)
{
    while (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // If left part is smaller, then recur for left
        // part and handle right part iteratively
        if (pi - low < high - pi)
        {
            quickSort(arr, low, pi - 1);
            low = pi + 1;
        }
 
        // Else recur for right part
        else
        {
            quickSort(arr, pi + 1, high);
            high = pi - 1;
        }
    }
}