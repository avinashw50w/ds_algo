/*Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n.
 Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if length of the rod is 8 and the 
 values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)

length   | 1   2   3   4   5   6   7   8   9   10 
-------------------------------------------------               //  here every possible length has a cost attached to it  // 
price    | 1   5   8   9  10  17  17  20   24  30

*/
#include <iostream>
#include <cstring>
using namespace std;
 
const int N = 1000;
int p[11];
int r[N], s[N];
 
// initializer for prieces and optimal solutions
void init() {
    memset(r, -1, N);
    r[0] = 0;
    p[]={0,1,5,8,9,10,17,20,24,30};
}
 
// naieve exponential solution
int cutRod(int n) {
    int q = 0;
    for (int i = 1; i <= n; ++i)
        q = max(q, p[i] + cutRod(n - i));
    return q;
}
 
// top-down solution
int topDownCutRod(int n) {
    if (r[n] != -1)
        return r[n];
    int q = 0;
    for (int i = 1; i <= n; ++i)
        q = max(q, p[i] + topDownCutRod(n - i));
    return r[n] = q;
}
 
// bottom-up solution
int buttomUpCutRod(int n) {
    
    for (int i = 1; i <= n; ++i) {
        int q = 0;
        for (int j = 1; j <= i; ++j)
            q = max(q, p[j] + r[i - j]);
        r[i] = q;
    }
    return r[n];
}
 
// bottom-up solution that maintains not only the best price but also the "required cut" for such solution
int extendedButtomUpCutRod(int n) {
    if (r[n] != -1)
        return r[n];
    for (int i = 1; i <= n; ++i) {
        int q = 0;
        for (int j = 1; j <= i; ++j)
            if (q < p[j] + r[i - j]) {
                q = p[j] + r[i - j];
                s[i] = j;
            }
        r[i] = q;
    }
    return r[n];
}
 
// prins the extended method's output
void printCutRodSoln(int n) {
    do
        cout << s[n] << " ";
    while ((n -= s[n]) > 0);
}
 
int main() {
    init();
    int n;
    cin >> n;
    cout << extendedButtomUpCutRod(n) << endl;
    printCutRodSoln(n);
    return 0;
}