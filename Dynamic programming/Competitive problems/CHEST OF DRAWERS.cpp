/*A Dynamic Programming combinatorics problem.
You start placing the drawers one by one and each time you decide between locked and unlocked. During this process, keep track of the 
number of drawers placed so far and the number of secure ones. If both reach your target, count that as one solution. The DP solution:

State S(n, s, l) – n is number of drawers waiting to be placed, s number of secured drawers required and l whether the previous drawer is locked.

Transition S(n, s, l) = S(n - 1, s - l, true) + S(n - 1, s, false) – You can place a locked drawer which decreases the number of 
required secured drawers, if and only if the previous drawer is locked. Placing an unlocked drawer only decreases the number of 
remaining drawers.
Caution!

long long isn’t enough!
C++ top-down implementation:  */

#include <iostream>
#include <cstring>
using namespace std;
 
#define N 128
 
unsigned long long nWays[N][N][2];
 
unsigned long long getNWays(int n, int s, bool l) {
    if (n == 0 && s == 0)
        return nWays[n][s][l] = 1;
    if (s > n || n < 0 || s < 0)
        return 0;
    if (nWays[n][s][l] != -1)
        return nWays[n][s][l];
    return nWays[n][s][l] = getNWays(n - 1, s - l, true) + getNWays(n - 1, s, false);
}
 
int main() {
    memset(nWays, -1, sizeof nWays);
    int n, s;
    while (cin >> n >> s && n >= 0 && s >= 0)
        cout << getNWays(n, s, true) << endl;
    return 0;
}