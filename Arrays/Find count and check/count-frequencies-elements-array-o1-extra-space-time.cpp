/*Count frequencies of all elements in array in O(1) extra space and O(n) time
Given an unsorted array of n integers which can contain integers from 1 to n.
Some elements can be repeated multiple times and some other elements can be absent
from the array. Count frequency of all elements that are present and print the
missing elements.

Examples:

Input: arr[] = {2, 3, 3, 2, 5}
Output: Below are frequencies of all elements
        1 -> 0
        2 -> 2
        3 -> 2
        4 -> 0
        5 -> 1

 */

int main() {
    vector<int> a = {2, 3, 2, 2, 3, 4, 3, 4, 4, 4, 5, 5};
    int n = a.size(), K = n + 1;

    for (int i = 0; i < n; ++i) {
        a[(a[i] - 1) % K] += K;
    }

    for (int i = 0; i < n; ++i) {
        cout << (i + 1) << " -> " << (a[i] / K) << "\n";
        a[i] %= K;
    }
}

/*output: 0 0 3 3 4 2 0 0 0 0 0 0
*/

// if the array contains n integers ranging from 0 to n-1, then we have
// to handle zeroes separately

int zeroes = 0;
for (int i = 0; i < n; ++i) {
    if (a[i] == 0) zeroes++;
    int x = a[i] % n;
    else a[x] += n;
}
cout << "0 -> " << zeroes << "\n";

for (int i = 1; i < n; ++i) {
    cout << i << " -> " << (a[i] / n) << "\n";
    a[i] %= n;
}
