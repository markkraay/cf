#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>

using namespace std;

struct Edge {
	int from;
	int to;
};

int solution(int V, vector<Edge> const&& edges) {
	vector<unordered_set<int>> g(V+1);
	for (auto e : edges) {
		g[e.from].insert(e.to);
		g[e.to].insert(e.from);
	}
	unordered_set<int> not_visited;
	for (int i = 1; i <= V; i++) not_visited.insert(i);
	int cnt = 0;
	queue<int> q;
	while (!not_visited.empty()) {
		int size = 0;
		int begin = *not_visited.begin();
		not_visited.erase(begin);
		q.push(begin);
		while (!q.empty()) {
			int current = q.front(); q.pop();
			size++;
			for (auto it = g[current].begin(); it != g[current].end();) {
				if (not_visited.contains(*it)) {
					q.push(*it);
					not_visited.erase(*it);
					it = g[current].erase(it);
				} else ++it;
			}
		}
		cnt += (size - 1);
	}
	return edges.size() - cnt;
}

void test() {
	cout << solution(5, {
		Edge{1,2}, Edge{4,3}, Edge{1,4}, Edge{3,4}
	});
	cout << solution(6, {
		{2,3}, {2,1}, {3,4}, {6,5}, {4,5}
	});
}

int main() {
	int n, k, a, b;
	cin >> n >> k;
	vector<Edge> edges(k);
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		edges[i] = Edge{a, b};
	}
	cout << solution(n, move(edges)) << endl;
}