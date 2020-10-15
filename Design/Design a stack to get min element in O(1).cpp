/*Implement a stack which supports getMinElement operation to get the min element in O(1). Given the nos will be btw 0 to 1e3*/
/*The idea is to store the min(m) and the element(a) itself in a single number. This can be done by p = a*(n+1) + m */

#include <iostream>
#include <stack>

class DS {
    vector<int> a;
    int mini;
    int N;
public:
    DS(int N) {
        this->N = N;
        a = vector<int> a(N);
        mini = INT_MAX;
    }

    void push(int x) {
        mini = min(mini, x);
        a.push_back(x * N + mini);
    }

    void pop() {
        if (a.size()) a.pop_back();
    }

    int top() {
        if (a.size()) return a[a.size() - 1] / N;
        return INT_MAX;
    }

    int getMin() {
        if (a.size()) return a[a.size() - 1] % N;
    }
}

////////////////////////////////////////////////////////////////
const int N = 1e3 + 1;

int a[N];
int top = -1;
int m = INT_MAX;

void push(int v) {
    m = min(m, v);
    a[++top] = v * N + m;
}

void pop() {
    if (top == -1) return;
    --top;
}

int top() {
    if (top == -1) return;

    return a[top] / N;
}
void getMin() {
    if (top == -1) return;

    return a[top] % N;
}

