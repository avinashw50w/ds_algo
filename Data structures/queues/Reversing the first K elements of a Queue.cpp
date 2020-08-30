/*Reversing the first K elements of a Queue
The idea is to use an auxiliary stack.

Create an empty stack.
One by one dequeue items from given queue and push the dequeued items to stack.
Enqueue the contents of stack at the back of the queue
Dequeue (size-k) elements from the front and enque them one by one to the same queue.*/

void solve(queue<int> &q, int k) {
	stack<int> s;
	int n = q.size();

	for (int i = 0; i < k; ++i) s.push(q.front()), q.pop();
	while (!s.empty()) q.push(s.top()), s.pop();
	for (int i = 0; i < n - k; ++i) q.push(q.front()), q.pop();
}