/*A Product Array Puzzle
Given an array arr[] of n integers, construct a Product Array prod[] (of same size) such that prod[i] is equal to
the product of all the elements of arr[] except arr[i]. Solve it without division operator and in O(n).

Example:
arr[] = {10, 3, 5, 6, 2}
prod[] = {180, 600, 360, 300, 900}

Algorithm:
1) Construct a temporary array left[] such that left[i] contains product of all elements on left of arr[i] excluding arr[i].
2) Construct another temporary array right[] such that right[i] contains product of all elements on on right of arr[i] excluding arr[i].
3) To get prod[], multiply left[] and right[].*/

void productPuzzle(int a[], int n) {

    int left[n], right[n], prod[n];

    left[0] = 1, right[n - 1] = 1;

    for (int i = 1; i < n; ++i)
        left[i] = a[i - 1] * left[i - 1];

    for (int i = n - 2; i >= 0; --i)
        right[i] = a[i + 1] * right[i + 1];

    for (int i = 0; i < n; ++i)
        prod[i] = left[i] * right[i];

    for (int i = 0; i < n; ++i) cout << prod[i] << " ";
}