// C program to segregate even and odd elements of array so that all the even nos comes before all the odd nos

// method 1
void solve(vector<int> &a) {
    int k = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] % 2 == 0) swap(a[k++], a[i]);
    }
}

// method 2
void segregateEvenOdd(int arr[], int n) {
    int l = 0, r = n - 1;

    while (l < r) {

        while (l < r && arr[l] % 2 == 0) l++;

        while (l < r && arr[r] % 2 == 1) r--;

        if (l < r) {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }
}
/* driver program to test */
int main()
{
    int arr[] = {12, 34, 45, 9, 8, 90, 3};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int i = 0;

    segregateEvenOdd(arr, arr_size);

    printf("Array after segregation ");
    for (i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);

    return 0;
}

/*
Output:
Array after segregation 12 34 90 8 9 45 3
Time Complexity: O(n)

*/