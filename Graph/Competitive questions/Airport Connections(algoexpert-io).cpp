/*You are given a list of airports (three-letter codes like 'JFK'), a list of routes (one-way flights from one airport to another like ['JFK', 'SFO']), and a starting airport.

Write a function that returns the minimum number of airport connections (one-way flights) that need to be added in order for someone to be able to reach any airport in the list, starting at the starting airport.

Note that the connections don't have to be direct; it's okay if an airport can only be reached from the starting airport by stopping at other airports first.

Sample Input:

[
"BGI",
"CDG",
"DEL",
"DOH",
"DSM",
"EWR",
"EYW",
"HDN",
"ICN",
"JFK",
"LGA",
"LHR",
"ORD",
"SAN",
"SFO",
"SIN",
"TLV",
"BUD,
],
[
["DSM","ORD"],
["ORD","BGI"],
["BGI","LGA"],
["SIN","CDG"],
["CDG","SIN"],
["CDG","BUD"],
["DEL","DOH"],
["DEL","CDG"],
["TLV","DEL"],
["EWR","HND"],
["HND","ICN"],
["HND","JFK"],
["ICN","JFK"],
["JFK","LGA"],
["EYW","LHR"],
["LHR","SFO"],
["SFO","SAN"],
["SFO", "DSM"],
["SAN","EYW"]
],
"LGA"

IDEA:
1. create an adjacency matrix of the graph
2. find all the strongly connected components
3. reduce each component to a single node(each node in a component will have a representative)
4. Now in the modified graph, the ans will be all the nodes having indegree of zero
	because adding an edge from the source to any of these nodes will ensure that we can
	any airport from the starting airport
*/
const int maxn = 1e5;
vector<int> g[maxn], rg[maxn], vis, st, who, indegree;

void dfs(int u) {
	vis[u] = 1;
	for (int v : g[u]) {
		if (!vis[v]) dfs(v);
	}
	st.push_back(u);
}

void dfs2(int u, int rep) {
	vis[u] = 1;
	who[u] = rep;
	for (int v : rg[u]) if (!vis[v]) dfs(v, rep);
}

int solve(vector<string> airports, vector<vector<string>> routes, string startingAirport) {
	int n = routes.size();
	vis.assign(n, 0);
	who.assign(n, -1);

	unordered_map<string, int> mp;
	for (int i = 0; i < n; ++i) mp[airports[i]] = i;

	for (auto v : routes) {
		g[mp[v[0]]].push_back(mp[v[1]]);
		rg[mp[v[1]]].push_back(mp[v[0]]);
	}

	for (int i = 0; i < n; ++i)
		if (!vis[i])
			dfs(i);

	vis.assign(n, 0);

	while (!st.empty()) {
		int u = st.back();
		st.pop_back();
		if (!vis[u]) dfs2(u, u);
	}
	for (int i = st.size() - 1; i >= 0; --i) {
		dfs2(i, i);
	}
	// iterate through each edge (u->v) and if the end nodes of the edge are not in the same
	// group then increment the indegree of v
	for (int u = 0; u < n; ++u) {
		for (int v : g[u]) {
			if (who[u] != who[v]) indegree[who[v]]++;
		}
	}

	int ans = 0;
	// go through all the representatives, and check whose indegree is zero and
	// it should not be the starting airport
	for (int i = 0; i < n; ++i) {
		if (who[i] == i and indegree[i] == 0 and who[i] != mp[startingAirport])
			ans++;
	}

	return ans;
}
