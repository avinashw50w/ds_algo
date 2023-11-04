/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.*/

class MinStack {
public:
    vector<pair<int, int>> a;

    void push(int x) {
        a.push_back({x, min(x, getMin())});
    }

    void pop() {
        a.pop_back();
    }

    int top() {
        return a.empty() ? INT_MAX : a.back().first;
    }

    int getMin() {
        return a.empty() ? INT_MAX : a.back().second;
    }

    void print() {
        for (auto e : a) cout << "{" << e.first << " " << e.second << "},"; cout << endl;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */