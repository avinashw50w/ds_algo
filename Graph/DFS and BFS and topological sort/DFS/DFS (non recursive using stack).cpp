#include <bits/stdc++.h>
using namespace std;

class Graph {
	int N;
	vector<int> *G;
	int *vis;

public:
	Graph(int N) {
		this->N = N;
		G = new vector<int>[N];
		vis = new int[N]();
	}

	void dfs(int u) {
		stack<int> st;
		st.push(u);

		while(!st.empty()) {
			u = st.top();
			st.pop();

			if (vis[u]) continue;
			vis[u] = 1;

			for (int v: G[u]) {
				if (!vis[v]) {
					st.push(v);
				}
			}
		}
	}
};

int main() {

}