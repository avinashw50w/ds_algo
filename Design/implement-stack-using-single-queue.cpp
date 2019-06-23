/*// x is the element to be pushed and s is stack
push(s, x) 
  1) Let size of q be s. 
  1) Enqueue x to q
  2) One by one Dequeue s items from queue and enqueue them.
  
// Removes an item from stack
pop(s)
  1) Dequeue an item from q */
template<typename T>
class Stack {
	queue<T> q;
public:
	void push(const T&);
	void pop();
	T top() const { return q.front(); }
	bool empty() const { return q.empty(); }
}

void Stack::push(const T& val) {
	int s = q.size();

	q.push(val);

	while(s--) {
		q.push(q.front());
		q.pop();
	}
}

void Stack::pop() {
	if(q.empty()) return;
	q.pop();
}