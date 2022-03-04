/*There is tree of N ( 0< N <=10^5) vertices and E edges (0< E <10^5) . You have been given q 
queries and in each query, you have given two vertices and you have to remove the edge between 
these two vertices and give the largest size of the tree from the resultant forest.

Use DSU offline queries.
- Union all the edges which are not part of the query
- also keep track of the size of each tree
- Process queries in reverse, for each query (u, v), union the trees having u and v*/

class DSU {
    vector<int> par, sz;
    multiset<int> st;
    
    DSU(int N) {
        par.assign(N);
        sz.assign(N);
        for (int i = 0; i < N; ++i) par[i] = i;
        st.insert(1);
    }

    int root(int v) {
        return (v == par[v]) ? v : par[v] = root(par[v]);
    }

    void merge(int u, int v) {
        int x = root(u);
        int y = root(v);
        if (sz[x] < sz[y]) swap(x, y);
        st.erase(sz[x]);
        st.erase(sz[y]);
        st.insert(sz[x] + sz[y]);
        par[y] = x;
        sz[x] += sz[y];

    }
};

vector<int> solve(vector<vector<int>> edges, vector<vector<int>> queries) {
    int n = adj.size();

    set<vector<int>> st;
    for (auto q: queries) {
        st.insert(q);
    }

    DSU dsu(n);

    for (auto e: edges) {
        if (st.count(e) == 0) dsu.merge(e[0], e[1]);
    }

    vector<int> ans;
    for (int i = queries.size() - 1; i >= 0; --i) {
        ans.push_back(*dsu.st.rbegin());
        dsu.merge(queries[0], queries[1]);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}