/*Given an array of n elements, where each element is at most k away from its target position, devise an algorithm that
sorts in O(n log k) time. */

/*We can sort such arrays more efficiently with the help of Heap data structure. Following is the detailed process that uses Heap.
1) Create a Min Heap of size k+1 with first k+1 elements. This will take O(k) time (See this GFact)
2) One by one remove min element from heap, put it in result array, and add a new element to heap from remaining elements.

Removing an element and adding a new element to min heap will take Logk time. So overall complexity will be O(k) + O((n-k)*logK)
,ie, O(nlogk) */

void sort(vector<int> &a, int k) {
    int n = a.size();
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i <= k; ++i) q.push(a[i]);

    int j = 0;
    for (int i = k + 1; i < n; ++i) {
        a[j++] = q.top(); q.pop();
        q.push(a[i]);
    }

    while (!q.empty()) {
        a[j++] = q.top(); q.pop();
    }
}
