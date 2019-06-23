/*A 1D array maximum sub-array problem.
The solution is Dynamic Programming. This maximum sub-array technique is also known as Kadane’s Algorithm.
C++ implementation: */

#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    long n, e, sum, maxSum;
    while (cin >> n && n) {
        sum = maxSum = 0;
        while (n--) {
            cin >> e;
            sum += e;
            if (sum < 0)
                sum = 0;
            maxSum = max(maxSum, sum);
        }
        if (maxSum > 0)
            cout << "The maximum winning streak is " << maxSum << ".";
        else
            cout << "Losing streak.";
        cout << endl;
    }
    return 0;
}