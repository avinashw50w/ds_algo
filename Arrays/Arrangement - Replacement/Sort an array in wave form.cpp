/*Sort an array in wave form
2.6
Given an unsorted array of integers, sort the array into a wave like array. An array ‘arr[0..n-1]’ is sorted in wave
form if arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..

Examples:

 Input:  arr[] = {10, 5, 6, 3, 2, 20, 100, 80}
 Output: arr[] = {10, 5, 6, 2, 20, 3, 100, 80} OR
                 {20, 5, 10, 2, 80, 6, 100, 3} OR
                 any other array that is in wave form*/

void solve(int a[], int n) {
    for (int i = 0; i < n; i += 2) {
        if (i > 0 and a[i - 1] > a[i]) swap(a[i - 1], a[i]);

        if (i < n and a[i] < a[i + 1]) swap(a[i], a[i + 1]);
    }
}

///////////// OR ///////////////
void solve(vector<int> &a) {
    bool flag = true;
    for (int i = 0; i < a.size() - 1; ++i) {
        if (flag) {
            if (a[i] < a[i + 1]) swap(a[i], a[i + 1]);
        } else {
            if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
        }

        flag ^= 1;
    }
}