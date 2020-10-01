/*You are given an array 𝑎, consisting of 𝑛 integers.

Each position 𝑖 (1≤𝑖≤𝑛) of the array is either locked or unlocked. You can take the values on the unlocked positions, rearrange them in any order and place them back into the unlocked positions. You are not allowed to remove any values, add the new ones or rearrange the values on the locked positions. You are allowed to leave the values in the same order as they were.

For example, let 𝑎=[−1,1,3⎯⎯,2,−2⎯⎯⎯⎯⎯,1,−4,0⎯⎯], the underlined positions are locked. You can obtain the following arrays:

[−1,1,3⎯⎯,2,−2⎯⎯⎯⎯⎯,1,−4,0⎯⎯];
[−4,−1,3⎯⎯,2,−2⎯⎯⎯⎯⎯,1,1,0⎯⎯];
[1,−1,3⎯⎯,2,−2⎯⎯⎯⎯⎯,1,−4,0⎯⎯];
[1,2,3⎯⎯,−1,−2⎯⎯⎯⎯⎯,−4,1,0⎯⎯];
and some others.
Let 𝑝 be a sequence of prefix sums of the array 𝑎 after the rearrangement. So 𝑝1=𝑎1, 𝑝2=𝑎1+𝑎2, 𝑝3=𝑎1+𝑎2+𝑎3, …, 𝑝𝑛=𝑎1+𝑎2+⋯+𝑎𝑛.

Let 𝑘 be the maximum 𝑗 (1≤𝑗≤𝑛) such that 𝑝𝑗<0. If there are no 𝑗 such that 𝑝𝑗<0, then 𝑘=0.

Your goal is to rearrange the values in such a way that 𝑘 is minimum possible.

Output the array 𝑎 after the rearrangement such that the value 𝑘 for it is minimum possible. If there are multiple answers then print any of them.

Input
The first line contains a single integer 𝑡 (1≤𝑡≤1000) — the number of testcases.

Then 𝑡 testcases follow.

The first line of each testcase contains a single integer 𝑛 (1≤𝑛≤100) — the number of elements in the array 𝑎.

The second line of each testcase contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (−105≤𝑎𝑖≤105) — the initial array 𝑎.

The third line of each testcase contains 𝑛 integers 𝑙1,𝑙2,…,𝑙𝑛 (0≤𝑙𝑖≤1), where 𝑙𝑖=0 means that the position 𝑖 is unlocked and 𝑙𝑖=1 means that the position 𝑖 is locked.

Output
Print 𝑛 integers — the array 𝑎 after the rearrangement. Value 𝑘 (the maximum 𝑗 such that 𝑝𝑗<0 (or 0 if there are no such 𝑗)) should be minimum possible. For each locked position the printed value should be equal to the initial one. The values on the unlocked positions should be an arrangement of the initial ones.

If there are multiple answers then print any of them.

Example
inputCopy
5
3
1 3 2
0 0 0
4
2 -3 4 -1
1 1 1 1
7
-8 4 -2 -6 4 7 1
1 0 0 0 1 1 0
5
0 1 -4 6 3
0 0 0 1 1
6
-1 7 10 4 -8 -1
1 0 0 0 0 1
outputCopy
1 2 3
2 -3 4 -1
-8 -6 1 4 4 7 -2
-4 0 1 6 3
-1 4 7 -8 10 -1
Note
In the first testcase you can rearrange all values however you want but any arrangement will result in 𝑘=0. For example, for an arrangement [1,2,3], 𝑝=[1,3,6], so there are no 𝑗 such that 𝑝𝑗<0. Thus, 𝑘=0.

In the second testcase you are not allowed to rearrange any elements. Thus, the printed array should be exactly the same as the initial one.

In the third testcase the prefix sums for the printed array are 𝑝=[−8,−14,−13,−9,−5,2,0]. The maximum 𝑗 is 5, thus 𝑘=5. There are no arrangements such that 𝑘<5.

In the fourth testcase 𝑝=[−4,−4,−3,3,6].

In the fifth testcase  𝑝=[−1,3,10,2,12,11]*/

int main() {
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n), l(n);
        for (int &x : a) cin >> x;
        for (int &x : l) cin >> x;

        vector<int> b;
        for (int x : l) {
            if (x == 0) b.push_back(x);
        }

        sort(b.rbegin(), b.rend());

        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (l[i] == 0) a[i] = b[k++];
        }

        for (int i = 0; i < n; ++i) {
            if (i > 0) cout << " ";
            cout << a[i];
        }
        cout << "\n";
    }
}