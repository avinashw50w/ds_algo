/*Given an array of integers which is initially increasing and then decreasing, find the maximum value in the array.
Examples :

Input: arr[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1}
Output: 500
*/


int find(int a[], int n) {
    int l = 0, r = n - 1, mid;

    while (l <= r) {
        // if only a single element
        if (l == r) return a[l];
        // if there are two elements
        if (r - l == 1) {
            if (a[l] >= a[r]) return a[l];
            else return a[r];
        }
        mid = (l + r) >> 1;
        // if the middle ele is greater than its left and right ele, then return it
        if (a[mid - 1] < a[mid]  and a[mid] > a[mid + 1]) return a[mid];
        // if the middle ele lie in the decreasing sequence, then move to left
        if (a[mid - 1] > a[mid] and a[mid] > a[mid + 1]) r = mid - 1;
        else l = mid + 1;
    }

    return 0;
}

int main()
{
    int arr[] = {1, 3, 50, 10, 9, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The maximum element is %d", find(arr, n));
    return 0;
}