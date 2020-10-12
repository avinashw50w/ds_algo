/*Its time for yet another challenge, and this time it has been prepared by none other than Monk himself for Super-Hardworking Programmers like you. So, this is how it goes:

Given N points located on the co-ordinate plane, where the ith point is located at co-ordinate (xi,yi),
 you need to answer q queries.

In the ith query, you shall be given an integer ri, and considering you draw a circle centered at the origin (0,0)
 with radius ri, you need to report the number of points lying inside or on the circumference of this circle.

For each query, you need to print the answer on a new line.

Input Format :

The first line contains a single integer N denoting the number of points lying on the co-ordinate plane. Each of the next N lines contains 2 space separated integers xi and yi, denoting the x and y co-ordintaes of the ith point.

The next line contains a single integer q, denoting the number of queries. Each of the next q lines contains a single integer, where the integer on the ith line denotes the parameters of the ith query ri.

Output Format :

For each query, print the answer on a new line.

Constraints :
1 ≤ N ≤ 10^5
-10^9 ≤ xi, yi ≤ 10^9
1 ≤ q ≤ 10^5
0 ≤ r ≤ 10^18

SAMPLE INPUT
5
1 1
2 2
3 3
-1 -1
4 4
2
3
32*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    long long x, y, r;
    cin >> N;
    vector<double> dist(N);

    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        dist[i] = sqrt((double)x * x + y * y);
    }

    sort(dist.begin(), dist.end());

    int Q;
    cin >> Q;
    while (Q--) {
        cin >> r;

        int idx = upper_bound(dist.begin(), dist.end(), r) - dist.begin();
        cout << idx << endl;
    }
}