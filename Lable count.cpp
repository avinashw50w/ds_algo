/*Given a tree with N nodes numbered from 0 to N, each node has a label which is a lowercase
english letter from a to z. Find for each node the no of nodes in its subtree including itself
which have the same label as that of the node.*/

int ans[maxn];
int cnt[26];
int label[maxn];

void dfs(int u, int p = -1) {
    int lc = cnt[label[u] - 'a']++;

    for (int v: G[u]) {
        if (v^p) dfs(v, u);
    }

    ans[u] = cnt[label[u] - 'a'] - lc;
}
