/*The hiring team of Google aims to find 3 candidates who are great collectively. Each candidate has
his or her ability expressed as an integer. 3 candidate are great collectively if product of their abilities is maximum.
Find the maximum collective ability from the given pool of candidates.

1 ≤ T ≤ 100
3 ≤ N ≤ 1000
-1000 ≤ ability ≤ 1000  */

// sol 1: find first, second and third max say A,B and C, first and second min say a and b
// then ans = max(A * B * C, A * a * b)
/*
IDEA: we need three max elements and two min elements,
then maximum product = max(prod of 3 max elements, prod of two min elements and the max element)
 */

sort(a, a + n, greater<int>);
return max(a[0] * a[1] * a[2], a[0] * a[n - 1] * a[n - 2]);


/* Sort the array, then check every possible case
Case 1: when all numbers are -ve : ans = prod of 3 most least -ve numbers
Case 2: when all numbers are -ve or zero : ans = 0
Case 3: when there are only +ve numbers : ans = prod of 3 most largest numbers
Case 4: when there are +ve numbers and there are atleat 2 -ve numbers:
        ans = max(3 most largest numbers, 2 least -ve numbers * the largest +ve number)
*/

int main() {

    caset{
        int n; cin >> n;
        int a[n], pos = 0, zero = 0, neg = 0;
        rep(i, 0, n) {
            cin >> a[i];
            if (a[i] >= 0) pos = 1;
            if (a[i] == 0) zero = 1;
            if (a[i] < 0) neg++;
        }
        sort(a, a + n);

        ll ans;
        if (!pos) {
            if (!zero)
                ans = a[n - 1] * a[n - 2] * a[n - 3];
            else ans = 0;
        }

        else {
            if (neg >= 2)
                ans = max(a[0] * a[1] * a[n - 1], a[n - 1] * a[n - 2] * a[n - 3]);
            else
                ans = a[n - 1] * a[n - 2] * a[n - 3];
        }

        cout << ans << endl;
    }

    return 0;
}
