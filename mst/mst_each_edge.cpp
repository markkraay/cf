#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>

using namespace std;
using ll = long long;

class DisjointSet { 
private:
	std::vector<int> parent;
	std::vector<int> height;
public: 
	DisjointSet(int size) {
		parent.resize(size);
		height.resize(size);
		for (int i = 0; i < size; i++) {
			parent[i] = i;
			height[i] = 1;
		}
	}

	int find(int x) {
		return x == parent[x] ? x : parent[x] = find(parent[x]);
	}

	void unionSets(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (height[x] > height[y]) swap(x, y); // Parent should have the larger height
		parent[y] = x;
		height[x] += height[y];
	}
};

struct EdgeWeight {
	int node;
	int weight;
};
using AdjMatrix = vector<vector<EdgeWeight>>;

const int mxN = 2e5+5;
const int mxL = 30;
int level[mxN];
int lca[mxN][mxL], heavy[mxN][mxL];

void dfs(int node, int weight, int parent, int l, AdjMatrix& adj) {
	lca[node][0] = parent;
	heavy[node][0] = weight;
	level[node] = l;
	for (EdgeWeight e : adj[node]) {
		if (e.node == parent) continue;
		dfs(e.node, e.weight, node, l + 1, adj);
	}
}

// Get the maximum weight of the LCA
int LCA(int a, int b) {
	int result = 0;
	if (level[a] < level[b]) swap(a, b);
	int depth = level[a] - level[b];
	for (int i = mxL; i >= 0; i--) { 
		if (depth & (1 << i)) {
			result = max(result, heavy[a][i]);
			a = lca[a][i];
		}
	}
	if (a == b) return result;
	for (int i = mxL-1; i >= 0; i--) {
		if (lca[a][i] != lca[b][i]) {
			result = max({result, heavy[a][i], heavy[b][i]});
			a = lca[a][i];
			b = lca[b][i];
		}
	}
	return max({result, heavy[a][0], heavy[b][0]});
}

void mst_each_edge(int V, int E, vector<vector<int>>&& edges) {
	sort(edges.begin(), edges.end(), [](const auto& v1, const auto& v2) {
		return v1[2] < v2[2];
	});
	unordered_set<int> in_mst;
	AdjMatrix adj(V+1, vector<EdgeWeight>());
	DisjointSet ds(V+1);
	ll cost = 0;
	// Generate the MST
	for (int i = 0; i < E; i++) {
		if (ds.find(edges[i][0]) != ds.find(edges[i][1])) {
			ds.unionSets(edges[i][0], edges[i][1]);
			cost += (ll)edges[i][2];
			in_mst.insert(edges[i][3]);
			adj[edges[i][0]].push_back(EdgeWeight{edges[i][1], edges[i][2]});
			adj[edges[i][1]].push_back(EdgeWeight{edges[i][0], edges[i][2]});
		}
	}
	// Precompute binary lifting
	dfs(1, 0, 0, 0, adj);
	for (int j = 1; j < mxL; j++) {
		for (int i = 1; i <= V; i++) {
			lca[i][j] = lca[ lca[i][j-1] ][j-1]; 
			heavy[i][j] = max(heavy[i][j-1], heavy[ lca[i][j-1] ][j-1]); 
		}
	}
	vector<ll> result(E);
	for (int i = 0; i < E; i++) {
		if (in_mst.contains(edges[i][3])) result[edges[i][3]] = cost;
		else result[edges[i][3]] = cost - LCA(edges[i][0], edges[i][1]) + edges[i][2];
	}
	for (ll i : result) cout << i << endl;
}

void test() {
	mst_each_edge(5, 7, {
		{1, 2, 3, 0},
		{1, 3, 1, 1},
		{1, 4, 5, 2},
		{2, 3, 2, 3},
		{2, 5, 3, 4},
		{3, 4, 2, 5},
		{4, 5, 4, 6}
	});
}

int main() {
	test();
	// int n, m, e1, e2, w;
	// cin >> n >> m;
	// vector<int> result(m);
	// vector<vector<int>> edges;
	// DisjointSet ds(n);
	// for (int i = 0; i < m; i++) {
	// 	cin >> e1 >> e2 >> w;
	// 	edges.push_back(vector<int>{e1, e2, w, i});
	// }
	// mst_each_edge(n, m, move(edges));
}