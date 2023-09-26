#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

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

// Find all the MSTs
void solve(int V, vector<vector<int>>&& edges, vector<vector<int>> const&& queries) {
	vector<vector<int>> weight(V+1, vector<int>(V+1));
	DisjointSet ds(V+1);
	vector<int> edge_weights(edges.size());
	sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
		return a[2] < b[0];
	});
	for (int i = 0; i < edges.size(); i++) {
		edge_weights[i] = edges[i][2];
		if (ds.find(edges[i][0]) != ds.find(edges[i][1])) {
			ds.unionSets(edges[i][0], edges[i][1]);
			edge_weights[edges[i][2]]++;
		}
	}
	for (const auto& q : queries) {
		unordered_map<int, int> cnts;
		bool valid = true;
		for (int edge : q) {
			if (!cnts.contains(edge)) cnts[edge] = edge_weights[edge];
			cnts[edge]--;
			if (cnts[edge] < 0) {
				valid = false;
				break;
			}
		}
		cout << (valid ? "YES" : "NO") << endl;
	}
}


// Since MST's are created from the smallest edge weights, if an MST contains edges with weight X, 
// it must also contain all edges with weights less than X (as long as the edges with lesser weights don't form cycles).

// For each query, we group the edges in the query by the weights. 
// For each edge group, if the edges in that group form a cycle with all other edges with lesser weights, 
// then the answer to the corresponding query is no, because MST's don't have cycles. If none of the edge groups form cycles, then the answer to the query is yes.

// To do this efficiently, we have to sort the edge groups by weight and process the edge groups starting from the lower ones, 
// while maintaining disjoint sets for nodes connected by edges with lower weights. For each edge group, we can just add the edges to the disjoint sets (union) to test for cycles.

// However, for the same weight, there might be multiple edge groups, and after testing if an edge group forms a cycle, 
// we need to remove those edges to test the next edge group. I used persistent disjoint sets to account for this.

// Find the MST and the min cost
// Rem
void test() {
	vector<vector<int>> edges = {
		{1,2,2},
		{1,3,1},
		{2,3,1},
		{2,4,1},
		{3,4,1},
		{3,5,2},
		{4,5,2}
	};
	vector<vector<int>> queries = {
		{3,4}, {3,4,5}, {1,7}, {1,2}
	};
	solve(5, move(edges), move(queries));
}

int main() {
	test();
	// int V, E, u, v, w;
	// cin >> V >> E;
	// vector<vector<int>> edges;
	// for (int i = 0; i < E; i++) {
	// 	cin >> u >> v >> w;
	// 	edges.push_back({u, v, w});
	// }
	// sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) { 
	// 	return a[2] < b[2]; 
	// });
	// vector<vector<int>> msts;
	// vector<int> indices;
	// find_all_msts(0, indices, DisjointSet(V+1), edges, V, msts);
	// // Must Generate each MST
	// // Sort vertices
	// // For each vertex, insert into MST, in DFS style
	// // Return the MST edges in a vector<vector<int>> 
	// // For each query, 

	// int q, k;
	// cin >> q;
	// vector<vector<int>> queries(q);
	// for (int i = 0; i < q; i++) {
	// 	cin >> k;
	// 	queries.push_back(vector<int>(k));
	// 	for (int j = 0; j < k; j++) {
	// 		cin >> queries[i][j];
	// 	}
	// }
}