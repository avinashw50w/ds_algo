/*Method 2 (Use Sorting and Binary Search)

sort the two arrays and check whether the smaller array is a subsequence of the larger array

Thanks to Parthsarthi for suggesting this method.

/* Return 1 if arr2[] is a subset of arr1[] */
bool isSubset(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
     
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + n);

    for (int i = 0; i < n; ++i) {
        if (arr1[i] == arr2[j]) j++;
    }

    return (j == m);
} 
/*
Method 4 (Use Hashing)
1) Create a Hash Table for all the elements of arr1[].
2) Traverse arr2[] and search for each element of arr2[] in the Hash Table. If element is not found then return 0.
3) If all elements are found then return 1.*/