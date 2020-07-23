/*XOR TEST
Given an integer array A of size N, you need to perform
2 operations over this array :0 L R : Find and print A[L] xor A[L+1] xor A[L+2] ... xor A[R]1 X Y : Update the value of the
Xth element of array [X] to (A[X] XOR Y) . That is, after the update the value of the element shall be (A[X] XOR Y).

Can you do it ?

Input Format :

The first line contains a single integer N denoting the size of array A. The next line contains N space separated integers,
where the ith element denotes A[i]. The third line contains the number of operations Q and then each of the remaining
Q lines contain three space separated integers, where the ith line denotes the parameters of the ith query.

Output Format :

For each operation of the form

0 L R, display the answer for the operation in a separate line.

Sample Input
5
1 2 3 4 5
5
0 3 4
1 3 4
0 3 4
1 4 3
0 3 4*/

#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 2;

int bit[maxn], a[maxn], n, q;

void update(int i, int val) {
    for (; i <= n; i += i & -i) bit[i] ^= val;
}

int query(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i) res ^= bit[i];
    return res;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], update(i, a[i]);;

    cin >> q;

    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 0) cout << (query(r) ^ query(l - 1)) << endl;
        else {
            update(l, r);
            a[l] ^= r;
        }
    }
    return 0;
}
