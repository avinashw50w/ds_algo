/*Find a pair with the given difference
Given an unsorted array and a number n, find if there exists a pair of elements in the array whose difference is n.
Examples:

Input: arr[] = {5, 20, 3, 2, 50, 80}, n = 78
Output: Pair Found: (2, 80)

Input: arr[] = {90, 70, 20, 80, 50}, n = 45
Output: No Such Pair */

pair<int,int> solve(int a[], int n) {

    sort(a, a + n);

    int i = 0, j = 1;

    while(i < n and j < n) {
        if (i != j and a[j]-a[i] == n) return {a[j], a[i]};
        else if (a[j] - a[i] > n) i++;
        else j++;  
    }

    return {};
}