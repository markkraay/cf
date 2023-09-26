#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;
using Graph = unordered_map<int, unordered_set<int>>;

int main() {
	int V, remove_E, v1, v2;
	cin >> V >> remove_E;
	Graph edges; // Edges that we cannot include
	for (int i = 0; i < remove_E; i++) {
		cin >> v1 >> v2;
		v1--;
		v2--;
		if (edges.find(v1) == edges.end()) {
			edges.insert(make_pair(v1, unordered_set<int>()));
		}
		edges[v1].insert(v2);
		if (edges.find(v2) == edges.end()) {
			edges.insert(make_pair(v2, unordered_set<int>()));
		}
		edges[v2].insert(v1);
	}
	unordered_set<int> not_visited;
	for (int i = 0; i < V; i++) not_visited.insert(i);
	vector<int> result;
	queue<int> q;
	while (!not_visited.empty()) {
		int node = *not_visited.begin();
		not_visited.erase(node);
		q.push(node);
		int size = 1;
		while (!q.empty()) {
			int current = q.front(); q.pop();
			for (auto it = not_visited.begin(); it != not_visited.end();) {
				if (!edges[current].contains(*it)) {
					size++;
					q.push(*it);
					it = not_visited.erase(it);
				} else ++it;
			}
		}
		result.push_back(size);
	}
	cout << result.size() << endl;
	sort(result.begin(), result.end());
	for (int i : result) cout << i << " ";
}