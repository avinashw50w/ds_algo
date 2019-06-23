/*Given three arrays sorted in non-decreasing order, print all common elements in these arrays.

Examples:

ar1[] = {1, 5, 10, 20, 40, 80}
ar2[] = {6, 7, 20, 80, 100}
ar3[] = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20, 80

ar1[] = {1, 5, 5}
ar2[] = {3, 4, 5, 5, 10}
ar3[] = {5, 5, 10, 20}
Output: 5, 5  */
// This function prints common elements in ar1
void findCommon(int ar1[], int ar2[], int ar3[], int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0;
 
    // Iterate through three arrays while all arrays have elements
    while (i < n1 && j < n2 && k < n3)
    {
         if (ar1[i] == ar2[j] && ar2[j] == ar3[k])
         {   cout << ar1[i] << " ";   i++; j++; k++; }
 
         else if (ar1[i] < ar2[j])
             i++;
 
         else if (ar2[j] < ar3[k])
             j++;
 
         else
             k++;
    }
}

/*Time complexity of the above solution is O(n1 + n2 + n3). In worst case, the largest sized 
array may have all small elements and middle sized array has all middle elements.*/
