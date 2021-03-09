/*Sort an array according to absolute difference with given value
2.5
Given an array of n distinct elements and a number x, arrange array elements according to the absolute difference with x, i. e.,
element having minimum difference comes first and so on.
Note : If two or more elements are at equal distance arrange them in same sequence as in the given array.

Examples :

Input : arr[] : x = 7, arr[] = {10, 5, 3, 9, 2}
Output : arr[] = {5, 9, 10, 3, 2}
Explanation:
7 - 10 = 3(abs)
7 - 5 = 2
7 - 3 = 4
7 - 9 = 2(abs)
7 - 2 = 5
So according to the difference with X,
elements are arranged as 5, 9, 10, 3, 2.

Input : x = 6, arr[] = {1, 2, 3, 4, 5}
Output :  arr[] = {5, 4, 3, 2, 1}

Input : x = 5, arr[] = {2, 6, 8, 3}
Output :  arr[] = {6, 3, 2, 8}*/

void solve(int a[], int n, int x) {
    map<int, vector<int>> mp;

    for (int i = 0; i < n; ++i)
        mp[abs(a[i] - x)].push_back(a[i]);

    int k = 0;

    for (auto p : m) {
        for (int e : p.second) a[k++] = e;
    }
}

/////////// using array
void solve(int a[], int n, int x) {
    int mx = *max_element(a, a + n);
    vector<int> f[mx + 1];
    for (int i = 0; i < n; ++i)
        f[abs(a[i] - x)].push_back(a[i]);

    int k = 0;
    for (int i = 0; i <= mx; ++i) {
        for (int x : f[i]) a[k++] = x;
    }
}

int main() {
    int arr[] = {10, 5, 3, 9 , 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;

    solve(arr, n, x);

    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
}