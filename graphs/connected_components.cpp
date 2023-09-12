#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

int main() {
	int V, remove_E, v1, v2;
	cin >> V >> remove_E;
	unordered_map<int, unordered_set<int>> edges; // Edges that we cannot include
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
	unordered_set<int> visited;
	vector<int> result;
	for (int i = 0; i < V; i++) {
		if (visited.find(i) == visited.end()) {
			queue<int> q;
			q.push(i);
			int size = 0;
			while (!q.empty()) {
				auto top = q.front(); q.pop();
				if (visited.find(top) != visited.end()) continue;
				size++;
				visited.insert(top);
				for (int i = 0; i < V; i++) {
					if (i != top && edges[top].find(i) == edges[top].end() && visited.find(i) == visited.end()) {
						q.push(i);
					}
				}
			}
			result.push_back(size);
		}
	}
	cout << result.size() << endl;
	sort(result.begin(), result.end());
	for (int i : result) cout << i << " ";
}