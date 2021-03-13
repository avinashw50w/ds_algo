void sortStack(stack<int> st) {
	if (st.size()) {
		int top = st.top(); st.pop();
		sortStack(st);
		sortedInsert(st, top);
	}
}

void sortedInsert(stack<int> st, int ele) {
	if (st.empty() or st.top() < ele) st.push(ele);
	else {
		int top = st.top();
		sortedInsert(st, ele);
		st.push(top);
	}
}

////////////////////////////////////////////////////////////////
// pseudo code
sortStack(stack S)
	if stack is not empty:
		temp = pop(S);  
		sortStack(S); 
		sortedInsert(S, temp);
Below algorithm is to insert element is sorted order:

sortedInsert(Stack S, element)
	if stack is empty OR element > top element
		push(S, elem)
	else
		temp = pop(S)
		sortedInsert(S, element)
		push(S, temp)