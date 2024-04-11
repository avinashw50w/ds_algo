// Given an array A of N elements. If a person is at index i then the person can jump A[i] steps to the
// right. Find min no of jumps to reach from start to end.
/* In this method, we build a jumps[] array from left to right such that jumps[i] indicates the minimum number of jumps needed to reach arr[i] from arr[0].
 Finally, we return jumps[n-1].  time complexity O(n2)*/

#include <bits/stdc++.h>
using namespace std;

int solve(int a[], int n) {
    int dp[n];
    fill(dp, dp + n, INT_MAX);

    if (a[0] == 0) return -1;
    dp[0] = 0;

    for (int i = n - 2; i >= 0; --i) {
        if (a[i] >= n - i - 1) dp[i] = 1;
        else {
            int mn = INT_MAX;
            for (int j = 0; j < n && j < a[i]; j++) {
                int k = j + i + 1;
                mn = min(mn, dp[k]);
            }

            if (mn != INT_MAX) dp[i] = 1 + mn;
        }
    }

    return (dp[0] == INT_MAX ? -1 : dp[0]);
}

int main() {
    int a[] = {2, 4, 1, 1, 0};
    int n = sizeof(a) / sizeof(a[0]);

    cout << solve(a, n);
}


#include<bits/stdc++.h>
#define oo (1<<30)
using namespace std;
int minJumps(int arr[], int n) {
    int *jumps = new int[n];
    if (n == 0 || arr[0] == 0) return 0;
    jumps[0] = 0;

    // for reaching position i
    for (int i = 1; i < n; i++) {
        jumps[i] = oo;
        // using j amount of jumps
        for (int j = 0; j < i; j++) {
            if (j + arr[j] <= i && arr[j] != oo)
                jumps[i] = min(jumps[i] , jumps[j] + 1);
            break;
        }
    }
    return jumps[n - 1];
}

/*In this method, we build jumps[] array from right to left such that jumps[i] indicates the minimum number of jumps needed to reach arr[n-1] from arr[i].
 Finally, we return jumps[0].  time complexity O(n2) in worst case.
*/
int minJumps(int arr[], int n) {
    int *jumps = new int[n];
    jumps[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] == 0) jumps[i] = oo;

        else if ((n - 1) - i <= arr[i]) jumps[i] = 1;

        else {
            jumps[i] = oo;
            for (int j = i + 1; j < n && (j - i) <= arr[i]; j++)
                jumps[i] = min(jumps[i] , jumps[j] + 1);
        }
    }
    return jumps[0];
}



int main()
{
    vector<int> arr = {1, 3, 6, 1, 0, 9};
    printf("Minimum number of jumps to reach end is %d ", minJumps(arr));
    return 0;
