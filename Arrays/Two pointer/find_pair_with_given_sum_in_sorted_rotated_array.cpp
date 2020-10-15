/*Given a sorted and rotated array, find if there is a pair with a given sum.
Input: arr[] = {11, 15, 6, 8, 9, 10}, x = 16
Output: true
There is a pair (6, 10) with sum 16
*/

bool check(int a[], int n, int x) {
    // find the index of the smallest no
    int i = 0;
    for (i = 0; i < n ++i) {
        if (a[i] > a[i + 1]) break;
    }
    // set l to the index of the smallest no and r to the highest no
    int l = (i + 1) % n;
    int r = i;

    while (l != r) {
        if (a[l] + a[r] == x) return true;
        else if (a[l] + a[r] < x) l = (l + 1) % n;
        else r = (r - 1 + n) % n;
    }

    return false;
}

// How to count all pairs having sum x?

int count(int a[], int n, int x) {
    int i = 0;
    for (i = 0; i < n ++i) {
        if (a[i] > a[i + 1]) break;
    }

    int l = (i + 1) % n;
    int r = i;

    int cnt = 0;

    while (l != r) {
        if (a[l] + a[r] == x) {
            cnt++;

            if (l == (r - 1 + n) % n) return cnt;

            l = (l + 1) % n;
            r = (r - 1 + n) % n;
        }
        else if (a[l] + a[r] < x) l = (l + 1) % n;
        else r = (r - 1 + n) % n;
    }

    return cnt;
}
