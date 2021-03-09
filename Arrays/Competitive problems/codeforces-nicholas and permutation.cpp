/**Nicholas has an array a that contains n distinct integers from 1 to n.
In other words, Nicholas has a permutation of size n.

Nicholas want the minimum element (integer 1) and the maximum element (integer n)
 to be as far as possible from each other. He wants to perform exactly
 one swap in order to maximize the distance between the minimum and the maximum
 elements. The distance between two elements is considered to be equal to the
  absolute difference between their positions.

Input
The first line of the input contains a single integer n (2 ≤ n ≤ 100) —
the size of the permutation.

The second line of the input contains n distinct integers a 1, a 2, ..., a n (1 ≤ a i ≤ n), where a i is equal to the element at the i-th position.

Output
Print a single integer — the maximum possible distance between the minimum
and the maximum elements Nicholas can achieve by performing exactly one swap.

Examples
inputCopy
5
4 5 1 3 2
outputCopy
3 */
#include <bits/stdc++.h>
using namespace std;

int n, i, a, pn, p1;

main() {
    cin >> n;
    // find index of 1 and n, ie the min and max no
    for (i = 0; i < n; i++) {
        cin >> a;
        if (a == n) pn = i + 1;
        if (a == 1) p1 = i + 1;
    }
    // return the position of the p1 or pn, depending on which is farthest from the start of array
    cout << max(
             max(p1 - 1, n - p1), // if we swap the max element to the front or to end
             max(pn - 1, n - pn) // if we swap the min element to the front or to end
         );
}
