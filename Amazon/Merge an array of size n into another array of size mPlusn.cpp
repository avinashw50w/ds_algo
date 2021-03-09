/*Merge an array of size n into another array of size m+n
There are two sorted arrays. First one is of size m+n containing only m elements.
Another one is of size n and contains n elements. Merge these two arrays into the first array of size m+n such that the output is sorted.

Let first array be mPlusN[] and other array be N[]
1) Move m elements of mPlusN[] to end.
2) Start from nth element of mPlusN[] and 0th element of N[] and merge them
    into mPlusN[].*/

void merge(vector<int> &A, vector<int> B, int m, int n) {
  int i = m - 1, j = n - 1, k = m + n - 1;

  while (i >= 0 and j >= 0) {
    if (B[j] >= A[i]) A[k--] = B[j--];
    else A[k--] = A[i--];
  }

  while (j >= 0) A[k--] = B[j--];
}

//////////////////////////////////////////////////////////////////////////
#define NA -1

void moveToEnd(int *M, int sz) {
  int i, j = sz - 1;
  for (i = sz - 1; i >= 0; --i) {
    if (M[i] != NA)
      M[j--] = M[i];
  }
}

void merge(int M[], int N[], int m, int n) {
  int i = n;  // starting index for M
  int j = 0; // starting index for N
  int k = 0; // starting index for final M

  while (k < m + n) {
    /* Take an element from mPlusN[] if
       a) value of the picked element is smaller and we have
          not reached end of it
       b) We have reached end of N[] */
    if ((i < m + n and M[i] <= N[j]) or (j == n))
      M[k++] = M[i++];

    else  // Otherwise take element from N[]
      M[k++] = N[j++];
  }
}

int main()
{
  /* Initialize arrays */
  int mPlusN[] = {2, 8, NA, NA, NA, 13, NA, 15, 20};
  int N[] = {5, 7, 9, 25};
  int n = sizeof(N) / sizeof(N[0]);
  int m = sizeof(mPlusN) / sizeof(mPlusN[0]) - n;

  /*Move the m elements at the end of mPlusN*/
  moveToEnd(mPlusN, m + n);

  /*Merge N[] into mPlusN[] */
  merge(mPlusN, N, m, n);

  /* Print the resultant mPlusN */
  printArray(mPlusN, m + n);

  return 0;
}