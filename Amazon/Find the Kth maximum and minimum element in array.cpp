/*Find the Kth max and min element in the array
IDEA: use min heap
for kth max:
1. store first k elements of array in the heap
2. for each of the remaining elements a[i], if it is > than the top of the heap,
    then pop the top of heap and push a[i] to it
3. Finally the top of the heap will contain the Kth max element
*/


int kthMax(vector<int> a, int K) {
    if (K >= a.size()) return -1;
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < K; ++i) q.push(a[i]);

    for (int i = K; i < a.size(); ++i) {
        if (a[i] > q.top()) q.pop(), q.push(a[i]);
    }

    return q.top();
}

////////////////////////////////////////////

int kthMin(vector<int> a, int K) {
    if (K >= a.size()) return -1;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < K; ++i) q.push(a[i]);

    for (int i = K; i < a.size(); ++i) {
        if (a[i] < q.top()) q.pop(), q.push(a[i]);
    }

    return q.top();
}